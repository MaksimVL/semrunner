#include "libft.h"
#include "lemin.h"
#include "mlx.h"
#include "fdf.h"

void			load_anthill_to_map_points(t_mlx *m, t_lemin *lem)
{
	int		i;

	if (!(m->map_points = (t_point*)ft_memalloc(sizeof(t_point) * lem->count_rooms)))
		finish_prog(lem, -1, -1, NULL);
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
	m->quantity_points = lem->count_rooms;
}

void			set_ants_to_start(t_lemin_mlx *lm)
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
