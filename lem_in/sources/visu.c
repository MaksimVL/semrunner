/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odrinkwa <odrinkwa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 18:48:15 by odrinkwa          #+#    #+#             */
/*   Updated: 2019/11/17 02:03:06 by odrinkwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "libft.h"
#include "lemin.h"
#include "mlx.h"
#include "fdf.h"
#include "float.h"
#include <stdio.h>

void			print_ants_moves(t_lemin *l)
{
	int i;
	t_dlist *curr;
	t_ant_move *am;

	i = -1;
	while (++i < l->number_of_ants)
	{
		curr = l->ants_moving[i];
		while (curr != NULL)
		{
			am = curr->content;
			ft_printf("ant=%d, step=%d to_name=%s to=%d\n", i, am->step, am->to_name, am->to);
			curr = curr->next;
		}
	}
}

void			set_start_conditions(t_lemin_mlx *lm)
{
	if (lm->lem->count_rooms > 100)
	{
		lm->show_room_numbers = 0;
		lm->show_interm_rooms = 0;
	}
}

int				main(int argc, char **argv)
{
	t_lemin		lemin;
	t_mlx		m;
	t_lemin_mlx	lm;

	lemin_init(&lemin);
	tmlx_initialize(&m, 1400, 1000);
	tlemin_mlx_initialize(&lm);
	errno = 0;
	open_file_load_data(&lemin, argc, argv);
	prepare_data(&lemin);
	//print_anthill(&lemin);  // TODO убрать
	set_num_rooms_to_ant_moves(&lemin);
	load_anthill_to_map_points(&m, &lemin);
	calc_parameter_maps(&m);
	make_map_points(&m);
	correct_color(&m);
	lm.m = &m;
	lm.lem = &lemin;
	create_ant_draw_move(&lm);
	if (tmlx_create_mlx(&m, "lemin") == 0)
	 	finish_all(&lm, -1);
	start_load_ant_im(&lm);
	set_start_conditions(&lm);
	//print_ants_moves(lm.lem);
	set_flow_anthill(lm.lem);

	// int i;
	// i = -1;
	// while (++i < lemin.count_edges)
	// {
	// 	ft_printf("edg %d: from: %d, to %d, flow %d\n", i, lemin.edges[i].from, lemin.edges[i].to, lemin.edges[i].flow);
	// }

	lemin_keyhook(-1, (void*)&lm);
	mlx_key_hook(m.win, lemin_keyhook, (void*)&lm);
	mlx_loop_hook(m.ptr, loop_ants_move, (void*)&lm);
	mlx_loop(m.ptr);

	finish_prog(&lemin, 0, -1, NULL);
}
