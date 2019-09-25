#include <stdio.h>
#include "libft.h"
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

int		ft_itoa_d(long long int num, int fd)
{
	char 	n[30];
	int 	i;
	int		sign;

	n[29] = '\0';
	if (num == 0)
	{
		ft_putchar_fd('0', fd);
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
	ft_putstr(&n[i]);
}

int		ft_itoa_u(long long int num, int fd)
{
	char 	n[30];
	int 	i;

	n[29] = '\0';
	if (num == 0)
	{
		ft_putchar_fd('0', fd);
		return (1);
	}
	i = 28;
	while(num != 0)
	{
		n[i--] = (char)(num % 10 + 48);
		num = num / 10;
	}
	ft_putstr(&n[++i]);
	return (1);
}

int		ft_itoa_box(unsigned long long num, char box, int fd)
{
	char *base_chars;
	int shift;
	int mask;
	int start_point;

	if (num == 0)
	{
		ft_putchar_fd('0', fd);
		return (1);
	}

	base_chars = (box == 'x') ? "0123456789abcdef" : "0123456789ABCDEF";
	if (box == 'b')
	{
		mask = 1;
		shift = 1;
	}
	else if (box == 'o')
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
	{
		ft_putchar_fd(base_chars[(num >> (start_point * shift)) & mask], fd);
	}
	return (1);
}

int		parse_csp(const char *ptr, t_param *p, int fd)
{
	if (*ptr == 'c')
		ft_putchar(va_arg(p->arg, int));
	else if (*ptr == 's')
		ft_putstr(va_arg(p->arg, char*));
	else if (*ptr == 'p')
	{
		ft_putstr("0x");
		ft_itoa_box((unsigned long long) va_arg(p->arg, void*), 'x', fd);
	}
	return (1);
}

int		parse_boxud(const char *ptr, t_param *p, int fd)
{
	if (*ptr == 'x' || *ptr == 'X' || *ptr == 'o' || *ptr == 'b')
		ft_itoa_box((unsigned int)va_arg(p->arg,unsigned int), *ptr, fd);
	else if (*ptr == 'd' || *ptr =='i')
		ft_itoa_d(va_arg(p->arg, int), fd);
	else if (*ptr == 'u')
		ft_itoa_u(va_arg(p->arg, unsigned int), fd);
	return (1);
}

int		parse_lboxud(const char *ptr, t_param *p, int fd)
{
	if (*ptr == 'x' || *ptr == 'X' || *ptr == 'o' || *ptr == 'b')
		ft_itoa_box((unsigned long int)va_arg(p->arg,unsigned long int), *ptr, fd);
	else if (*ptr == 'd' || *ptr =='i')
		ft_itoa_d(va_arg(p->arg, long int), fd);
	else if (*ptr == 'u')
		ft_itoa_d(va_arg(p->arg, unsigned long int), fd);
	return (1);
}

int		parse_llboxud(const char *ptr, t_param *p, int fd)
{
	if (*ptr == 'x' || *ptr == 'X' || *ptr == 'o' || *ptr == 'b')
		ft_itoa_box((unsigned long long int)va_arg(p->arg,unsigned long long int), *ptr, fd);
	else if (*ptr == 'd' || *ptr =='i')
		ft_itoa_d(va_arg(p->arg, long long int), fd);
	else if (*ptr == 'u')
		ft_itoa_d(va_arg(p->arg, unsigned long long int), fd);
	return (1);
}

int		parse_hboxud(const char *ptr, t_param *p, int fd)
{
	if (*ptr == 'x' || *ptr == 'X' || *ptr == 'o' || *ptr == 'b')
		ft_itoa_box((unsigned short)va_arg(p->arg,unsigned int), *ptr, fd);
	else if (*ptr == 'd' || *ptr =='i')
		ft_itoa_d((short)va_arg(p->arg, int), fd);
	else if (*ptr == 'u')
		ft_itoa_u((unsigned short)va_arg(p->arg, unsigned int), fd);
	return (1);
}

int		parse_hhboxud(const char *ptr, t_param *p, int fd)
{
	if (*ptr == 'x' || *ptr == 'X' || *ptr == 'o' || *ptr == 'b')
		ft_itoa_box((unsigned char)va_arg(p->arg,unsigned int), *ptr, fd);
	else if (*ptr == 'd' || *ptr =='i')
		ft_itoa_d((char)va_arg(p->arg, int), fd);
	else if (*ptr == 'u')
		ft_itoa_u((unsigned char)va_arg(p->arg, unsigned int), fd);
	return (1);
}

int		parse(char **ptr, t_param *p, int fd)
{
	if (**ptr == 'c' || **ptr == 's' || **ptr == 'p')
		parse_csp(*ptr, p, fd);
	else if (**ptr == 'x' || **ptr == 'X' || **ptr == 'o' || **ptr == 'b'||
			**ptr =='d' || **ptr =='i' || **ptr == 'u')
		parse_boxud(*ptr, p, fd);
	else if (**ptr == 'l')
	{
		(*ptr)++;
		if (**ptr == '\0')
			return (0);
		else if (**ptr == 'x' || **ptr == 'X' || **ptr == 'o' || **ptr == 'b'||
				 **ptr =='d' || **ptr =='i' || **ptr == 'u')
			parse_lboxud(*ptr, p, fd);
		else if (**ptr == 'l')
		{
			(*ptr)++;
			if (**ptr == '\0')
				return (0);
			else if (**ptr == 'x' || **ptr == 'X' || **ptr == 'o' || **ptr == 'b'||
					 **ptr =='d' || **ptr =='i' || **ptr == 'u')
				parse_llboxud(*ptr, p, fd);
		}
	}
	else if (**ptr == 'h')
	{
		(*ptr)++;
		if (**ptr == '\0')
			return (0);
		else if (**ptr == 'x' || **ptr == 'X' || **ptr == 'o' || **ptr == 'b'||
				 **ptr =='d' || **ptr =='i' || **ptr == 'u')
			parse_hboxud(*ptr, p, fd);
		else if (**ptr == 'h')
		{
			(*ptr)++;
			if (**ptr == '\0')
				return (0);
			else if (**ptr == 'x' || **ptr == 'X' || **ptr == 'o' || **ptr == 'b' ||
					 **ptr == 'd' || **ptr == 'i' || **ptr == 'u')
				parse_hhboxud(*ptr, p, fd);
		}
	}
	return (1);
}

int 	ft_printf(const char *format, ...)
{
	t_param		par;
	char		*ptr;
	char 		tmp_char;
	char 		*tmp_str;


	va_start(par.arg, format);
	ptr = (char*)format;
	while(*ptr)
	{
		if (*ptr != '%')
			ft_putchar(*ptr);
		else
		{
			ptr++;
			if (ptr == '\0')
				return (0);
			else
				if (parse(&ptr, &par, 1) == 0)
					return (0);
		}
		ptr++;
	}
	va_end(par.arg);
	return (0);
}