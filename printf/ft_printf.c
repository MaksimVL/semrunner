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

int		ft_itoa_box(unsigned long long num, char box, int fd)
{
	char *base_chars;
	int shift;
	int mask;
	int start_point;

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

int		parse_csp(const char *ptr, va_list arg, int fd)
{
	if (*ptr == 'c')
		ft_putchar(va_arg(arg, int));
	else if (*ptr == 's')
		ft_putstr(va_arg(arg, char*));
	else if (*ptr == 'p')
	{
		ft_putstr("0x");
		ft_itoa_box((unsigned long long) va_arg(arg, void*), 'x', fd);
	}
	return (1);
}

int		parse_box(const char *ptr, va_list arg, int fd)
{
	ft_itoa_box((unsigned int)va_arg(arg,unsigned int), *ptr, fd);
	return (1);
}

int		parse_lbox(const char *ptr, va_list arg, int fd)
{
	ft_itoa_box((unsigned long int)va_arg(arg,unsigned long int), *ptr, fd);
	return (1);
}

int parse_ld(const char *ptr, va_list arg, int fd)
{
	;
}

int		parse(char **ptr, va_list arg, int fd)
{
	if (**ptr == 'c' || **ptr == 's' || **ptr == 'p')
		parse_csp(*ptr, arg, fd);
	if (**ptr == 'x' || **ptr == 'X' || **ptr == 'o' || **ptr == 'b')
		parse_box(*ptr, arg, fd);
	if (**ptr == 'l')
	{
		(*ptr)++;
		if (**ptr == '\0')
			return (0);
		else if (**ptr == 'x' || **ptr == 'X' || **ptr == 'o' || **ptr == 'b')
			parse_lbox(*ptr, arg, fd);
		else if (**ptr == 'd')
			parse_ld(*ptr, arg, fd);
	}
	return (1);
}

int 	ft_printf(const char *format, ...)
{
	va_list		arg;
	char		*ptr;
	char 		tmp_char;
	char 		*tmp_str;


	va_start(arg, format);
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
				if (parse(&ptr, arg, 1) == 0)
					return (0);
		}
		ptr++;
	}
	va_end(arg);
	return (0);
}