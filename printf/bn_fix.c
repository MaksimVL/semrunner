#include "libft.h"
#include "double.h"

void			fixsize_bignum(t_bignum *bn)
{
	int i;

	i = SIZE_BN - 1;
	while (i >= 0)
	{
		if (bn->number[i] != 0)
			break ;
		i--;
	}
	bn->size = i + 1;
}

void			fixup_bignum(t_bignum *bn)
{
	int i;

	i = 0;
	while(i < SIZE_BN - 1)
	{
		bn->number[i + 1] += bn->number[i] / BASE_BN;
		bn->number[i] = bn->number[i] % BASE_BN;
		i++;
	}
	fixzero_bignum(bn);
}

void			fixzero_bignum(t_bignum *bn)
{
	int i;

	i = 0;
	while (i < SIZE_BN)
	{
		if (bn->number[i] != 0)
			return ;
		i++;
	}
	bn->size = 0;
	bn->sign = 0;
}
