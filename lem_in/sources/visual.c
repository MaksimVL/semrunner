#include "libft.h"
#include "lemin.h"
#include "mlx.h"
#include "fdf.h"

void			load_anthill(t_mlx *m, t_lemin *lem)
{
	int		i;

	m->map_points = (t_point*)malloc(sizeof(t_point) * (lem->count_rooms + lem->number_of_ants));
	i = 0;
	while (i < lem->count_rooms)
	{
		m->map_points[i].x0 = lem->rooms[i]->x;
		m->map_points[i].y0 = lem->rooms[i]->y;
		if (lem->rooms[i]->z == NO_DEFINE)
			m->map_points[i].z0 = 0;
		else
			m->map_points[i].z0 = lem->rooms[i]->z;
		i++;
	}
	while (i < lem->count_rooms + lem->number_of_ants)
	{
		m->map_points[i].x0 = lem->rooms[lem->start_room]->x;
		m->map_points[i].y0 = lem->rooms[lem->start_room]->y;
		if (lem->rooms[lem->start_room]->z == NO_DEFINE)
			m->map_points[i].z0 = 0;
		else
			m->map_points[i].z0 = lem->rooms[lem->start_room]->z;
		i++;
	}
	m->quantity_points = lem->count_rooms + lem->number_of_ants;
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

void				put_num_ants(t_mlx *m, t_lemin *l, int color)
{
	int i;
	t_point		point_draw_room;

	i = -1;
	while (++i < l->number_of_ants)
	{
		point_draw_room = get_point_to_draw(m, i + l->count_rooms);
		mlx_string_put(m->ptr, m->win, point_draw_room.x - 20,
										point_draw_room.y,
										color,
										ft_itoa(i));
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

void			set_all_ants_to_start(t_mlx *m, t_lemin *lem)
{
	int		i;

	i = lem->count_rooms;
	while (i < lem->count_rooms + lem->number_of_ants)
	{
		m->map_points[i].x0 = lem->rooms[lem->start_room]->x;
		m->map_points[i].y0 = lem->rooms[lem->start_room]->y;
		if (lem->rooms[lem->start_room]->z == NO_DEFINE)
			m->map_points[i].z0 = 0;
		else
			m->map_points[i].z0 = lem->rooms[lem->start_room]->z;
		i++;
	}
}

void			set_ants_to_rooms(t_mlx *m, t_lemin *lem)
{
	int i;
	t_dlist *curr;
	t_ant_move *am;

	i = -1;
	while (++i < lem->number_of_ants)
	{
		curr = lem->ants_moving[i];
		while (curr != NULL)
		{
			am = curr->content;
			if (am->step == lem->current_step)
			{
				m->map_points[i + lem->count_rooms].x0 = lem->rooms[am->to]->x;
				m->map_points[i + lem->count_rooms].y0 = lem->rooms[am->to]->y;
				if (lem->rooms[am->to]->z == NO_DEFINE)
					m->map_points[i + lem->count_rooms].z0 = 0;
				else
					m->map_points[i + lem->count_rooms].z0 = lem->rooms[am->to]->z;
			}
			curr = curr->next;
		}
	}

}

int		keyhook_move_ants(int keycode, t_mlx *m, t_lemin *l)
{
// 43 = <, 47 = >
	if (keycode == 7)
		l->current_step = 0;
	if (keycode == 47)
		l->current_step += 1;
	// if (keycode == 47)
	// 	l->current_step = l->current_step == 0 ? 0 : l->current_step - 1;
	if (l->current_step == 0)
		set_all_ants_to_start(m, l);
	else
		set_ants_to_rooms(m, l);

}

int		lemin_keyhook(int keycode, void *lm)
{
	ft_printf("%d\n", keycode);
	draw_anthill((t_lemin_mlx*)lm, 0);
	keyhooks(keycode, ((t_lemin_mlx*)lm)->m);
	keyhook_move_ants(keycode, ((t_lemin_mlx*)lm)->m, ((t_lemin_mlx*)lm)->lem);
	make_map_points(((t_lemin_mlx*)lm)->m);
	draw_anthill((t_lemin_mlx*)lm, 1);
	mlx_put_image_to_window(((t_mlx*)((t_lemin_mlx*)lm)->m)->ptr,
							((t_mlx*)((t_lemin_mlx*)lm)->m)->win,
							((t_mlx*)((t_lemin_mlx*)lm)->m)->main_im, 1, 0);
	main_legend(((t_lemin_mlx*)lm)->m);
	put_names_rooms(((t_lemin_mlx*)lm)->m, ((t_lemin_mlx*)lm)->lem, 0xFF0000);
	put_num_ants(((t_lemin_mlx*)lm)->m, ((t_lemin_mlx*)lm)->lem, 0xAAAAFF);
	return (1);
}
