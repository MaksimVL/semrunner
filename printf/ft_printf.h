#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>

# define NRM "\x1b[00m"
# define RED "\x1b[31m"
# define GRN  "\x1B[32m"
# define YEL  "\x1B[33m"
# define BLU  "\x1B[34m"
# define MAG  "\x1B[35m"
# define CYN  "\x1B[36m"
# define WHT  "\x1B[37m"

#define F_PLUS 0x1
#define F_MINUS 0x2
#define F_SPACE 0x4
#define F_OCTO 0x8
#define F_ZERO 0x10

typedef struct				s_printf
{
	char 					*str;
	char 					buff[500];
	char 					*output;
	unsigned int			flags;
	size_t 					width;
	int 					prec;
	int 					fd;
	va_list 				arg;
}							t_printf;

typedef	struct				s_param
{
	va_list 				arg;
}							t_param;

int 					ft_printf(const char *format, ...);


int 			ft_itoa_f1(union u_double d, t_printf *p, int prec);

#endif