/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odrinkwa <odrinkwa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 19:32:00 by odrinkwa          #+#    #+#             */
/*   Updated: 2019/10/25 00:26:40 by odrinkwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

void			write_operation(char *str, t_stack *a, t_stack *b)
{
	a->count_operations++;
	if (a->flag == 1)
	{
		ft_printf("operation: %s, count_operation: %d\n", str, a->count_operations);
		pretty_print_stack(a, b);
	}
	else if (a->flag == 2)
	{
		HOME();
		CLRSCR();
		pretty_print_stack(a, b);
		usleep(200000);
	}
	else if (a->flag_checker == 0)
		ft_printf("%s\n", str);
}

void			sa(t_stack *a, t_stack *b)
{
	if (b == NULL && b != NULL)
		return ;
	stack_swap(a);
	write_operation("sa", a, b);
}

void			sb(t_stack *a, t_stack *b)
{
	if (a == NULL && a != NULL)
		return ;
	stack_swap(b);
	write_operation("sb", a, b);
}
