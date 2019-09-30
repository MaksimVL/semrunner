#include "libft.h"
#include "double.h"

t_bignum		ft_pow_bignum(t_bignum bn, unsigned int n)
{
	unsigned int i;
	t_bignum res_bn;

	if (n == 0)
	{
		ft_assign_bignum(&res_bn, 1);
		return (res_bn);
	}
	ft_deepcopy_bignum(&res_bn, bn);
	i = 1;
	while (i < n)
	{
		ft_imul_bignum(&res_bn, bn);
		i++;
	}
	return (res_bn);
}

void			ft_isumabs_bignum(t_bignum *res, t_bignum bn2)
{
	int i;
	t_bignum	temp_bn;

	i = 0;
	initialize_bignum(&temp_bn);
	while(i < SIZE_BN)
	{
		temp_bn.number[i] += res->number[i] + bn2.number[i];
		fixup_bignum(&temp_bn);
		i++;
	}
	fixsize_bignum(&temp_bn);
	if (temp_bn.size > 0)
		temp_bn.sign = 1;
	ft_deepcopy_bignum(res, temp_bn);
}

void			ft_imul_bignum(t_bignum *res, t_bignum bn2)
{
	int 		i;
	int			j;
	t_bignum	temp_bn;

	initialize_bignum(&temp_bn);
	i = 0;
	while (i < SIZE_BN)
	{
		j = 0;
		while (j < SIZE_BN - i)
		{
			temp_bn.number[i + j] += res->number[i] * bn2.number[j];
			j++;
		}
		i++;
	}
	temp_bn.sign = res->sign * bn2.sign;
	fixup_bignum(&temp_bn);
	fixsize_bignum(&temp_bn);
	ft_deepcopy_bignum(res, temp_bn);
}

t_bignum		ft_mul_bignum(t_bignum bn1, t_bignum bn2)
{
	int 		i;
	int			j;
	t_bignum	res_bn;

	initialize_bignum(&res_bn);
	i = 0;
	while (i < SIZE_BN)
	{
		j = 0;
		while (j < SIZE_BN - i)
		{
			res_bn.number[i + j] += bn1.number[i] * bn2.number[j];
			j++;
		}
		i++;
	}
	res_bn.sign = bn1.sign * bn2.sign;
	fixup_bignum(&res_bn);
	fixsize_bignum(&res_bn);
	return (res_bn);
}

void			ft_ipow_bignum(t_bignum *res, unsigned int n)
{
	unsigned int i;
	t_bignum tmp_bn;

	if (n == 0)
	{
		ft_assign_bignum(res, 1);
		return ;
	}

	ft_deepcopy_bignum(&tmp_bn, *res);
	i = 1;
	while (i < n)
	{
		ft_imul_bignum(res, tmp_bn);
		i++;
	}
}
