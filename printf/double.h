#ifndef DOUBLE_H
#define DOUBLE_H

# include <stdarg.h>

# define SIZE_BN 500
# define BASE_BN 10000

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

typedef struct 		s_bigdec
{
	t_bignum		intpart;
	t_bignum		fractpart;
	int				sizefract;
	int 			prec;
	int 			sign;
}					t_bigdec;

void 			initialize_bignum(t_bignum *n);
void			ft_assign_bignum(t_bignum *bn, long long n);
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
void			ft_putfractpart_bignum(t_bigdec bd, char *output);
void			putnzeros(char *output, int prec);
int 			ft_itoa_f(union u_double d, char *output, int prec);
int				ft_pow_bn(int num, unsigned int p);
void			roundbd(t_bigdec *bd, int prec);
int 			getiinfract(t_bigdec bd, int i);
void			initialize_bd(t_bigdec *bd);
void			ft_strcatnbr(char *output, long int nbr);
void			ft_putnbr_output(long int n, char *output);
void			putzeros_bignum(char *output, long long nbr);
void			ft_put_one_inpos_bignum(t_bignum *bn, int pos);
int 			set_onetozero_infract(t_bigdec *bd, int i);
void			put_bd_output(t_bigdec bd, char *output, int prec);
void			prf_dblcalc(long double d, int prec, char *str);

#endif
