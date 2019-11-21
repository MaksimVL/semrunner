#include "libft.h"
#include "lemin.h"
#include "mlx.h"
#include "fdf.h"

void			set_num_rooms_to_ant_moves(t_lemin *l)
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
	if (errno)
		finish_prog(l, -1, -1, NULL);
}

void			create_ant_draw_move(t_lemin_mlx *lm)
{
	int		i;

	if (!(lm->ants_move = (t_ant_draw_move*)ft_memalloc(sizeof(t_ant_draw_move) * lm->lem->number_of_ants)))
		finish_all(lm, -1);
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
		l->rooms[l->start_room]->flow = 1;
		while (++j < l->count_edges)
			if (l->edges[j].from == l->start_room && l->edges[j].to == am->to)
				l->edges[j].flow = 1;

		while (curr != NULL && curr->next != NULL)
		{
			am = curr->content;
			am_next = curr->next->content;
			j = -1;
			while (++j < l->count_edges)
			{
				if (l->edges[j].from == am->to && l->edges[j].to == am_next->to)
					l->edges[j].flow = 1;
				l->rooms[am->to]->flow = 1;
				l->rooms[am_next->to]->flow = 1;
			}
			curr = curr->next;
		}
	}
}
