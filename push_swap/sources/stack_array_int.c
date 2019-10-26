/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_array_int.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odrinkwa <odrinkwa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 20:40:39 by odrinkwa          #+#    #+#             */
/*   Updated: 2019/10/26 14:55:41 by odrinkwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

static void		sort_array_int(t_stack *a)
{
	int i;
	int j;
	int tmp_int;

	i = 0;
	while (i < a->len_all - 1)
	{
		j = i + 1;
		while (j < a->len_all)
		{
			if (a->array_int[j] < a->array_int[i])
			{
				tmp_int = a->array_int[j];
				a->array_int[j] = a->array_int[i];
				a->array_int[i] = tmp_int;
			}
			j++;
		}
		i++;
	}
}

void			stack_fill_and_sort_array_int(t_stack *a)
{
	t_dlist		*curr;
	int			i;

	i = 0;
	curr = a->top;
	while (curr != NULL)
	{
		a->array_int[i] = int_content(curr);
		i++;
		curr = curr->next;
	}
	sort_array_int(a);
}

void			stack_set_max_len_el(t_stack *a)
{
	int		i;
	int		len_nbr;

	i = 0;
	while (i < a->len_all)
	{
		len_nbr = ft_nbrlen(a->array_int[i]);
		if (a->max_len_elem < len_nbr)
			a->max_len_elem = len_nbr;
		i++;
	}
}
