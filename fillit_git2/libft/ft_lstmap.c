/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwolf <hwolf@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 14:59:52 by hwolf             #+#    #+#             */
/*   Updated: 2019/09/07 19:05:21 by hwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list		*ans;
	t_list		*ptr;

	if (lst && (*f))
	{
		ptr = f(lst);
		ans = ptr;
		while (lst->next)
		{
			lst = lst->next;
			if (!(ptr->next = f(lst)))
			{
				free(ptr->next);
				return (NULL);
			}
			ptr = ptr->next;
		}
		return (ans);
	}
	return (NULL);
}
