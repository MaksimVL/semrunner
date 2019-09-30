#include "libft.h"
#include "double.h"
#include "ft_printf.h"

int		len_num_box(unsigned long long num, int shift)
{
	int 	count;

	count = 0;
	while(num > 0)
	{
		num = (num >> shift);
		count++;
	}
	return (count);
}

int 	len_num_d(long long int num)
{
	int count;

	count = (num < 0) ? 1 : 0;

	while(num != 0)
	{
		num = num / 10;
		count++;
	}
	return (count);
}

int		len_num_u(unsigned long long int num)
{
	int count;

	count = 0;
	while(num != 0)
	{
		num = num / 10;
		count++;
	}
	return (count);
}

int		ft_itoa_d(long long int num, t_printf *p)
{
	char 	n[30];
	int 	i;
	int		sign;

	n[29] = '\0';
	if (num == 0)
	{
		ft_putchar_fd('0', p->fd);
		return (1);
	}
	i = 28;
	sign = (num < 0) ? 1 : 0;
	if (num < 0)
	{
		n[i--] = (char)(-(num % 10) + 48);
		num = -(num / 10);
	}
	while(num != 0)
	{
		n[i--] = (char)(num % 10 + 48);
		num = num / 10;
	}
	if (sign == 1)
		n[i] = '-';
	else
		i++;
	ft_putstr_fd(&n[i], p->fd);
	return  (1);
}

int		ft_itoa_u(long long int num, t_printf *p)
{
	char 	n[30];
	int 	i;

	n[29] = '\0';
	if (num == 0)
	{
		ft_putchar_fd('0', p->fd);
		return (1);
	}
	i = 28;
	while(num != 0)
	{
		n[i--] = (char)(num % 10 + 48);
		num = num / 10;
	}
	ft_putstr_fd(&n[++i], p->fd);
	return (1);
}

int		ft_itoa_box(unsigned long long num, t_printf *p)
{
	char *base_chars;
	int shift;
	int mask;
	int start_point;

	if (num == 0)
	{
		ft_strcat(p->buff, "0");
		return (1);
	}

	base_chars = (*p->str == 'x' || *p->str == 'p') ? "0123456789abcdef" : "0123456789ABCDEF";
	if (*p->str == 'b')
	{
		mask = 1;
		shift = 1;
	}
	else if (*p->str == 'o')
	{
		mask = 7;
		shift = 3;
	}
	else
	{
		mask = 15;
		shift = 4;
	}
	if (!(start_point = len_num_box(num, shift)))
		return (0);

	while(start_point-- > 0)
		*(p->output++) = base_chars[(num >> (start_point * shift)) & mask];
	*p->output = '\0';
	return (1);
}

int		parse_csp(t_printf *p)
{
	if (*p->str == 'c')
		ft_putchar(va_arg(p->arg, int));
	else if (*p->str == 's')
		ft_putstr(va_arg(p->arg, char*));
	else if (*p->str == 'p')
	{
		p->flags |= F_OCTO;
		ft_itoa_box((unsigned long long) va_arg(p->arg, void*), p);
	}
	return (1);
}

int		parse_boxudf(t_printf *p)
{
	union u_double d;

	if (*p->str == 'x' || *p->str == 'X' || *p->str == 'o' || *p->str == 'b')
		ft_itoa_box((unsigned int)va_arg(p->arg,unsigned int), p);
	else if (*p->str == 'd' || *p->str =='i')
		ft_itoa_d(va_arg(p->arg, int), p);
	else if (*p->str == 'u')
		ft_itoa_u(va_arg(p->arg, unsigned int), p);
	else if (*p->str == 'f')
	{
		d.ld = va_arg(p->arg, double);
		ft_itoa_f1(d, p, 10);
	}
	return (1);
}

