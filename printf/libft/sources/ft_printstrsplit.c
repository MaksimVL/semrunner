/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printstrsplit.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odrinkwa <odrinkwa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 14:11:52 by odrinkwa          #+#    #+#             */
/*   Updated: 2019/09/26 13:18:25 by semenbegunov     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_printstrsplit(char **tab)
{
	if (!tab)
		return ;
	while (*tab)
	{
		ft_putendl(*tab);
		tab++;
	}
}