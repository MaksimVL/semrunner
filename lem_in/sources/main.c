/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odrinkwa <odrinkwa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 18:48:15 by odrinkwa          #+#    #+#             */
/*   Updated: 2019/11/16 20:18:45 by odrinkwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "libft.h"
#include "lemin.h"
#include "mlx.h"
#include "fdf.h"
#include "float.h"
#include <stdio.h>

void			print_anthill(t_lemin *l)
{
	t_dlist		*curr;
	t_room		*room;

	curr = l->list_rooms;
	while (curr != NULL)
	{
		room = curr->content;
		if (room->start_end_flag == 1)
			ft_printf("##start\n");
		else if (room->start_end_flag == 2)
			ft_printf("##end\n");
		ft_printf("%s %d %d", room->name, room->x, room->y);
		if (room->z != NO_DEFINE)
			ft_printf(" %d", room->z);
		ft_printf("\n");
		curr = curr->next;
	}
}

int				main(int argc, char **argv)
{
	t_lemin		lemin;
	// t_mlx		m;
	// t_lemin_mlx	lm;

	lemin_init(&lemin);

	ft_printf("start load data...");
	if (argc == 2)
		load_data(&lemin, argv[1]); //TODO проверка на чтение, полная очистка если ошибка
	else
		exit(0);
	prepare_data(&lemin);
	solve(&lemin);
	print_anthill(&lemin);
	going_ants(&lemin);
	// tmlx_initialize(&m, 1800, 1200);
	// load_anthill(&m, &lemin);
	// calc_parameter_maps(&m);
	// make_map_points(&m);

	// lm.m = &m;
	// lm.lem = &lemin;

	// tmlx_create_mlx(&m, "lemin");

	// lemin_keyhook(-1, (void*)&lm);
	// mlx_key_hook(m.win, lemin_keyhook, (void*)&lm);
	// mlx_loop_hook(m.ptr, test_func, (void*)&lm);
	// mlx_loop(m.ptr);
	finish_prog(&lemin, 0, -1, NULL);
}
