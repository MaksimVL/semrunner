/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odrinkwa <odrinkwa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 18:48:15 by odrinkwa          #+#    #+#             */
/*   Updated: 2019/11/04 21:05:08 by odrinkwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "libft.h"
#include "lemin.h"
#include "mlx.h"
#include "fdf.h"
#include <stdio.h>

# define MAX_N 50

void			going_ants(t_lemin *l)
{
	int		ants_left;
	int		ant_counter;
	int		i;
	int		j;
	t_dlist	*curr;
	t_dlist *next;

	ants_left = l->number_of_ants;
	ant_counter = 0;
	ft_printf("ways:\n");
	print_intmatrix(l->ways, l->max_flow, l->count_rooms);

	while (ants_left != 0)
	{
		i = -1;
		while (++i < l->max_flow && ants_left != 0) // цикл по путям
		{
			j = -1;
			while (l->ways[i][++j] != l->start_room)
			{
				if (j == 0)
					{
						if (l->ants_on_ways[i][j] != 0)
						{
							l->ants_on_ways[i][j] = 0;
							ants_left--;
						}
					}
				else
				{
					l->ants_on_ways[i][j - 1] = l->ants_on_ways[i][j];
					l->ants_on_ways[i][j] = 0;
				}
			}
			// l->ants_on_ways[i][j - 1] = l->ants_on_ways[i][j];
			// l->ants_on_ways[i][j] = 0;
			if (ant_counter < l->number_of_ants)
			{
				ant_counter++;
				l->ants_on_ways[i][j - 1] = ant_counter;
			}
		}
		// ft_printf("ants_on_ways:\n");
		// print_intmatrix(l->ants_on_ways, l->max_flow, l->count_rooms);
		j = -1;
		while (++j < l->count_rooms)
		{
			i = -1;
			while (++i < l->max_flow)
			{
				if (l->ants_on_ways[i][j] != 0)
					ft_printf("L%d-%d ", l->ants_on_ways[i][j], l->ways[i][j]);
			}
		}
		ft_printf("\n");
	}
}

void			*set_cont_size_zero(t_dlist *list)
{
	if (list != NULL)
		list->content_size = 0;
	return (NULL);
}

void			*ft_dlistmap(t_dlist *list, void *f(t_dlist *))
{
	t_dlist *curr;

	curr = list;
	while (curr != NULL)
	{
		f(curr);
		curr = curr->next;
	}
	return (list);
}

int				main(int argc, char **argv)
{
	t_lemin		lemin;
	int			res;
	t_mlx		m;
	t_lemin_mlx	lm;

	lemin_init(&lemin);

	load_data(&lemin); //TODO проверка на чтение, полная очистка если ошибка
	set_rooms_number(&lemin);
	lemin.count_edges = ft_dlst_len(lemin.room_ways);
	edges_assign(&lemin);
	lemin_init_arrays(&lemin);
	lemin_fill_rooms(&lemin);
	lemin_fill_matrix2x(&lemin);
	lemin_init_ways(&lemin); // выделяем память под пути, в том числе под предыдущие пути
	//min_cost_f(&lemin);
	solve(&lemin);

//	print_intmatrix(lemin.flow, lemin.size_matrix, lemin.size_matrix);

	calculate_ways(&lemin);

	going_ants(&lemin);

	tmlx_initialize(&m, 1800, 1200);
	load_anthill(&m, &lemin);
	calc_parameter_maps(&m);
	make_map_points(&m);

	lm.m = &m;
	lm.lem = &lemin;
	tmlx_create_mlx(&m, "lemin");

	lemin_keyhook(-1, (void*)&lm);
	mlx_key_hook(m.win, lemin_keyhook, (void*)&lm);
	mlx_loop(m.ptr);
	lemin_destroy(&lemin);
}
