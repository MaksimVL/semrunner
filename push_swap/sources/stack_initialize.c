/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_initialize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odrinkwa <odrinkwa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 19:37:47 by odrinkwa          #+#    #+#             */
/*   Updated: 2019/10/25 00:11:30 by odrinkwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

void			stack_initialize(t_stack *stack)
{
	stack->len = 0;
	stack->top = NULL;
	stack->bottom = NULL;
	stack->pos_min = -1;
	stack->pos_max = -1;
	stack->array_int = NULL;
	stack->coef_star_size = 1;
	stack->max_len_elem = 0;
	stack->count_operations = 0;
	stack->flag = 0;
}

void			stack_del(t_stack *stack)
{
	if (stack->len != 0)
		ft_dlstdel(&(stack->top), del_int);
	if (stack->array_int != NULL)
		ft_memdel((void**)&(stack->array_int));
	stack->len = 0;
	stack->bottom = NULL;
}
