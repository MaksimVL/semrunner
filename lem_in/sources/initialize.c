#include "libft.h"
#include "lemin.h"

void			destroy_room(void *room, size_t size)
{
	t_room		*room_tmp;

	if (size == 0 && size != 0)
		;
	ft_memdel((void**)&(((t_room*)room)->name));
	//ft_memdel((void**)&room);
}

void			destroy_way(void *room_ways, size_t size)
{
	if (size == 0 && size != 0)
		;
	ft_memdel((void**)&((t_room_ways*)room_ways)->start_room);
	ft_memdel((void**)&((t_room_ways*)room_ways)->end_room);
	//ft_memdel((void**)&room_ways);
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
	ft_delmatrix((void***)&(lemin->adj), lemin->count_rooms);
	ft_delmatrix((void***)&lemin->cost, lemin->count_rooms);
	ft_delmatrix((void***)&lemin->capacity, lemin->count_rooms);
	ft_delmatrix((void***)&lemin->flow, lemin->count_rooms);
	ft_memdel((void**)&lemin->push);
	ft_memdel((void**)&lemin->mark);
	ft_memdel((void**)&lemin->pred);
	ft_memdel((void**)&lemin->dist);

	// if (lemin->list_rooms != NULL)
	// 	ft_dlstdel(&(lemin->list_rooms), destroy_room);
	// if (lemin->room_ways != NULL)
	// 	ft_dlstdel(&(lemin->room_ways), destroy_way);
}

void			lemin_init(t_lemin *lemin)
{
	lemin->list_rooms = NULL;
	lemin->room_ways = NULL;
	lemin->count_rooms = 0;
	lemin->number_of_ants = 0;
	lemin->count_edges = 0;
	lemin->edges = NULL;
	lemin->adj = NULL;
	lemin->cost = NULL;
	lemin->capacity = NULL;
	lemin->flow = NULL;
	lemin->push = NULL;
	lemin->mark = NULL;
	lemin->pred = NULL;
	lemin->dist = NULL;
	lemin->max_flow = 0;
	lemin->min_cost = 0;
	lemin->s = -1;
	lemin->t = -1;
}
