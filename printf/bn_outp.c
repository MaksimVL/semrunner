/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bignum.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odrinkwa <odrinkwa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/25 19:31:16 by odrinkwa          #+#    #+#             */
/*   Updated: 2019/09/29 14:14:36 by semenbegunov     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "double.h"

static void		check_putzerosinfract(t_bigdec bd, char *output)
{
	char tmp[10];

	tmp[0] = '\0';
	ft_putnbr_output(bd.fractpart.number[bd.fractpart.size - 1], tmp);
	putnzeros(output, bd.sizefract % 4 - ft_strlen(tmp));
	ft_strcat(output, tmp);
}

void			ft_putintpart_bignum(t_bignum bn, char *output)
{
	int i;

	if (bn.sign == -1)
		ft_strcat(output, "-");
	i = bn.size - 1;
	if (i < 0)
	{
		ft_strcat(output, "0");
		return ;
	}
	else
		ft_strcatnbr(output, bn.number[i]);
	while (i-- > 0)
	{
		putzeros_bignum(output, bn.number[i]);
		if (bn.number[i] != 0)
			ft_strcatnbr(output, bn.number[i]);
	}
}

void			ft_putfractpart_bignum(t_bigdec bd, char *output)
{
	int i;

	i = bd.fractpart.size;
	if (i <= 0)
	{
		ft_strcat(output, "0");
		return ;
	}
	if (bd.fractpart.size * 4 <= bd.sizefract)
		putnzeros(output, bd.sizefract - bd.fractpart.size * 4);
	else
	{
		check_putzerosinfract(bd, output);
		i--;
	}
	while (i-- > 0)
	{
		putzeros_bignum(output, bd.fractpart.number[i]);
		if (bd.fractpart.number[i] != 0)
			ft_strcatnbr(output, bd.fractpart.number[i]);
	}
}

void			reformat_output(char *output, int prec)
{
	char *c;

	c = ft_strchr(output, '.');
	if (c)
	{
		while (prec-- >= 0 && c)
			c++;
		if (c)
			*c = '\0';
	}
	else if (prec != 0)
	{
		ft_strcat(output, ".");
		putnzeros(output, prec);
	}
}

void			put_bd_output(t_bigdec bd, char *output, int prec)
{
	if (bd.sign == -1)
		ft_strcat(output, "-");
	ft_putintpart_bignum(bd.intpart, output);
	if (!((bd.prec == 0 || bd.fractpart.size == 0)))
	{
		ft_strcat(output, ".");
		ft_putfractpart_bignum(bd, output);
	}
	reformat_output(output, prec);
}
