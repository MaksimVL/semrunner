/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odrinkwa <odrinkwa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/26 14:39:46 by odrinkwa          #+#    #+#             */
/*   Updated: 2019/10/26 14:39:48 by odrinkwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

int				check(t_stack *a)
{
	if (a->len == 0 || find_repeat_elements(a) == 1)
		return (0);
	a->len_all = a->len;
	if (!(a->array_int = (int*)ft_memalloc(sizeof(int) * a->len_all)))
		return (0);
	stack_fill_and_sort_array_int(a);
	stack_set_max_len_el(a);
	return (1);
}

void			sort(t_stack *a, t_stack *b)
{
	if (a->flag == 1)
	{
		a->count_operations--;
		write_operation("start condition", a, b);
	}
	stack_sort(a, b);
	if (a->flag != 0)
		ft_printf("result: count of elements: %d, count of operations: %d\n",
				a->len_all, a->count_operations);
}

int				check_sort_stack(t_stack *a)
{
	t_dlist		*curr;

	if (a->len != a->len_all)
		return (0);
	if (a->len == 1)
		return (1);
	curr = a->top;
	while (curr->next != NULL)
	{
		if (int_content(curr) > int_content(curr->next))
			return (0);
		curr = curr->next;
	}
	return (1);
}
