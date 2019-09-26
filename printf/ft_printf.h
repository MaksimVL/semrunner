#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>

#define SIZE_BN 100
#define BASE_BN 10000

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
	long long int	number[100];
	int 			sign;
	int 			size;
}					t_bignum;

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

#endif