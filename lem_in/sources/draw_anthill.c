#include "libft.h"
#include "lemin.h"
#include "mlx.h"

static void		draw_ways (t_lemin_mlx *lm, int not_black)
{
	int i;
	int n1;
	int n2;

	i = -1;
	while (++i < lm->lem->count_edges)
	{
		n1 = lm->lem->edges[i].from;
		n2 = lm->lem->edges[i].to;
		if (lm->lem->edges[i].flow == 1)
			put_thickline(lm->m, get_point_to_draw(lm->m, n1),
						get_point_to_draw(lm->m, n2), not_black);
		else
		{
			if (lm->show_not_use_edges == 1)
				putline(lm->m, get_point_to_draw(lm->m, n1),
						get_point_to_draw(lm->m, n2), not_black);
		}
	}
}

static void		draw_start_end_room(t_lemin_mlx *lm, int not_black, int color_frontier, int i)
{
	t_point p;
	p = get_point_to_draw(lm->m, i);
	p.color = color_frontier;
	putbox(lm->m, get_point_to_draw(lm->m, i), lm->size_ant_im + 2, not_black);
	putbox(lm->m, get_point_to_draw(lm->m, i), lm->size_ant_im + 4, not_black);
	putbox(lm->m, p, lm->size_ant_im + 6, not_black);
	putbox(lm->m, p, lm->size_ant_im + 8, not_black);
	put_full_box(lm->m, get_point_to_draw(lm->m, i), lm->size_ant_im, 0);
}

draw_intermed_room_aux(t_lemin_mlx *lm, int not_black, int i)
{
	if (lm->show_interm_rooms == 0)
		putbox(lm->m, get_point_to_draw(lm->m, i), 2, not_black);
	else
	{
		putbox(lm->m, get_point_to_draw(lm->m, i), lm->size_ant_im + 2, not_black);
		putbox(lm->m, get_point_to_draw(lm->m, i), lm->size_ant_im + 4, not_black);
		put_full_box(lm->m, get_point_to_draw(lm->m, i), lm->size_ant_im, 0);
	}
}

static void		draw_intermed_room(t_lemin_mlx *lm, int not_black, int i)
{
	if (lm->show_not_use_edges == 0)
	{
		if (lm->lem->rooms[i]->flow == 1)
			draw_intermed_room_aux(lm, not_black, i);
		else
		{
			if (lm->show_interm_rooms == 0)
				draw_intermed_room_aux(lm, not_black, i);
		}
	}
	else
		draw_intermed_room_aux(lm, not_black, i);
}

static void		draw_rooms(t_lemin_mlx *lm, int not_black)
{
	int		i;
	i = -1;
	while (++i < lm->lem->count_rooms)
	{
		if (i != lm->lem->start_room && i != lm->lem->end_room)
			draw_intermed_room(lm, not_black, i);
	}
	draw_start_end_room(lm, not_black, 0xFF0000, lm->lem->start_room);
	draw_start_end_room(lm, not_black, 0x00FF00, lm->lem->end_room);
}

void			draw_anthill(t_lemin_mlx *lm, int not_black)
{
	draw_ways(lm, not_black);
	draw_rooms(lm, not_black);
}
