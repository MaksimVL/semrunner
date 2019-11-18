#include "libft.h"
#include "lemin.h"
#include "mlx.h"
#include "fdf.h"

void			put_main_image(t_lemin_mlx *lm)
{
	mlx_put_image_to_window(((t_mlx*)((t_lemin_mlx*)lm)->m)->ptr,
						((t_mlx*)((t_lemin_mlx*)lm)->m)->win,
						((t_mlx*)((t_lemin_mlx*)lm)->m)->main_im, 0, 0);
}

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

void	draw_anthill(t_lemin_mlx *lm, int not_black)
{
	int i;
	int n1;
	int n2;
	int ang_proj;
	int proj_type;

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
	while (++i < lm->lem->count_rooms)
		put_thickcircle(lm->m, get_point_to_draw(lm->m, i), 6, not_black);
}



void			set_ants_to_rooms(t_lemin_mlx *lm, t_mlx *m, t_lemin *lem)
{
	int i;
	t_dlist *curr;
	t_ant_move *am;
	int start_step = -1;
	int end_step = -1;

	i = -1;
	while (++i < lem->number_of_ants)
	{
		curr = lem->ants_moving[i];
		if (curr != NULL)
			start_step = ((t_ant_move*)(curr->content))->step;
		while (curr != NULL)
		{
			am = curr->content;
			if (am->step == lem->current_step)
			{
				lm->ants_move[i].start_room = lm->ants_move[i].end_room;
				lm->ants_move[i].start = get_point_to_draw(m, lm->ants_move[i].start_room);
				lm->ants_move[i].end_room = am->to;
				lm->ants_move[i].end = get_point_to_draw(m, am->to);
				lm->ants_move[i].curr = get_point_to_draw(m, lm->ants_move[i].start_room);
				//ft_printf("i=%d, step=%d, to=%d\n, start.xy=%d %d, end.xy=%d %d", i, am->step, am->to, am->start.x, am->start.y, am->end.x, am->end.ym);
			}
			end_step = ((t_ant_move*)(curr->content))->step;
			curr = curr->next;
		}
		if (lem->current_step < start_step)
		{
			lm->ants_move[i].start_room = lem->start_room;
			lm->ants_move[i].end_room = lem->start_room;
		}
		else if (lem->current_step > end_step)
		{
			lm->ants_move[i].start_room = lem->end_room;
			lm->ants_move[i].end_room = lem->end_room;
		}
	}
	lm->step_counter = 0;

}

// void	draw_ants(t_lemin_mlx *lm)
// {
// 	int		x;
// 	int		y;
// 	t_point		p;
// 	int			i;

// 	i = lm->lem->count_rooms;
// 	while (++i < lm->m->quantity_points)
// 	{
// 		p = get_point_to_draw(lm->m, i);
// 		put_ant(lm, p.x, p.y);
// 	}
// }

int		keyhook_move_ants(int keycode, t_lemin_mlx *lm, t_mlx *m, t_lemin *l)
{
	if (keycode == 7)
		l->current_step = 0;
	if (keycode == 47)
		l->current_step += 1;
	set_ants_to_rooms(lm, m, l);
	return (1);
}

void	draw_ant(t_lemin_mlx *lm, int i, t_point p)
{

	i = 0;
	mlx_put_image_to_window(((t_mlx*)((t_lemin_mlx*)lm)->m)->ptr,
							((t_mlx*)((t_lemin_mlx*)lm)->m)->win,
							((t_lemin_mlx*)lm)->ant_im, p.x, p.y);
}

void	put_all(void *lm)
{
	put_main_image(lm);
	//draw_ants(lm);
	main_legend(((t_lemin_mlx*)lm)->m);
	put_names_rooms(((t_lemin_mlx*)lm)->m, ((t_lemin_mlx*)lm)->lem, 0xFF0000);
	//put_num_ants(((t_lemin_mlx*)lm)->m, ((t_lemin_mlx*)lm)->lem, 0xAAAAFF);
}


void	set_ants_to_start(t_lemin_mlx *lm)
{
	int		i;

	i = -1;
	while (++i < lm->lem->number_of_ants)
	{
		lm->ants_move[i].start_room = lm->lem->start_room;
		lm->ants_move[i].end_room = lm->lem->start_room;
		lm->ants_move[i].start = get_point_to_draw(lm->m, lm->lem->start_room);
		lm->ants_move[i].end = get_point_to_draw(lm->m, lm->lem->start_room);
		lm->ants_move[i].curr = get_point_to_draw(lm->m, lm->lem->start_room);
	}
}

void	draw_ants(t_lemin_mlx *lm)
{
	int		i;
	int		count_in_start;
	int		count_in_end;

	count_in_start = 0;
	count_in_end = 0;
	i = -1;
	while (++i < lm->lem->number_of_ants)
	{
		if (lm->ants_move[i].start_room == lm->lem->start_room &&
			lm->ants_move[i].end_room == lm->lem->start_room)
		{
			if (count_in_start == 0)
				count_in_start++;
			else
				continue ;
		}
		if (lm->ants_move[i].start_room == lm->lem->end_room &&
			lm->ants_move[i].end_room == lm->lem->end_room)
		{
			if (count_in_end == 0)
				count_in_end++;
			else
				continue ;
		}
		draw_ant(lm, i, lm->ants_move[i].curr);
	}
}

int		lemin_keyhook(int keycode, void *lm)
{
	t_lemin_mlx *lm1 = lm;

	ft_printf("%d\n", keycode);
	if (keycode == 18 || keycode == 19 || keycode == 20 || keycode == 21 || keycode == 23 || keycode == 7)
		draw_anthill((t_lemin_mlx*)lm, 0);
	if (keycode == -1 || keyhooks(keycode, ((t_lemin_mlx*)lm)->m))
	{
		draw_anthill((t_lemin_mlx*)lm, 0);
		make_map_points(((t_lemin_mlx*)lm)->m);
		draw_anthill((t_lemin_mlx*)lm, 1);
		mlx_put_image_to_window(((t_mlx*)((t_lemin_mlx*)lm)->m)->ptr,
							((t_mlx*)((t_lemin_mlx*)lm)->m)->win,
							((t_mlx*)((t_lemin_mlx*)lm)->m)->main_im, 0, 0);
		main_legend(((t_lemin_mlx*)lm)->m);
		put_names_rooms(((t_lemin_mlx*)lm)->m, ((t_lemin_mlx*)lm)->lem, 0xFF0000);
		ft_printf("draw_anthill\n");
	}
	keyhook_move_ants(keycode, ((t_lemin_mlx*)lm), ((t_lemin_mlx*)lm)->m, ((t_lemin_mlx*)lm)->lem);

	if (keycode == -1 || lm1->lem->current_step == 0)
		set_ants_to_start((t_lemin_mlx*)lm);
	//set_ants_to_rooms(((t_lemin_mlx*)lm), ((t_lemin_mlx*)lm)->m, ((t_lemin_mlx*)lm)->lem);
	//main_legend(((t_lemin_mlx*)lm)->m);
	//lm1->curr_pos = lm1->start_move;
	return (1);
}
