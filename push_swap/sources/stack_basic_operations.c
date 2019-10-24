/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_basic_operations.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odrinkwa <odrinkwa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 19:46:27 by odrinkwa          #+#    #+#             */
/*   Updated: 2019/10/24 21:16:20 by odrinkwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

void			del_int(void *content, size_t size)
{
	if (size == 0 && size != 0)
		return ;
	ft_memdel((void**)&content);
}

int				int_content(t_dlist *list)
{
	return (*(int*)(list->content));
}

int				peek_top(t_stack stack)
{
	return (*(int*)(stack.top->content));
}

int				peek_bottom(t_stack stack)
{
	return (*(int*)(stack.bottom->content));
}

int				peek_second(t_stack stack)
{
	return (*(int*)(stack.top->next->content));
}
