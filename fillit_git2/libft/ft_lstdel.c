/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwolf <hwolf@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 14:44:17 by hwolf             #+#    #+#             */
/*   Updated: 2019/09/17 19:20:51 by hwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *ptr;

	if (alst && (*del))
		while (*alst)
		{
			ptr = (*alst)->next;
			(*del)((*alst)->content, (*alst)->content_size);
			free(*alst);
			(*alst) = ptr;
		}
}

void	ft_lst_del(t_list **alst)
{
	t_list *ptr;

	if (alst)
		while (*alst)
		{
			ptr = (*alst)->next;
			free(*alst);
			(*alst) = ptr;
		}
}
