/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odrinkwa <odrinkwa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 18:48:15 by odrinkwa          #+#    #+#             */
/*   Updated: 2019/11/03 00:16:46 by odrinkwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "libft.h"
#include "lemin.h"
#include "mlx.h"
#include "fdf.h"

# define MAX_N 50

typedef struct	s_lemin_mlx
{
	t_mlx		*m;
	t_lemin		*lem;
}				t_lemin_mlx;

void			load_anthill(t_mlx *m, t_lemin *lem)
{
	int		i;

	m->map_points = (t_point*)malloc(sizeof(t_point) * lem->count_rooms);
	i = 0;
	while (i < lem->count_rooms)
	{
		m->map_points[i].x0 = lem->rooms[i]->x;
		m->map_points[i].y0 = lem->rooms[i]->y;
		m->map_points[i].z0 = lem->rooms[i]->z;
		i++;
	}
	m->quantity_points = lem->count_rooms;
}

void				calc_parameter_maps(t_mlx *m)
{
	int i;

	m->max_h = m->map_points[0].z0;
	m->min_h = m->map_points[0].z0;
	m->map_x = m->map_points[0].x0;
	m->map_y = m->map_points[0].y0;
	i = 0;
	while (i < m->quantity_points)
	{
		if (m->max_h < m->map_points[i].z0)
			m->max_h = m->map_points[i].z0;
		if (m->min_h > m->map_points[i].z0)
			m->min_h = m->map_points[i].z0;
		if (m->map_x < m->map_points[i].x0)
			m->map_x = m->map_points[i].x0;
		if (m->map_y < m->map_points[i].y0)
			m->map_y = m->map_points[i].y0;
		i++;
	}
}

void				put_names_rooms(t_mlx *m, t_lemin *l, int color)
{
	int i;
	t_point		point_draw_room;

	i = -1;
	while (++i < l->count_rooms)
	{
		point_draw_room = get_point_to_draw(m, i);
		mlx_string_put(m->ptr, m->win, point_draw_room.x + 10,
										point_draw_room.y - 10,
										color,
										((l->rooms)[i])->name);
	}


}

void	draw_anthill(t_lemin_mlx *lm, int not_black)
{
	int i;
	int n1;
	int n2;

	i = -1;
	while (++i < lm->lem->count_edges)
	{
		n1 = lm->lem->edges[i].from;
		n2 = lm->lem->edges[i].to;
		put_thickline(lm->m, get_point_to_draw(lm->m, n1),
						get_point_to_draw(lm->m, n2), not_black);

		// putline(lm->m, get_point_to_draw(lm->m, n1),
		// 				get_point_to_draw(lm->m, n2), not_black);
	}

	i = -1;
	while (++i < lm->m->quantity_points)
		put_thickcircle(lm->m, get_point_to_draw(lm->m, i), 6, not_black);
}

int		lemin_keyhook(int keycode, void *lm)
{
	draw_anthill((t_lemin_mlx*)lm, 0);
	keyhooks(keycode, ((t_lemin_mlx*)lm)->m);
	make_map_points(((t_lemin_mlx*)lm)->m);
	draw_anthill((t_lemin_mlx*)lm, 1);
	mlx_put_image_to_window(((t_mlx*)((t_lemin_mlx*)lm)->m)->ptr,
							((t_mlx*)((t_lemin_mlx*)lm)->m)->win,
							((t_mlx*)((t_lemin_mlx*)lm)->m)->main_im, 1, 0);
	main_legend(((t_lemin_mlx*)lm)->m);
	put_names_rooms(((t_lemin_mlx*)lm)->m, ((t_lemin_mlx*)lm)->lem, 0xFF0000);
	return (1);
}



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
	lemin_fill_matrix(&lemin);
	min_cost_f(&lemin);
	lemin_print_res(&lemin);

	print_intmatrix(lemin.flow, lemin.count_rooms, lemin.count_rooms);

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
