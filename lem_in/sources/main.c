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

int				main(int argc, char **argv)
{
	t_lemin		lemin;
	int			res;
	t_mlx		m;
	t_lemin_mlx	lm;

	lemin_init(&lemin);

	load_data(&lemin); //TODO проверка на чтение, полная очистка если ошибка
	lemin.number_of_ants = 1;
	set_rooms_number(&lemin);
	lemin.count_edges = ft_dlst_len(lemin.room_ways);
	edges_assign(&lemin);
	lemin_init_arrays(&lemin);
	print_all_rooms_property(lemin.list_rooms);
	print_all_links(lemin.room_ways);
	print_all_edges(&lemin);

	lemin_fill_rooms(&lemin);
	//lemin_fill_matrix(&lemin);
	lemin_fill_matrix2x(&lemin);
	print_intmatrix(lemin.capacity, lemin.size_matrix, lemin.size_matrix);
	min_cost_f(&lemin);
	lemin_print_res(&lemin);

	print_intmatrix(lemin.flow, lemin.size_matrix, lemin.size_matrix);

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
