/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_rotate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odrinkwa <odrinkwa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 19:39:51 by odrinkwa          #+#    #+#             */
/*   Updated: 2019/10/24 19:43:22 by odrinkwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

static void		stack_rotate_two_el(t_stack *stack, t_dlist *top,
									t_dlist *bottom)
{
	top->next = NULL;
	bottom->prev = NULL;
	top->prev = bottom;
	bottom->next = top;
	stack->top = bottom;
	stack->bottom = top;
}

void			stack_rotate(t_stack *stack)
{
	t_dlist *top;
	t_dlist *bottom;
	t_dlist	*next;

	if (stack->len <= 1)
		return ;
	top = stack->top;
	bottom = stack->bottom;
	if (stack->len == 2)
		stack_rotate_two_el(stack, top, bottom);
	else
	{
		next = top->next;
		next->prev = NULL;
		bottom->next = top;
		top->prev = bottom;
		top->next = NULL;
		stack->top = next;
		stack->bottom = top;
	}
}

void			stack_rrotate(t_stack *stack)
{
	t_dlist *top;
	t_dlist *bottom;
	t_dlist	*prev;

	if (stack->len <= 1)
		return ;
	top = stack->top;
	bottom = stack->bottom;
	if (stack->len == 2)
		stack_rotate_two_el(stack, top, bottom);
	else
	{
		prev = bottom->prev;
		bottom->prev = NULL;
		bottom->next = top;
		top->prev = bottom;
		prev->next = NULL;
		stack->top = bottom;
		stack->bottom = prev;
	}
}
