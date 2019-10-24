/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odrinkwa <odrinkwa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 19:28:29 by odrinkwa          #+#    #+#             */
/*   Updated: 2019/10/24 21:21:15 by odrinkwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

void			find_max_stack(t_stack *b)
{
	int		pos;
	t_dlist	*curr_lst;

	if (b->len == 0)
	{
		b->pos_max = -1;
		return ;
	}
	curr_lst = b->top;
	pos = 0;
	b->max_stack = int_content(curr_lst);
	b->pos_max = 0;
	while (curr_lst != NULL)
	{
		if (b->max_stack < int_content(curr_lst))
		{
			b->max_stack = int_content(curr_lst);
			b->pos_max = pos;
		}
		curr_lst = curr_lst->next;
		pos++;
	}
}

void			find_min_stack(t_stack *b)
{
	int		pos;
	t_dlist	*curr_lst;

	if (b->len == 0)
	{
		b->pos_min = -1;
		return ;
	}
	curr_lst = b->top;
	pos = 0;
	b->min_stack = int_content(curr_lst);
	b->pos_min = 0;
	while (curr_lst != NULL)
	{
		if (b->min_stack > int_content(curr_lst))
		{
			b->min_stack = int_content(curr_lst);
			b->pos_min = pos;
		}
		curr_lst = curr_lst->next;
		pos++;
	}
}

static void		find_between_aux(t_stack *a, int value)
{
	int			pos;
	t_dlist		*curr;

	curr = a->top;
	pos = 0;
	a->pos_low_value = 0;
	a->low_value = int_content(a->top);
	while (curr->next != NULL)
	{
		pos++;
		if (int_content(curr) <= value && value <= int_content(curr->next))
		{
			a->pos_low_value = pos;
			a->low_value = int_content(curr->next);
			return ;
		}
		curr = curr->next;
	}
}

void			find_between_asc_values_with_limits(t_stack *a, int value)
{
	if (a->len == 0 || a->len == 1)
	{
		a->pos_low_value = 0;
		return ;
	}
	find_max_stack(a);
	find_min_stack(a);
	if (value > a->max_stack || value < a->min_stack)
	{
		a->pos_low_value = a->pos_min;
		a->low_value = a->min_stack;
		return ;
	}
	find_between_aux(a, value);
}