int		parse_lboxudf(t_printf *p)
{
	union u_double d;

	if (*p->str == 'x' || *p->str == 'X' || *p->str == 'o' || *p->str == 'b')
		ft_itoa_box((unsigned long int)va_arg(p->arg,unsigned long int), p);
	else if (*p->str == 'd' || *p->str =='i')
		ft_itoa_d(va_arg(p->arg, long int), p);
	else if (*p->str == 'u')
		ft_itoa_d(va_arg(p->arg, unsigned long int), p);
	else if (*p->str == 'f')
	{
		d.ld = va_arg(p->arg, double);
		ft_itoa_f1(d, p, 10);
	}
	return (1);
}

int		parse_llboxudf(t_printf *p)
{
	union u_double d;

	if (*p->str == 'x' || *p->str == 'X' || *p->str == 'o' || *p->str == 'b')
			ft_itoa_box((unsigned long long int)va_arg(p->arg,unsigned long long int), p);
		else if (*p->str == 'd' || *p->str =='i')
			ft_itoa_d(va_arg(p->arg, long long int), p);
		else if (*p->str == 'u')
			ft_itoa_d(va_arg(p->arg, unsigned long long int), p);
		else if (*p->str == 'f')
		{
		d.ld = va_arg(p->arg, long double);
		ft_itoa_f1(d, p, 10);
	}
	return (1);
}

int 	ft_itoa_f1(union u_double d, t_printf *p, int prec)
{
	int 				exp;
	int 				pow;
	unsigned long int	mant;
	t_bigdec			bd;

	if (check_specvalues(d, p->output))
		return (1);
	else
	{
		pow = 0;
		exp = (d.s_parts.e == 0) ? 0 : d.s_parts.e - 16382;
		if (exp > 0 && exp < 65)
			mant = d.s_parts.m >> (64 - exp);
		else
		{
			pow = (exp <= 0) ? -exp + 1 : exp - 64;
			mant = d.s_parts.m;
		}
		initialize_bd(&bd);
		bd.sign = d.s_parts.s == 1 ? -1 : 1;
		ft_intpart(pow, mant, exp, &bd);
		if (prec != 0 && exp <= 65)
		{

			ft_fractpart(pow, exp <= 0 ? d.s_parts.m : d.s_parts.m << exp, p->output, &bd);
			roundbd(&bd, prec);
		}
		put_bd_output(bd, p->output, prec);
	}
}

int		parse_hboxud(t_printf *p)
{
	if (*p->str == 'x' || *p->str == 'X' || *p->str == 'o' || *p->str == 'b')
		ft_itoa_box((unsigned short)va_arg(p->arg,unsigned int), p);
	else if (*p->str == 'd' || *p->str =='i')
		ft_itoa_d((short)va_arg(p->arg, int), p);
	else if (*p->str == 'u')
		ft_itoa_u((unsigned short)va_arg(p->arg, unsigned int), p);
	return (1);
}

int		parse_hhboxud(t_printf *p)
{
	if (*p->str == 'x' || *p->str == 'X' || *p->str == 'o' || *p->str == 'b')
		ft_itoa_box((unsigned char)va_arg(p->arg,unsigned int), p);
	else if (*p->str == 'd' || *p->str =='i')
		ft_itoa_d((char)va_arg(p->arg, int), p);
	else if (*p->str == 'u')
		ft_itoa_u((unsigned char)va_arg(p->arg, unsigned int), p);
	return (1);
}

int		parseflags(t_printf *p)
{
	if (p == '\0')
		return (0);
	if (*p->str == '+' || *p->str == '-' || *p->str == ' ' || *p->str == '0' || *p->str == '#')
	{
		if (*p->str == '+')
			p->flags |= F_PLUS;
		if (*p->str == '-')
			p->flags |= F_MINUS;
		if (*p->str == ' ')
			p->flags |= F_SPACE;
		if (*p->str == '0')
			p->flags |= F_ZERO;
		if (*p->str == '#')
			p->flags |= F_OCTO;
		p->str++;
		return (parseflags(p));
	}
	return (1);
}

