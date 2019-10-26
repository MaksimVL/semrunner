/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_print_basic.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odrinkwa <odrinkwa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 19:58:37 by odrinkwa          #+#    #+#             */
/*   Updated: 2019/10/26 14:41:02 by odrinkwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void		stack_print_aux(t_stack *stack)
{
	t_dlist		*tmp;

	ft_printf("--- start info stack ---\n");
	tmp = NULL;
	if (stack->top == NULL)
	{
		ft_printf("len = %d, top = %p, bottom = %p\n", stack->len,
				stack->top, stack->bottom);
		ft_printf("---  end info stack  ---\n");
		return ;
	}
	tmp = stack->top;
	ft_printf("len = %d, top = %d, bottom = %d\n", stack->len,
											*(int*)(stack->top->content),
											*(int*)(stack->bottom->content));
	while (tmp)
	{
		ft_printf("%d\n", *(int*)(tmp->content));
		tmp = tmp->next;
	}
	ft_printf("---  end info stack  ---\n");
}

void			print_stacks(t_stack *a, t_stack *b)
{
	ft_printf("-------------- start print stacks ----------\n");
	ft_printf("'''stack a:\n");
	stack_print_aux(a);
	ft_printf("'''stack b:\n");
	stack_print_aux(b);
	ft_printf("--------------  end print stacks  ----------\n");
}
