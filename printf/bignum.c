/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bignum.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odrinkwa <odrinkwa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/25 19:31:16 by odrinkwa          #+#    #+#             */
/*   Updated: 2019/09/25 23:04:14 by odrinkwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

void initialize_bignum(t_bignum *n)
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

void	ft_assign_bignum(t_bignum *bn, long long n)
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

void ft_print_bignum(t_bignum bn)
{
	int i;

	if (bn.sign == -1)
		ft_putchar('-');
	i = bn.size - 1;
	if (i < 0)
	{
		ft_printf("0");
		return ;
	}
	else
		ft_printf("%lld", bn.number[i]);
	while(i-- > 0)
	{
		if (bn.number[i] < 10)
			ft_putstr("000");
		else if (bn.number[i] < 100)
			ft_putstr("00");
		else if (bn.number[i] < 1000)
			ft_putstr("0");
		ft_printf("%lld", bn.number[i]);
	}
}

void fixzero_bignum(t_bignum *bn)
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

void fixsize_bignum(t_bignum *bn)
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

void fixup_bignum(t_bignum *bn)
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

void ft_isumabs_bignum(t_bignum *res, t_bignum bn2)
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

void ft_imul_bignum(t_bignum *res, t_bignum bn2)
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

void 		ft_deepcopy_bignum(t_bignum *res, t_bignum bn)
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

void		ft_ipow_bignum(t_bignum *res, unsigned int n)
{
	unsigned int i;
	t_bignum tmp_bn;

	ft_deepcopy_bignum(&tmp_bn, *res);
	i = 1;
	while (i < n)
	{
		ft_imul_bignum(res, tmp_bn);
		i++;
	}
}