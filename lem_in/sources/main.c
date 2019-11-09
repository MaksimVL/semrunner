/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odrinkwa <odrinkwa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 18:48:15 by odrinkwa          #+#    #+#             */
/*   Updated: 2019/11/10 00:33:08 by odrinkwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "libft.h"
#include "lemin.h"
#include "mlx.h"
#include "fdf.h"
#include "float.h"
#include <stdio.h>

# define MAX_N 50

void			going_ants(t_lemin *l)
{
	int		ants_left;
	int		ant_counter;
	int		count_all_ways;
	int		i;
	int		j;
	t_dlist	*curr;
	t_dlist *next;
	int		max_len;
	int		flow_base;

	count_all_ways = l->count_ways;
	ants_left = l->number_of_ants;
	ant_counter = 0;
	 ft_printf("count ways: %d\n", count_all_ways);
	// print_intmatrix(l->ways, l->max_flow, l->count_rooms);

	while (ants_left != 0)
	{
		// чекаем перед запуском цикла по путям - уменьшаем количество путей или нет.
		if (l->count_ways > 1)
		{
			max_len = max_int_array(l->way_length, l->count_ways);
			// вычисляем базовый поток через оставшиеся пути
			flow_base = count_flow_base(l->way_length, l->count_ways, max_len);
			if (flow_base > l->number_of_ants - ant_counter) // если баз поток больше оставшихся муравьев, то уменьшаем количество путей.
			{
				l->count_ways--;
				while (l->count_ways > 1)
				{
					max_len = max_int_array(l->way_length, l->count_ways);
					flow_base = count_flow_base(l->way_length, l->count_ways, max_len);
					if (flow_base < l->number_of_ants - ant_counter)
						break ;
					l->count_ways--;
				}
			}
		}

		i = -1;
		while (++i < count_all_ways && ants_left != 0) // цикл по путям
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
			// запускаем нового муравья в i-й путь
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
			while (++i < count_all_ways)
			{
				if (l->ants_on_ways[i][j] != 0)
					ft_printf("L%d-%s ", l->ants_on_ways[i][j],
						(l->rooms[l->ways[i][j]])->name);
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

void			test_func(void *lm)
{
	int		i;


	// i = 1;
	// ft_printf("fuck\n");
	// usleep(20000);
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

//	calculate_ways(&lemin);


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
	mlx_loop_hook(m.ptr, test_func, (void*)&lm);
	mlx_loop(m.ptr);
	lemin_destroy(&lemin);

}
