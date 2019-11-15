#include "libft.h"
#include "lemin.h"

void			finish_prog(t_lemin *l, int res, int fd, char ***strings,
						char **line)
{
	lemin_destroy(l);
	ft_memdel((void**)line);
	if (strings != NULL)
		ft_del_strsplit(strings);
	if (fd > 0)
		close(fd);
	if (res != 0)
	{
		ft_printf("ERROR\n");
	}
		exit(res);
}

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

void			del_g(t_lemin *l)
{
	int		i;

	i = -1;
	while (++i < l->size_matrix)
		ft_dlstdel(&(l->g[i]), NULL);
	free(l->g);
	l->g = NULL;
}

void			lemin_destroy(t_lemin *lemin)
{
	ft_dlstdel(&(lemin->list_rooms), destroy_room);
	ft_dlstdel(&(lemin->room_ways), destroy_way);
	ft_memdel((void**)&lemin->edges);
	if (lemin->rooms != NULL)
	{
		free(lemin->rooms);
		lemin->rooms = NULL;
	}
	ft_delmatrix((void***)&(lemin->ants_on_ways), lemin->max_ways);
	ft_delmatrix((void***)&(lemin->ways), lemin->max_ways);
	ft_delmatrix((void***)&(lemin->prev_ways), lemin->max_ways);
	ft_memdel((void**)&lemin->way_length);
	ft_memdel((void**)&lemin->prev_way_length);
	ft_memdel((void*)&lemin->ants_left_on_ways);
	if (lemin->g != NULL)
		del_g(lemin);
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
	lemin->ants_on_ways = NULL;
	lemin->ways = NULL;
	lemin->way_length = NULL;
	lemin->count_ways = 0;
	lemin->count_steps = 0;
	lemin->prev_ways = NULL;
	lemin->way_length = NULL;
	lemin->prev_count_ways = 0;
	lemin->prev_count_steps = 0;
	lemin->max_ways = 0;
	lemin->ants_left_on_ways = NULL;
	lemin->size_matrix = 0;
	lemin->g = NULL;
	lemin->push = NULL;
	lemin->mark = NULL;
	lemin->pred = NULL;
	lemin->max_flow = 0;
	lemin->s = -1;
	lemin->t = -1;
}

int					count_max_flow(t_lemin *l)
{
	int			max_flow;
	t_dlist		*curr;
	t_gedge		*edg;

	max_flow = 0;
	curr = l->g[l->s];
	while (curr != NULL)
	{
		edg = curr->content;
		if (edg->capacity == 1)
			max_flow++;
		curr = curr->next;
	}
	return (max_flow);
}

void				lemin_init_ways(t_lemin *l)
{
	int i;
	int max_flow;

	max_flow = count_max_flow(l);
	l->max_ways = max_flow;
	l->way_length = (int*)ft_memalloc(sizeof(int) * max_flow);
	l->prev_way_length = (int*)ft_memalloc(sizeof(int) * max_flow);
	l->ways = (int**)ft_memalloc(sizeof(int*) * max_flow);
	l->prev_ways = (int**)ft_memalloc(sizeof(int*) * max_flow);
	l->ants_on_ways = (int**)ft_memalloc(sizeof(int*) * max_flow);
	i = -1;
	while (++i < max_flow)
	{
		(l->ways)[i] = (int*)malloc(sizeof(int) * l->count_rooms);
		(l->prev_ways)[i] = (int*)malloc(sizeof(int) * l->count_rooms);
		vector_int_assign(l->ways[i], l->count_rooms, -1);
		vector_int_assign(l->prev_ways[i], l->count_rooms, -1);
		(l->ants_on_ways)[i] = (int*)ft_memalloc(sizeof(int) * l->count_rooms);
	}
}
