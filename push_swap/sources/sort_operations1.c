/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_operations1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odrinkwa <odrinkwa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 20:36:53 by odrinkwa          #+#    #+#             */
/*   Updated: 2019/10/24 21:17:18 by odrinkwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

void			sort_a_three_elements(t_stack *a, t_stack *b)
{
	find_max_stack(a);
	ra_to_bottom_value(a, b, a->pos_max);
	if (peek_top(*a) > peek_second(*a))
		sa(a, b);
}

void			left_a_three_elements(t_stack *a, t_stack *b)
{
	while (a->len > 3)
		pb(a, b);
}

void			sort_le_five_elements(t_stack *a, t_stack *b)
{
	while (a->len > 3)
		pb(a, b);
	sort_a_three_elements(a, b);
	while (b->len > 0)
	{
		rotate_a_asc_for_insert_value(a, b, peek_top(*b));
		pa(a, b);
	}
	find_max_stack(a);
	ra_to_bottom_value(a, b, a->pos_max);
}
