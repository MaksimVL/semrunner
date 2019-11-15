#include <fcntl.h>
#include "libft.h"
#include "lemin.h"

t_room			set_room_property(char **strings, int next_flag)
{
	t_room			room_temp;

	room_temp.name = ft_strdup(strings[0]);
	if (ft_isint(strings[1]) == 0 || ft_isint(strings[2]) == 0)
		errno = 200;
	room_temp.x = ft_atoi(strings[1]);
	room_temp.y = ft_atoi(strings[2]);
	if (strings[3] != NULL)
		room_temp.z = ft_atoi(strings[3]);
	else
		room_temp.z = 0;
	room_temp.start_end_flag = next_flag;
	return (room_temp);
}

int				find_duplicates_rooms(t_dlist *list_rooms, t_room room_temp)
{
	t_dlist	*curr;
	t_room	*room;

	curr = list_rooms;
	while (curr != NULL)
	{
		room = curr->content;
		if (ft_strequ(room->name, room_temp.name))
			return (1);

		curr = curr->next;
	}
	return (0);
}
int				load_data(t_lemin *lemin, char *filename)
{
	int				res;
	char			*line;
	char			**strings;
	int				next_flag;
	t_room			room_temp;
	t_room_ways		room_ways_temp;
	int				fd;

	line = NULL;
	strings = NULL;
	next_flag = 0;
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		finish_prog(lemin, -1, fd, NULL, NULL);
	if ((res = get_next_line(fd, &line)) == 1)
	{
		lemin->number_of_ants = ft_atoi(line);
		ft_memdel((void**)&line);
		if (lemin->number_of_ants <= 0)
			finish_prog(lemin, -1, fd, NULL, NULL);
	}
	else
		finish_prog(lemin, -1, fd, NULL, NULL);
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
			if (!(strings = ft_strsplit(line, '-')))
				finish_prog(lemin, -1, fd, NULL, &line);
			if (strings[0] == NULL || strings[1] == NULL)
				finish_prog(lemin, -1, fd, &strings, &line);
			room_ways_temp.start_room = ft_strdup(strings[0]);
			room_ways_temp.end_room = ft_strdup(strings[1]);
			ft_dlst_addcontent_back(&(lemin->room_ways), &room_ways_temp, sizeof(room_ways_temp));
			lemin->count_edges++;
			ft_del_strsplit(&strings);
			next_flag = 0;
		}
		else
		{
			if (!(strings = ft_strsplit(line, ' ')))
				finish_prog(lemin, -1, fd, NULL, &line);
			if (strings[0] == NULL || strings[1] == NULL || strings[2] == NULL)
				finish_prog(lemin, -1, fd, &strings, &line);
			//TODO сделать проверку на дублирование комнат
			room_temp = set_room_property(strings, next_flag);
			room_temp.number = (lemin->count_rooms);
			if (next_flag == 1)
				lemin->start_room = lemin->count_rooms;
			if (next_flag == 2)
				lemin->end_room = lemin->count_rooms;
			if (find_duplicates_rooms(lemin->list_rooms, room_temp) == 1)
			 	finish_prog(lemin, -1, fd, &strings, &line);
			ft_dlst_addcontent_back(&(lemin->list_rooms), &room_temp, sizeof(room_temp));
			lemin->count_rooms++;
			ft_del_strsplit(&strings);
			next_flag = 0;
		}
		ft_memdel((void**)&line);
		if (errno)
			finish_prog(lemin, -1, fd, NULL, NULL);
	}
	close(fd);
	ft_memdel((void**)&line);
	if (res == -1)
		return (0);
	lemin->size_matrix = lemin->count_rooms * 2;
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
	lemin->push = (int*)malloc(sizeof(int) * lemin->count_rooms * 2);
	lemin->mark = (int*)malloc(sizeof(int) * lemin->count_rooms * 2);
	lemin->pred = (int*)malloc(sizeof(int) * lemin->count_rooms * 2);
	lemin->max_flow = 0;
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

void			*add_edge(t_lemin *lem, int start, int end, int capacity)
{
	t_dlist *curr;
	t_gedge tmp;

	curr = lem->g[start];
	while (curr != NULL)
	{
		if (((t_gedge*)(curr->content))->to == end)
			return (lem);
		curr = curr->next;
	}
	tmp.to = end;
	tmp.capacity = capacity;
	tmp.flow = 0;
	tmp.flow1 = 0;
	ft_dlst_addcontent_back(&(lem->g[start]), &tmp, sizeof(tmp));
	return (lem);
}

void			lemin_fill_matrix2x(t_lemin *lem)
{
	int		i;
	t_edge	e;
	int		start;
	int		end;

	lem->g = (t_dlist**)ft_memalloc(sizeof(t_dlist*) * lem->size_matrix);

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
		add_edge(lem, 2 * start, 2 * end + 1, 1);
		add_edge(lem, 2 * end + 1, 2 * start, 0);
		if (start != lem->s && end != lem->t)
		{
			add_edge(lem, 2 * end, 2 * start + 1, 1);
			add_edge(lem, 2 * start + 1, 2 * end, 0);
		}
	}
	i = -1;
	while (++i < lem->count_rooms)
	{
		if (i != lem->s && i != lem->t)
		{
			add_edge(lem, 2 * i + 1, 2 * i, 1);
			add_edge(lem, 2 * i, 2 * i + 1, 0);
		}
	}
	lem->s = lem->start_room * 2;
	lem->t = lem->end_room * 2 + 1;
}
