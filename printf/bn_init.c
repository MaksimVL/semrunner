#include "libft.h"
#include "double.h"

void			initialize_bignum(t_bignum *n)
{
	int i;

	i = 0;
	while (i < SIZE_BN)
	{
		n->number[i] = 0;
		i++;
	}
	n->sign = 0;
	n->size = 0;
}

void			initialize_bd(t_bigdec *bd)
{
	initialize_bignum(&(bd->intpart));
	initialize_bignum(&(bd->fractpart));
	bd->sizefract = 0;
	bd->prec = 0;
	bd->sign = 0;
}

void			ft_assign_bignum(t_bignum *bn, long long n)
{
	int i;

	initialize_bignum(bn);
	if (n == 0)
		return ;
	bn->sign = (n < 0) ? -1 : 1;

	i = 0;
	if (n < 0)
	{
		bn->number[i++] = -(n % BASE_BN);
		n = -(n / BASE_BN);
	}
	while (n != 0)
	{
		bn->number[i++] = (int)(n % BASE_BN);
		n = n / BASE_BN;
	}
	bn->size = i;
}

void 			ft_deepcopy_bignum(t_bignum *res, t_bignum bn)
{
	int i;

	i = 0;
	while (i < SIZE_BN)
	{
		res->number[i] = bn.number[i];
		i++;
	}
	res->sign = bn.sign;
	res->size = bn.size;
}

void			putzeros_bignum(char *output, long long nbr)
{
	int i;
	i = BASE_BN / 10;

	while (nbr < i)
	{
		ft_strcat(output, "0");
		i /= 10;
	}
}

