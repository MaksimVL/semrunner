/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odrinkwa <odrinkwa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 21:55:36 by odrinkwa          #+#    #+#             */
/*   Updated: 2019/10/24 23:33:33 by odrinkwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

int				find_repeat_elements(t_stack *stack)
{
	t_dlist		*curr;
	t_dlist		*i_lst;
	int			curr_value;

	if (stack->len == 0)
		return (1);
	curr = stack->top;
	while (curr != NULL)
	{
		curr_value = int_content(curr);
		i_lst = curr->next;
		while (i_lst != NULL)
		{
			if (curr_value == int_content(i_lst))
				return (1);
			i_lst = i_lst->next;
		}
		curr = curr->next;
	}
	return (0);
}

int				check_sorted_stack(t_stack *stack)
{
	t_dlist	*curr;

	curr = stack->top;
	while (curr != NULL)
	{
		if (curr->next == NULL)
			return (1);
		if (int_content(curr) > int_content(curr->next))
			return (0);
		curr = curr->next;
	}
	return (1);
}
