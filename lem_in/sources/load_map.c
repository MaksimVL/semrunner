#include <fcntl.h>
#include "libft.h"
#include "lemin.h"

t_room			set_room_property(char **strings, int next_flag)
{
	t_room			room_temp;

	room_temp.name = ft_strdup(strings[0]);
	room_temp.x = ft_atoi(strings[1]);
	room_temp.y = ft_atoi(strings[2]);
	if (strings[3] != NULL)
		room_temp.z = ft_atoi(strings[3]);
	else
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
	if ((res = get_next_line(fd, &line)) == 1)
	{
		lemin->number_of_ants = ft_atoi(line);
		ft_memdel((void**)&line);
	}
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
			lemin->start_room = i;
		if (((t_room*)(curr->content))->start_end_flag == 2)
			lemin->end_room = i;
		i++;
		lemin->count_rooms++;
		curr = curr->next;
	}
	lemin->size_matrix = lemin->count_rooms * 2;
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

	lemin->adj = (int**)ft_memalloc(sizeof(int*) * lemin->count_rooms * 2);
	lemin->cost = (int**)ft_memalloc(sizeof(int*) * lemin->count_rooms * 2);
	lemin->capacity = (int**)ft_memalloc(sizeof(int*) * lemin->count_rooms * 2);
	lemin->flow = (int**)ft_memalloc(sizeof(int*) * lemin->count_rooms * 2);
	lemin->flow1 = (int**)ft_memalloc(sizeof(int*) * lemin->count_rooms * 2);
	i = 0;
	while (i < lemin->count_rooms * 2)
	{
		(lemin->adj)[i] = (int*)ft_memalloc(sizeof(int) * lemin->count_rooms * 2);
		(lemin->cost)[i] = (int*)ft_memalloc(sizeof(int) * lemin->count_rooms * 2);
		(lemin->capacity)[i] = (int*)ft_memalloc(sizeof(int) * lemin->count_rooms * 2);
		(lemin->flow)[i] = (int*)ft_memalloc(sizeof(int) * lemin->count_rooms * 2);
		(lemin->flow1)[i] = (int*)ft_memalloc(sizeof(int) * lemin->count_rooms * 2);
		i++;
	}
	lemin->push = (int*)ft_memalloc(sizeof(int) * lemin->count_rooms * 2);
	lemin->mark = (int*)ft_memalloc(sizeof(int) * lemin->count_rooms * 2);
	lemin->pred = (int*)ft_memalloc(sizeof(int) * lemin->count_rooms * 2);
	lemin->dist = (int*)ft_memalloc(sizeof(int) * lemin->count_rooms * 2);

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

void			lemin_fill_rooms(t_lemin *lem)
{
	int		i;
	t_dlist *curr;

	lem->rooms = (t_room**)ft_memalloc(sizeof(t_room*) * lem->count_rooms);
	curr = lem->list_rooms;
	i = 0;
	while (i < lem->count_rooms)
	{
		(lem->rooms)[i] = (t_room*)(curr->content);
		i++;
		curr = curr->next;
	}
}

void			lemin_fill_matrix2x(t_lemin *lem)
{
	int		i;
	t_edge	e;
	int		start;
	int		end;

	i = -1;
	while (++i < lem->count_edges)
	{
		e = lem->edges[i];
		if (e.from == lem->s)
		{
			start = e.from;
			end = e.to;
		}
		else if (e.to == lem->s)
		{
			start = e.to;
			end = e.from;
		}
		else if (e.from == lem->t)
		{
			start = e.to;
			end = e.from;
		}
		else
		{
			start = e.from;
			end = e.to;
		}

		lem->capacity[2 * start][2 * end + 1] = 1;
		lem->cost[2 * start][2 * end + 1] = 1;
		lem->cost[2 * end + 1][2 * start] = -1;
		if (start != lem->s && end != lem->t)
		{
			lem->capacity[2 * end][2 * start + 1] = 1;
			lem->cost[2 * end][2 * start + 1] = 1;
			lem->cost[2 * start + 1][2 * end] = -1;
		}
	}
	i = -1;
	while (++i < lem->count_rooms)
	{
		if (i != lem->s && i != lem->t)
		{
			lem->capacity[2 * i + 1][2 * i] = 1;
			lem->cost[2 * i + 1][2 * i] = 1;
			lem->cost[2 * i][2 * i + 1] = -1;
		}
	}
	lem->s = lem->start_room * 2;
	lem->t = lem->end_room * 2 + 1;
	// ft_printf("---- capacity ----\n");
	// print_intmatrix(lem->capacity, lem->size_matrix, lem->size_matrix);
	// ft_printf("----\n");
	// ft_printf("---- cost ----\n");
	// print_intmatrix(lem->cost, lem->size_matrix, lem->size_matrix);
	// ft_printf("----\n");

}
