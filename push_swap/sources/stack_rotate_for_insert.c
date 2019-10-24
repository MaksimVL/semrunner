/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_rotate_for_insert.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odrinkwa <odrinkwa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 20:04:54 by odrinkwa          #+#    #+#             */
/*   Updated: 2019/10/24 20:18:42 by odrinkwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

void			find_between_desc_values(t_stack *b, int value)
{
	int			pos;
	t_dlist		*curr;

	curr = b->top;
	pos = 0;
	b->pos_low_value = 0;
	b->low_value = int_content(b->top);
	while (curr->next != NULL)
	{
		pos++;
		if (int_content(curr) >= value && value >= int_content(curr->next))
		{
			b->pos_low_value = pos;
			b->low_value = int_content(curr->next);
			return ;
		}
		curr = curr->next;
	}
}

void			find_between_asc_values(t_stack *a, int value)
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

void			rotate_a_asc_for_insert_value(t_stack *a, t_stack *b, int value)
{
	if (a->len == 0 || a->len == 1)
		return ;
	find_max_stack(a);
	find_min_stack(a);
	if (value > a->max_stack || value < a->min_stack)
		ra_to_top_value(a, b, a->pos_min);
	else
	{
		find_between_asc_values(a, value);
		ra_to_top_value(a, b, a->pos_low_value);
	}
}

void			pa_all(t_stack *a, t_stack *b)
{
	while (b->len > 0)
		pa(a, b);
}

void			rotate_b_desc_for_insert_value(t_stack *a, t_stack *b,
											int value)
{
	if (b->len == 0 || b->len == 1)
		return ;
	find_max_stack(b);
	find_min_stack(b);
	if (value > b->max_stack || value < b->min_stack)
		rb_to_top_value(a, b, b->pos_max);
	else
	{
		find_between_desc_values(b, value);
		rb_to_top_value(a, b, b->pos_low_value);
	}
}
