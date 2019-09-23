#include "libft.h"
#include "ft_printf.h"

int		parse_csp(char *ptr, va_list arg)
{
	char 		tmp_char;
	char 		*tmp_str;

	ptr++;
	if (*ptr == '\0')
		return (0);
	else if (*ptr == 'c')
		ft_putchar(va_arg(arg, int));
	else if (*ptr == 's')
		ft_putstr(va_arg(arg, char*));
	else if (*ptr == 'p')
	{

		return (1); //TODO сделать вывод адреса (значения указателя)
	}
	else
		ft_putchar(*ptr);
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
			if (parse_csp(ptr, arg) == 0)
				return (0);
			else
				ptr++;
		}
		ptr++;
	}
	va_end(arg);
	return (0);
}