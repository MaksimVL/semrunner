#include "libft.h"
#include "double.h"

void	ft_intpart(int pow, unsigned long int mant, int exp, t_bigdec *bd)
{
	t_bignum	mult;
	t_bignum	*res;

	res = &(bd->intpart);
	if (exp <= 0)
		return ;
	ft_assign_bignum(&mult, 2);
	ft_ipow_bignum(&mult, pow);
	while (mant > 0)
	{
		if (mant & 1)
			ft_isumabs_bignum(res, mult);
		mant >>= 1;
		ft_isumabs_bignum(&mult, mult);
	}
}

void 	ft_fractpart(int pow, unsigned long int mant, char *output, t_bigdec *bd)
{
	int		i;
	t_bignum	five;
	t_bignum	two;
	t_bignum	*res;

	res = &(bd->fractpart);

	ft_assign_bignum(res, 0);
	ft_assign_bignum(&five, 5);
	ft_assign_bignum(&two, 2);
	ft_ipow_bignum(&five, 64 + pow);
	i = 0;
	while (++i <= 64)
	{
		if (mant &0x8000000000000000)
			ft_isumabs_bignum(res, ft_mul_bignum(five, ft_pow_bignum(two, 64 - i + (pow == 0 ? 0 : 1))));
		mant <<= 1;
	}
	bd->sizefract = 64 + pow;
}

int		check_specvalues(union u_double d, char *output)
{
	if (!((d.ld != d.ld || d.ld == 1.0 / 0.0 || d.ld == -1.0 / 0.0 ||
		   (d.s_parts.e == 0 && d.s_parts.m == 0))))
		return (0);
	else
	{
		if (d.ld != d.ld)
			ft_strcat(output, "nan");
		else if (d.ld == 1.0 / 0.0)
			ft_strcat(output, "inf");
		else if (d.ld == -1.0 / 0.0)
			ft_strcat(output, "-inf");
		else if (d.s_parts.e == 0 && d.s_parts.m == 0)
		{
			if (d.s_parts.s == 1)
				ft_strcat(output, "-0");
			else
				ft_strcat(output, "0");
		}
	}
	return (1);
}

int		ft_pow_bn(int num, unsigned int p)
{
	int i = 0;
	int tmp;

	if (p == 0)
		return (1);
	tmp = num;

	while (++i < p)
		num = num * tmp;
	return (num);
}

int 	ft_itoa_f(union u_double d, char *output, int prec)
{
	int 				exp;
	int 				pow;
	unsigned long int	mant;
	t_bigdec			bd;

	if (check_specvalues(d, output))
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

			ft_fractpart(pow, exp <= 0 ? d.s_parts.m : d.s_parts.m << exp, output, &bd);
			roundbd(&bd, prec);
		}
		put_bd_output(bd, output, prec);
	}
}
