#include <fcntl.h>
#include "libft.h"
#include "lemin.h"

t_room			set_room_property(char **strings, int next_flag)
{
	t_room			room_temp;

	room_temp.name = ft_strdup(strings[0]);
	room_temp.x = ft_atoi(strings[1]);
	room_temp.y = ft_atoi(strings[2]);
	room_temp.z = 0;
	room_temp.start_end_flag = next_flag;
	return (room_temp);
}

int				load_data(t_lemin *lemin)
{
	int				res;
	char			*line;
	char			**strings;
	int				next_flag;
	t_room			room_temp;
	t_room_ways		room_ways_temp;
	t_dlist			*dlst_temp;
	int				fd;

	line = NULL;
	strings = NULL;
	next_flag = 0;
	fd = open("testmap", O_RDONLY);
	while ((res = get_next_line(fd, &line)) == 1) //TODO добавить проверку на корректность данных
	{
		if (ft_strequ(line, "##start"))
			next_flag = 1;
		else if (ft_strequ(line, "##end"))
			next_flag = 2;
		else if (ft_strnstr(line, "#", 1))
			next_flag = 0;
		else if (ft_strstr(line, "-"))
		{
			strings = ft_strsplit(line, '-');
			room_ways_temp.start_room = ft_strdup(strings[0]);
			room_ways_temp.end_room = ft_strdup(strings[1]);
			ft_dlst_addcontent_back(&(lemin->room_ways), &room_ways_temp, sizeof(room_ways_temp));
			ft_del_strsplit(&strings);
			next_flag = 0;
		}
		else
		{
			strings = ft_strsplit(line, ' '); //TODO сделать проверку на дублирование комнат
			room_temp = set_room_property(strings, next_flag);
			ft_dlst_addcontent_back(&(lemin->list_rooms), &room_temp, sizeof(room_temp));
			ft_del_strsplit(&strings);
			next_flag = 0;
		}
		ft_memdel((void**)&line);
	}
	close(fd);
	ft_memdel((void**)&line);
	if (res == -1)
		return (0);
	return (1);
}

void			set_rooms_number(t_lemin *lemin)
{
	t_dlist		*curr;
	int			i;

	i = 0;
	curr = lemin->list_rooms;
	while (curr != NULL)
	{
		((t_room*)(curr->content))->number = i;
		if (((t_room*)(curr->content))->start_end_flag == 1)
			lemin->s = i;
		if (((t_room*)(curr->content))->start_end_flag == 2)
			lemin->t = i;
		i++;
		lemin->count_rooms++;
		curr = curr->next;
	}
}

int				room_number(t_lemin *lemin, char *room_name)
{
	t_dlist		*curr;

	curr = lemin->list_rooms;
	while (curr != NULL)
	{
		if (ft_strequ(((t_room*)(curr->content))->name, room_name))
			return (((t_room*)(curr->content))->number);
		curr = curr->next;
	}
	return (-1);
}

void			edges_assign(t_lemin *lemin)
{
	t_dlist		*curr;
	int			i;

	lemin->edges = (t_edge*)ft_memalloc(sizeof(t_edge) * lemin->count_edges);
	i = 0;
	curr = lemin->room_ways;
	while (i < lemin->count_edges)
	{
		lemin->edges[i].from = room_number(lemin, ((t_room_ways*)(curr->content))->start_room);
		lemin->edges[i].to = room_number(lemin, ((t_room_ways*)(curr->content))->end_room);
		lemin->edges[i].capacity = 1;
		lemin->edges[i].cost = 1;
		i++;
		curr = curr->next;
	}
}

void			lemin_init_arrays(t_lemin *lemin)
{
	int i;
	int from;
	int to;
	t_dlist		*curr;

	lemin->adj = (int**)ft_memalloc(sizeof(int*) * lemin->count_rooms);
	lemin->cost = (int**)ft_memalloc(sizeof(int*) * lemin->count_rooms);
	lemin->capacity = (int**)ft_memalloc(sizeof(int*) * lemin->count_rooms);
	lemin->flow = (int**)ft_memalloc(sizeof(int*) * lemin->count_rooms);
	i = 0;
	while (i < lemin->count_rooms)
	{
		(lemin->adj)[i] = (int*)ft_memalloc(sizeof(int) * lemin->count_rooms);
		(lemin->cost)[i] = (int*)ft_memalloc(sizeof(int) * lemin->count_rooms);
		(lemin->capacity)[i] = (int*)ft_memalloc(sizeof(int) * lemin->count_rooms);
		(lemin->flow)[i] = (int*)ft_memalloc(sizeof(int) * lemin->count_rooms);
		i++;
	}
	lemin->push = (int*)ft_memalloc(sizeof(int) * lemin->count_rooms);
	lemin->mark = (int*)ft_memalloc(sizeof(int) * lemin->count_rooms);
	lemin->pred = (int*)ft_memalloc(sizeof(int) * lemin->count_rooms);
	lemin->dist = (int*)ft_memalloc(sizeof(int) * lemin->count_rooms);

	lemin->max_flow = 0;
	lemin->min_cost = 0;
}

void			lemin_fill_matrix(t_lemin *lem)
{
	int i;
	t_edge e;

	i = 0;
	while (i < lem->count_edges)
	{
		e = lem->edges[i];
		lem->capacity[e.from][e.to] = e.capacity;
		lem->capacity[e.to][e.from] = e.capacity;
		lem->cost[e.from][e.to] = e.cost;
		lem->cost[e.to][e.from] = e.cost;
		i++;
	}
}
