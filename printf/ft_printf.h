#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>

# define SIZE_BN 500
# define BASE_BN 10000

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

union 						u_double
{
	long double				ld;
	struct
	{
		unsigned long int	m : 64;
		unsigned int		e : 15;
		unsigned int		s : 1;
	}						s_parts;
};

typedef struct		s_bignum
{
	long long int	number[SIZE_BN];
	int 			sign;
	int 			size;
}					t_bignum;

typedef struct 		s_bd
{
	t_bignum		intpart;
	t_bignum		fractpart;
	int				sizefract;
}					t_bd;
int 					ft_printf(const char *format, ...);

void 			initialize_bignum(t_bignum *n);
void			ft_assign_bignum(t_bignum *bn, long long n);
void			ft_print_bignum(t_bignum bn);
void			fixzero_bignum(t_bignum *bn);
void			fixsize_bignum(t_bignum *bn);
void			fixup_bignum(t_bignum *bn);
void			ft_isumabs_bignum(t_bignum *res, t_bignum bn2);
void			ft_imul_bignum(t_bignum *res, t_bignum bn2);
void			ft_deepcopy_bignum(t_bignum *res, t_bignum bn);
void			ft_ipow_bignum(t_bignum *res, unsigned int n);
t_bignum		ft_mul_bignum(t_bignum bn1, t_bignum bn2);
t_bignum		ft_pow_bignum(t_bignum bn, unsigned int n);
void			ft_putintpart_bignum(t_bignum bn, char *output);
void			ft_putfractpart_bignum(t_bignum bn, char *output, int pow);
void			putnzeros(char *output, int prec);
int 			ft_itoa_f(union u_double d, t_printf *p, int prec);

#endif