/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odrinkwa <odrinkwa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 19:35:33 by odrinkwa          #+#    #+#             */
/*   Updated: 2019/10/24 19:43:38 by odrinkwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

void			ss(t_stack *a, t_stack *b)
{
	stack_swap(a);
	stack_swap(b);
	write_operation("ss", a, b);
}

void			pa(t_stack *a, t_stack *b)
{
	stack_push_ab(a, b);
	write_operation("pa", a, b);
}

void			rra(t_stack *a, t_stack *b)
{
	if (b == NULL && b != NULL)
		return ;
	stack_rrotate(a);
	write_operation("rra", a, b);
}

void			rrb(t_stack *a, t_stack *b)
{
	if (a == NULL && a != NULL)
		return ;
	stack_rrotate(b);
	write_operation("rrb", a, b);
}

void			rrr(t_stack *a, t_stack *b)
{
	stack_rrotate(a);
	stack_rrotate(b);
	write_operation("rrr", a, b);
}
