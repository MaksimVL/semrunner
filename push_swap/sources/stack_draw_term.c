/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_draw_term.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odrinkwa <odrinkwa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 19:56:33 by odrinkwa          #+#    #+#             */
/*   Updated: 2019/10/25 00:25:14 by odrinkwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void		print_stars(int count)
{
	while(count-- > 0)
		ft_printf("*");
}

static int		get_size_stack_elem(t_stack *a, t_dlist *curr_el)
{
	int		i;

	i = 0;
	while (i < a->len_all)
	{
		if (a->array_int[i] == int_content(curr_el))
			return ((i + 1) / a->coef_star_size);
		i++;
	}
	return (0);
}

static void		pretty_print_aux(t_stack *a, t_dlist *curr_a,
								t_dlist *curr_b, int width)
{
	int i;

	i = 1;
	while (curr_a != NULL || curr_b != NULL)
	{
		SETCOLOR(F_RED);
		if (curr_a != NULL)
		{
			ft_printf("% *d ", a->max_len_elem + 2, int_content(curr_a));
			print_stars(get_size_stack_elem(a, curr_a));
			curr_a = curr_a->next;
		}
		GOTOINLINE(width);
		SETCOLOR(F_GREEN);
		if (curr_b != NULL)
		{
			ft_printf("% *d ", a->max_len_elem + 2, int_content(curr_b));
			print_stars(get_size_stack_elem(a, curr_b));
			curr_b = curr_b->next;
		}
		ft_printf("\n");
		i++;
	}
}

void			pretty_print_stack(t_stack *a, t_stack *b)
{
	int			width;
	t_dlist		*curr_a;
	t_dlist		*curr_b;

	curr_a = (a != NULL) ? a->top : NULL;
	curr_b = (b != NULL) ? b->top : NULL;
	width = a->len_all + 15;
	pretty_print_aux(a, curr_a, curr_b, width);
	RESET_COLOR();
}



