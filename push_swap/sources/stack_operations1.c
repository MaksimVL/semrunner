/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odrinkwa <odrinkwa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 19:34:25 by odrinkwa          #+#    #+#             */
/*   Updated: 2019/10/24 19:34:28 by odrinkwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "dlist.h"
#include "push_swap.h"

void			pb(t_stack *a, t_stack *b)
{
	stack_push_ab(b, a);
	write_operation("pb", a, b);
}

void			ra(t_stack *a, t_stack *b)
{
	if (b == NULL && b != NULL)
		return ;
	stack_rotate(a);
	write_operation("ra", a, b);
}

void			rb(t_stack *a, t_stack *b)
{
	if (a == NULL && a != NULL)
		return ;
	stack_rotate(b);
	write_operation("rb", a, b);
}

void			rr(t_stack *a, t_stack *b)
{
	stack_rotate(a);
	stack_rotate(b);
	write_operation("rr", a, b);
}