int		parsewidth(t_printf *p)
{
	if (*p->str == '*')
	{
		p->width = va_arg(p->arg,int);
		*p->str++;
	}
	else
		while ('0' <= *p->str && *p->str <= '9')
		{
			p->width = p->width * 10 + (*p->str - '0');
			p->str++;
		}
	if (*p->str == '\0')
		return (0);
}

int		parseprec(t_printf *p)
{
	if (*p->str == '\0')
		return (0);
	if (*p->str != '.')
		return (1);
	p->str++;
	if (*p->str == '*')
	{
		p->prec = va_arg(p->arg, int);
		p->str++;
	}
	else
	{
		p->prec = 0;
		while ('0' <= *p->str && *p->str <= '9')
		{
			p->prec = p->prec * 10 + (*p->str - '0');
			p->str++;
		}
	}
	if (*p->str == '\0')
		return (0);
}

int		parse(t_printf *p)
{
	if (parseflags(p) == 0)
		return (0);
	if (parsewidth(p) == 0)
		return (0);
	if (parseprec(p) == 0)
		return (0);
	if (*p->str == 'c' || *p->str == 's' || *p->str == 'p')
		parse_csp(p);
	else if (*p->str == 'x' || *p->str == 'X' || *p->str == 'o' || *p->str == 'b'||
			*p->str =='d' || *p->str =='i' || *p->str == 'u' || *p->str == 'f')
		parse_boxudf(p);
	else if (*p->str == 'L')
	{
		p->str++;
		if (*p->str == '\0')
			return (0);
		else if (*p->str == 'f')
			parse_llboxudf(p);
	}

	else if (*p->str == 'l')
	{
		p->str++;
		if (*p->str == '\0')
			return (0);
		else if (*p->str == 'x' || *p->str == 'X' || *p->str == 'o' || *p->str == 'b'||
				 *p->str =='d' || *p->str =='i' || *p->str == 'u'|| *p->str == 'f')
			parse_lboxudf(p);
		else if (*p->str == 'l')
		{
			*p->str++;
			if (*p->str == '\0')
				return (0);
			else if (*p->str == 'x' || *p->str == 'X' || *p->str == 'o' || *p->str == 'b'||
					 *p->str =='d' || *p->str =='i' || *p->str == 'u')
				parse_llboxudf(p);
		}
	}
	else if (*p->str == 'h')
	{
		p->str++;
		if (*p->str == '\0')
			return (0);
		else if (*p->str == 'x' || *p->str == 'X' || *p->str == 'o' || *p->str == 'b'||
				 *p->str =='d' || *p->str =='i' || *p->str == 'u')
			parse_hboxud(p);
		else if (*p->str == 'h')
		{
			p->str++;
			if (*p->str == '\0')
				return (0);
			else if (*p->str == 'x' || *p->str == 'X' || *p->str == 'o' || *p->str == 'b' ||
					 *p->str == 'd' || *p->str == 'i' || *p->str == 'u')
				parse_hhboxud(p);
		}
	}

	return (1);
}

void	initialize_printf(t_printf *p, const char *format, int fd)
{
	p->buff[0] = '\0';
	p->str = (char*)format;
	p->flags = 0;
	p->fd = fd;
	p->width = 0;
	p->prec = -1;
	p->output = (p->buff);
}

void 	mainparse(t_printf *p)
{
	while (*p->str)
	{
		if (*p->str != '%')
			ft_putchar_fd(*p->str, p->fd);
		else
		{
			p->str++;
			if (p->str == '\0')
				return ;
			else
			{
				if (parse(p) == 0)
					return ;
			}
		}
		p->str++;
	}
}

int 	ft_printf(const char *format, ...)
{
	t_printf	p;

	initialize_printf(&p, format, 1);
	va_start(p.arg, format);
	mainparse(&p);
	va_end(p.arg);
	return (0);
}