/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dictclearzero.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odrinkwa <odrinkwa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 16:22:00 by odrinkwa          #+#    #+#             */
/*   Updated: 2019/09/15 18:11:18 by odrinkwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_dict **dict, void (*del)(void *, size_t))
{
	t_dict	*curr;

	if (dict == NULL || *dict == NULL)
		return ;
	curr = *dict;
	if (curr->prev != NULL)
		(curr->prev)->next = curr->next;
	if (curr->next != NULL)
		(curr->next)->prev = curr->next;
	if (del != NULL)
		del(curr->content, curr->content_size);
	ft_memdel(dict);


	size_t	i;
	t_list	*curr;
	t_list	*prev;

	if (!(*alst))
		return ;
	if (nbr == 0)
	{
		ft_lstdelone(alst, del);
		return ;
	}
	prev = *alst;
	curr = prev->next;
	i = 1;
	while (curr && i < nbr)
	{
		prev = curr;
		curr = curr->next;
		i++;
	}
	if (!(curr))
		return ;
	prev->next = curr->next;
	del(curr->content, (curr)->content_size);
	ft_memdel((void**)(&curr));
}



static void		ft_cycledict(t_dict **curr, t_dict **prev)
{
	if ((*curr)->content == NULL)
	{
		(*prev)->next = (*curr)->next;
		ft_memdel((void**)curr);
		(*curr) = (*prev)->next;
		if (*curr != NULL)
			(*curr)->prev = *prev;
	}
	else
	{
		(*prev) = (*curr);
		(*curr) = (*curr)->next;
	}
}

void			ft_dictclearzero(t_dict **dict)
{
	t_dict *curr;
	t_dict *prev;

	if (dict == NULL)
		return ;
	while ((*dict) && (*dict)->content == NULL)
	{
		curr = *dict;
		(*dict) = (*dict)->next;
		if (*dict != NULL)
			(*dict)->prev = NULL;
		ft_memdel((void**)&curr);
	}
	if (*dict == NULL)
		return ;
	prev = *dict;
	curr = (*dict)->next;
	while (curr)
		ft_cycledict(&curr, &prev);
}
