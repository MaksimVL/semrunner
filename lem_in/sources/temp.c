// void			set_all_ants_to_start(t_mlx *m, t_lemin *lem)
// {
// 	int		i;

// 	i = lem->count_rooms;
// 	while (i < lem->count_rooms + lem->number_of_ants)
// 	{
// 		m->map_points[i].x0 = lem->rooms[lem->start_room]->x;
// 		m->map_points[i].y0 = lem->rooms[lem->start_room]->y;
// 		if (lem->rooms[lem->start_room]->z == NO_DEFINE)
// 			m->map_points[i].z0 = 0;
// 		else
// 			m->map_points[i].z0 = lem->rooms[lem->start_room]->z;
// 		i++;
// 	}
// }

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


void	put_ant(t_lemin_mlx *lm, int x, int y)
{
	mlx_put_image_to_window(((t_mlx*)((t_lemin_mlx*)lm)->m)->ptr,
							((t_mlx*)((t_lemin_mlx*)lm)->m)->win,
							((t_lemin_mlx*)lm)->ant_im, x, y);
}
