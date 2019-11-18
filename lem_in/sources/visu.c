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

void			open_file_load_data(t_lemin *lemin, int argc, char **argv)
{
	int		fd;

	if (argc == 1)
		load_data(lemin, 0, 1);
	else if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		load_data(lemin, fd, 1);
		close(fd);
	}
	else
		finish_prog(lemin, -1, -1, NULL);
}

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

void set_num_rooms_to_ant_moves(t_lemin *l)
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
			am->to = room_number(l, am->to_name);
			curr = curr->next;
		}
	}
}

void			correct_color_ants(t_lemin *l, t_mlx *m)
{
	int i;
	int color;

	color = 0xFF;
	i = l->count_rooms;
	while (i < m->quantity_points)
	{
		m->map_points[i].color = color;
		i++;
	}
}

int				ant_move(t_lemin_mlx *lm)
{
	t_mlx	*m = lm->m;
	t_lemin *l = lm->lem;
	double step_x;
	double step_y;
	int i;
	t_ant_draw_move *ant_move;

	put_all(lm);

	i = -1;
	while (++i < lm->lem->number_of_ants)
	{
		ant_move = &(lm->ants_move[i]);
		if (ant_move->start_room == ant_move->end_room)
		{
			ant_move->curr = get_point_to_draw(lm->m, ant_move->start_room);
		 	continue ;
		}
		ant_move->start = get_point_to_draw(lm->m, ant_move->start_room);
		ant_move->end = get_point_to_draw(lm->m, ant_move->end_room);
		step_x = (double)(ant_move->end.x - ant_move->start.x) / 10.0;
		step_y = (double)(ant_move->end.y - ant_move->start.y) / 10.0;
		ant_move->curr.x = ant_move->start.x + step_x * lm->step_counter;
		ant_move->curr.y = ant_move->start.y + step_y * lm->step_counter;
		if (lm->step_counter >= 10)
		{
			ant_move->start = ant_move->end;
			ant_move->start_room = ant_move->end_room;
		}
	}
	if (lm->step_counter < 10)
		lm->step_counter++;
	usleep(2000);
	draw_ants(lm);
	return (1);
}

void			create_ant_draw_move(t_lemin_mlx *lm)
{
	int		i;

	lm->ants_move = (t_ant_draw_move*)ft_memalloc(sizeof(t_ant_draw_move) * lm->lem->number_of_ants);
	i = -1;
	while (++i < lm->lem->number_of_ants)
	{
		lm->ants_move[i].start_room = lm->lem->start_room;
		lm->ants_move[i].end_room = lm->lem->start_room;
	}
}

void			set_flow_anthill(t_lemin *l)
{
	int i;
	int j;
	t_dlist *curr;
	t_ant_move *am;
	t_ant_move *am_next;

	i = -1;
	while (++i < l->number_of_ants)
	{
		curr = l->ants_moving[i];
		am = curr->content;
		j = -1;
		while (++j < l->count_edges)
			if (l->edges[j].from == l->start_room && l->edges[j].to == am->to)
				l->edges[j].flow = 1;

		while (curr != NULL && curr->next != NULL)
		{
			am = curr->content;
			am_next = curr->next->content;
			j = -1;
			while (++j < l->count_edges)
				if (l->edges[j].from == am->to && l->edges[j].to == am_next->to)
					l->edges[j].flow = 1;
			curr = curr->next;
		}
	}
}

int				main(int argc, char **argv)
{
	t_lemin		lemin;
	t_mlx		m;
	t_lemin_mlx	lm;

	lemin_init(&lemin);
	errno = 0;
	open_file_load_data(&lemin, argc, argv);
	prepare_data(&lemin);

	// solve(&lemin);
	print_anthill(&lemin);
	// going_ants(&lemin);
	set_num_rooms_to_ant_moves(&lemin);
	//print_ants_moves(&lemin);
	tmlx_initialize(&m, 1800, 1200);
	load_anthill(&m, &lemin);
	calc_parameter_maps(&m);
	make_map_points(&m);
	correct_color(&m);

	//correct_color_ants(&lemin, &m);

	lm.m = &m;
	lm.lem = &lemin;

	create_ant_draw_move(&lm);

	tmlx_create_mlx(&m, "lemin");

	int x = 30;
	int y = 30;
	if (lemin.count_rooms < 10)
		lm.size_ant_im = 40;
	else if (lemin.count_rooms < 50)
		lm.size_ant_im = 30;
	else
		lm.size_ant_im = 20;
	if (lm.size_ant_im == 20)
		lm.ant_im = mlx_xpm_file_to_image(m.ptr, "white_ant_20_20.xpm", &(lm.size_ant_im), &(lm.size_ant_im));
	else if (lm.size_ant_im == 30)
		lm.ant_im = mlx_xpm_file_to_image(m.ptr, "white_ant_30_30.xpm", &(lm.size_ant_im), &(lm.size_ant_im));
	else
		lm.ant_im = mlx_xpm_file_to_image(m.ptr, "white_ant_40_40.xpm", &(lm.size_ant_im), &(lm.size_ant_im));

	set_flow_anthill(lm.lem);
	// if (!(lm.ant_im = mlx_new_image(m.ptr, 49, 48)))
	// 	tmlx_destroy(&m, -1);

	lm.start_move.x = 50;
	lm.start_move.y = 50;
	lm.finish_move.x = 500;
	lm.finish_move.y = 50;

	lemin_keyhook(-1, (void*)&lm);
	mlx_key_hook(m.win, lemin_keyhook, (void*)&lm);
	mlx_loop_hook(m.ptr, ant_move, (void*)&lm);
	mlx_loop(m.ptr);
	finish_prog(&lemin, 0, -1, NULL);
}
