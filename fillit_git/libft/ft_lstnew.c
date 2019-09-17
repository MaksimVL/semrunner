/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwolf <hwolf@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 14:07:21 by hwolf             #+#    #+#             */
/*   Updated: 2019/09/08 20:12:10 by hwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list *ptr;

	if (!(ptr = (t_list*)malloc(sizeof(*ptr))))
		return (NULL);
	if (content)
	{
		if (!(ptr->content = malloc(content_size)))
		{
			free(ptr);
			return (NULL);
		}
		ft_memcpy(ptr->content, content, content_size);
		ptr->content_size = content_size;
	}
	else
	{
		ptr->content = NULL;
		ptr->content_size = 0;
	}
	ptr->next = NULL;
	return (ptr);
}
