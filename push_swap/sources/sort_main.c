/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odrinkwa <odrinkwa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 21:23:33 by odrinkwa          #+#    #+#             */
/*   Updated: 2019/10/24 22:13:33 by odrinkwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

t_min			find_minimum_operations_stack(int pos_b, int rrb_pos_b,
										int pos_a, int rra_pos_a)
{
	int		min;
	int		type_rotation;
	t_min	res;

	type_rotation = 1;
	min = MAX(pos_b, pos_a);
	if (MAX(rrb_pos_b, rra_pos_a) < min)
	{
		min = MAX(rrb_pos_b, rra_pos_a);
		type_rotation = 2;
	}

	if (pos_b + rra_pos_a < min)
	{
		min = pos_b + rra_pos_a;
		type_rotation = 3;
	}
	if (pos_a + rrb_pos_b < min)
	{
		min = pos_a + rrb_pos_b;
		type_rotation = 4;
	}
	res.min = min;
	res.type_rotation = type_rotation;
	return (res);
}

static void		main_sort_aux(t_stack *a, t_stack *b, t_min *min_ops)
{
	if (min_ops->type_rotation == 1)
		while (min_ops->pos_a > 0 && min_ops->pos_b > 0)
		{
			rr(a, b);
			min_ops->pos_a--;
			min_ops->pos_b--;
		}
	else if (min_ops->type_rotation == 2)
		while (min_ops->pos_a < a->len && min_ops->pos_b < b->len)
		{
			rrr(a, b);
			min_ops->pos_a++;
			min_ops->pos_b++;
		}
	ra_to_top_value(a, b, min_ops->pos_a);
	rb_to_top_value(a, b, min_ops->pos_b);
	pa(a, b);
}

static void		put_min_ops_aux(t_min *min_ops, t_min *min_tmp,
								int a_pos_low_value, int pos_b)
{
	*min_ops = *min_tmp;
	min_ops->pos_a = a_pos_low_value;
	min_ops->pos_b = pos_b;
}

void			main_sort_algorithm(t_stack *a, t_stack *b)
{
	t_dlist		*curr_b;
	int			pos_b;
	t_min		min_ops;
	t_min		min_tmp;

	first_group_stacks(a, b);
	while (b->len > 0)
	{
		curr_b = b->top;
		pos_b = 0;
		min_ops.pos_a = -1;
		while (curr_b != NULL)
		{
			find_between_asc_values_with_limits(a, int_content(curr_b));
			min_tmp = find_minimum_operations_stack(pos_b, b->len - pos_b,
								a->pos_low_value, a->len - a->pos_low_value);
			if (min_ops.pos_a == -1 || min_tmp.min < min_ops.min)
				put_min_ops_aux(&min_ops, &min_tmp, a->pos_low_value, pos_b);
			curr_b = curr_b->next;
			pos_b++;
		}
		main_sort_aux(a, b, &min_ops);
	}
	find_max_stack(a);
	ra_to_bottom_value(a, b, a->pos_max);
}

void			stack_sort(t_stack *a, t_stack *b)
{
	if (a->len < 2)
		;
	else if (a->len == 2)
	{
		if (peek_top(*a) > peek_bottom(*a))
			sa(a, b);
	}
	else if (a->len == 3)
		sort_a_three_elements(a, b);
	else
		main_sort_algorithm(a, b);
}
