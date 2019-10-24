/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_rotate_to_top.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odrinkwa <odrinkwa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 20:01:37 by odrinkwa          #+#    #+#             */
/*   Updated: 2019/10/24 20:02:10 by odrinkwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

void			rotate_ab_to_top_value(t_stack *stack, t_stack *o_stack,
										int pos_value, char n_stack)
{
	if (pos_value < (int)(stack->len / 2 + 1))
		while (pos_value-- > 0)
			n_stack == 'a' ? ra(stack, o_stack) : rb(o_stack, stack);
	else
		while (pos_value++ < stack->len)
			n_stack == 'a' ? rra(stack, o_stack) : rrb(o_stack, stack);
}

void			ra_to_top_value(t_stack *a, t_stack *b, int pos_value)
{
	rotate_ab_to_top_value(a, b, pos_value, 'a');
}

void			rb_to_top_value(t_stack *a, t_stack *b, int pos_value)
{
	rotate_ab_to_top_value(b, a, pos_value, 'b');
}
