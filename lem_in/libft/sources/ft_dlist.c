/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlist.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odrinkwa <odrinkwa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/26 14:52:53 by odrinkwa          #+#    #+#             */
/*   Updated: 2019/11/24 14:19:44 by odrinkwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_dlist		*ft_dlstnew(void const *content, size_t content_size)
{
	t_dlist	*ptr_list;

	if (!(ptr_list = (t_dlist*)malloc(sizeof(t_dlist))))
		return (NULL);
	ptr_list->next = NULL;
	ptr_list->prev = NULL;
	if (content)
	{
		if (!(ptr_list->content = (void*)malloc(content_size)))
			return (NULL);
		ft_memcpy(ptr_list->content, content, content_size);
		ptr_list->content_size = content_size;
	}
	else
	{
		ptr_list->content = NULL;
		ptr_list->content_size = 0;
	}
	return (ptr_list);
}

void		ft_dlstadd(t_dlist **alst, t_dlist *new)
{
	if (!(alst))
		return ;
	if (new)
	{
		new->next = *alst;
		if (*alst)
			(*alst)->prev = new;
		*alst = new;
	}
}

void		ft_dlst_addback(t_dlist **alst, t_dlist *new)
{
	t_dlist		*temp;

	if (alst == NULL)
		return ;
	if (*alst == NULL)
		*alst = new;
	else
	{
		temp = *alst;
		while (temp->next)
			temp = temp->next;
		temp->next = new;
		new->prev = temp;
	}
}

void		ft_dlstdel(t_dlist **alst, void (*del)(void *, size_t))
{
	t_dlist	*next;
	t_dlist	*curr;

	curr = *alst;
	while (curr)
	{
		next = curr->next;
		if (*del != NULL)
			del(curr->content, curr->content_size);
		if (curr->content_size != 0)
			ft_memdel((void**)&(curr->content));
		ft_memdel((void**)&curr);
		curr = next;
	}
	*alst = NULL;
}

void		*ft_dlst_addcontent_back(t_dlist **list, void *content,
										size_t content_size)
{
	t_dlist		*temp;

	temp = ft_dlstnew(content, content_size);
	if (temp == NULL)
		return (NULL);
	ft_dlst_addback(list, temp);
	return (list);
}
