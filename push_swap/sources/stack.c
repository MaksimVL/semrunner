/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odrinkwa <odrinkwa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 19:29:47 by odrinkwa          #+#    #+#             */
/*   Updated: 2019/10/24 20:25:46 by odrinkwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

void			*stack_push(t_stack *stack, int a)
{
	t_dlist		*temp;

	temp = ft_dlstnew(&a, sizeof(a));
	if (temp == NULL)
		return (NULL);
	if (stack->top == NULL)
	{
		stack->len = 1;
		stack->top = temp;
		stack->bottom = temp;
	}
	else
	{
		ft_dlst_addback(&(stack->bottom), temp);
		stack->bottom = temp;
		stack->len += 1;
	}
	stack->pos_max = -1;
	stack->pos_min = -1;
	return (stack);
}

void			stack_swap(t_stack *stack)
{
	t_dlist	*top;
	t_dlist *next;
	t_dlist *nnext;

	if (stack->len == 0 || stack->len == 1)
		return ;
	top = stack->top;
	next = stack->top->next;
	nnext = next->next;
	next->prev = NULL;
	next->next = top;
	top->prev = next;
	top->next = nnext;
	if (nnext != NULL)
		nnext->prev = top;
	stack->top = next;
	if (stack->len == 2)
		stack->bottom = top;
}

static void		stack_push_ab_aux(t_stack *a, t_stack *b, t_dlist *nextb)
{
	if (b->len == 1)
	{
		b->top = NULL;
		b->bottom = NULL;
	}
	else
	{
		nextb->prev = NULL;
		b->top = nextb;
	}
	b->len--;
	a->pos_max = -1;
	a->pos_min = -1;
	b->pos_max = -1;
	b->pos_min = -1;
}

void			stack_push_ab(t_stack *a, t_stack *b)
{
	t_dlist *topa;
	t_dlist *topb;
	t_dlist *nextb;

	if (b->len == 0)
		return ;
	topa = a->top;
	topb = b->top;
	nextb = topb->next;
	topb->next = topa;
	if (a->len != 0)
		topa->prev = topb;
	else
		a->bottom = topb;
	a->len++;
	a->top = topb;
	stack_push_ab_aux(a, b, nextb);
}
