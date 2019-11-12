#include "libft.h"
#include "lemin.h"

void			destroy_room(void *room, size_t size)
{
	if (size == 0 && size != 0)
		;
	ft_memdel((void**)&(((t_room*)room)->name));
}

void			destroy_way(void *room_ways, size_t size)
{
	if (size == 0 && size != 0)
		;
	ft_memdel((void**)&((t_room_ways*)room_ways)->start_room);
	ft_memdel((void**)&((t_room_ways*)room_ways)->end_room);
}

void			ft_delmatrix(void ***matrix, int num_of_lines)
{
	int		i;

	if (matrix == NULL || *matrix == NULL)
		return ;
	i = 0;
	while (i < num_of_lines)
	{
		ft_memdel((void**)&((*matrix)[i]));
		i++;
	}
	free(*matrix);
	*matrix = NULL;
}

void			lemin_destroy(t_lemin *lemin)
{
	ft_dlstdel(&(lemin->list_rooms), destroy_room);
	ft_dlstdel(&(lemin->room_ways), destroy_way);
	ft_memdel((void**)&lemin->edges);
	ft_delmatrix((void***)&lemin->capacity, lemin->count_rooms);
	ft_delmatrix((void***)&lemin->flow, lemin->count_rooms);
	ft_memdel((void**)&lemin->push);
	ft_memdel((void**)&lemin->mark);
	ft_memdel((void**)&lemin->pred);
	free(lemin->rooms);
	lemin->rooms = NULL;
}

void			lemin_init(t_lemin *lemin)
{
	lemin->list_rooms = NULL;
	lemin->room_ways = NULL;
	lemin->count_rooms = 0;
	lemin->number_of_ants = 0;
	lemin->start_room = -1;
	lemin->end_room = -1;
	lemin->number_of_ants = 0;
	lemin->count_edges = 0;
	lemin->edges = NULL;
	lemin->rooms = NULL;
	lemin->ants_left_on_ways = NULL;
	lemin->flow1 = NULL;
	lemin->ways = NULL;
	lemin->way_length = NULL;
	lemin->count_ways = 0;
	lemin->prev_ways = NULL;
	lemin->way_length = NULL;
	lemin->prev_count_ways = 0;
	lemin->ants_left_on_ways = NULL;
	lemin->size_matrix = 0;
	lemin->capacity = NULL;
	lemin->flow = NULL;
	lemin->push = NULL;
	lemin->mark = NULL;
	lemin->pred = NULL;
	lemin->max_flow = 0;
	lemin->s = -1;
	lemin->t = -1;
}
