/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstaddback.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odrinkwa <odrinkwa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 22:35:33 by odrinkwa          #+#    #+#             */
/*   Updated: 2019/09/09 22:35:36 by odrinkwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstaddback(t_list *alst, t_list *new)
{
	if (!alst)
		return ;
	while (alst->next)
		alst = alst->next;
	alst->next = new;
}
