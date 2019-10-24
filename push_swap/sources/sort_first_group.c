/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_first_group.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odrinkwa <odrinkwa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 21:40:48 by odrinkwa          #+#    #+#             */
/*   Updated: 2019/10/24 21:55:11 by odrinkwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

static void				search_asc_while_aux(t_dlist *curr_curr,
						t_longest_asc *curr_asc, t_longest_asc *max)
{
	while (curr_curr != NULL && curr_curr->next != NULL &&
				int_content(curr_curr) < int_content(curr_curr->next))
	{
		curr_curr = curr_curr->next;
		curr_asc->count++;
	}
	if (curr_asc->count > max->count)
	{
		max->count = curr_asc->count;
		max->pos = curr_asc->pos;
	}
}

static t_longest_asc	search_longest_asc(t_stack *a)
{
	t_dlist			*curr;
	t_dlist			*curr_curr;
	t_longest_asc	curr_asc;
	t_longest_asc	max;

	curr = a->top;
	curr_asc.pos = 0;
	max.pos = -1;
	max.count = -1;
	while (curr != NULL)
	{
		curr_asc.count = 1;
		curr_curr = curr;
		search_asc_while_aux(curr_curr, &curr_asc, &max);
		curr = curr->next;
		curr_asc.pos++;
	}
	return (max);
}

static void				group_stack_while_aux(t_stack *a, t_stack *b,
								t_longest_asc asc, int len_a)
{
	while (asc.pos > 0)
	{
		pb(a, b);
		asc.pos--;
		len_a--;
	}
	if (asc.count == len_a)
		return ;
	while (asc.count > 0)
	{
		ra(a, b);
		asc.count--;
		len_a--;
	}
	while (len_a > 0)
	{
		pb(a, b);
		len_a--;
	}
}

void					first_group_stacks(t_stack *a, t_stack *b)
{
	t_longest_asc	asc;
	int				len_a;

	len_a = a->len;
	asc = search_longest_asc(a);
	if (asc.count == len_a)
		return ;
	if (asc.count > 3)
		group_stack_while_aux(a, b, asc, len_a);
	else
	{
		left_a_three_elements(a, b);
		sort_a_three_elements(a, b);
	}
}
