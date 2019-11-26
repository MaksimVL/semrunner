/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_map1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odrinkwa <odrinkwa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/16 17:50:59 by odrinkwa          #+#    #+#             */
/*   Updated: 2019/11/24 23:06:44 by odrinkwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "lemin.h"
#include <time.h>

void			set_numbers_rooms(t_lemin *lemin)
{
	int i = -1;
	t_dlist *curr;
	t_room *room;

	curr = lemin->list_rooms;
	while (++i < lemin->count_rooms)
	{
		room = curr->content;
		room->number = i;
		if (room->start_end_flag == 1)
			lemin->start_room = i;
		else if (room->start_end_flag == 2)
			lemin->end_room = i;
//		ft_printf("%s, ", room->name);
		curr = curr->next;
	}
}

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
		room_temp.z = NO_DEFINE;
	room_temp.start_end_flag = next_flag;
	room_temp.flow = 0;
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

static int		set_first_end_room(t_lemin *lemin, int *next_flag)
{
	if (*next_flag == 1)
	{
		if (lemin->start_room == -1)
			lemin->start_room = lemin->count_rooms;
		else
			return (-1);
	}
	if (*next_flag == 2)
	{
		if (lemin->end_room == -1)
			lemin->end_room = lemin->count_rooms;
		else
			return (-1);
	}
	return (1);
}

int				load_ordered_room(t_dlist **list_rooms, t_room *room_temp)
{
	t_dlist		*curr;
	t_room		*room;
	int			cmp;

	if (*list_rooms == NULL)
	{
		ft_dlst_addcontent_back(list_rooms, room_temp, sizeof(*room_temp));
		return (1);
	}
	curr = *list_rooms;
	while (curr != NULL)
	{
		room = curr->content;
		cmp = ft_strcmp(room->name, room_temp->name);
		if (cmp == 0)
			return (0);
		else if (cmp > 0)
		{
			ft_dlst_addcontent(&curr, room_temp, sizeof(*room_temp));
			return (1);
		}
		curr = curr->next;
	}
	ft_dlst_addcontent_back(list_rooms, room_temp, sizeof(*room_temp));
	return (1);
}


void			load_room(t_lemin *lemin, char **line, int *next_flag, int fd)
{
	char		**strings;
	t_room		room_temp;

	strings = NULL;
	if (!(strings = ft_strsplit(*line, ' ')) || strings[0] == NULL ||
		strings[1] == NULL || strings[2] == NULL)
	{
		ft_del_strsplit(&strings);
		finish_prog(lemin, -1, fd, line);
	}
	ft_memdel((void**)line);
	room_temp = set_room_property(strings, *next_flag);
	ft_del_strsplit(&strings);
	room_temp.number = (lemin->count_rooms);
	if (set_first_end_room(lemin, next_flag) == -1)
		finish_prog(lemin, -1, fd, &(room_temp.name));
	if (load_ordered_room(&(lemin->list_rooms), &room_temp) == 0 ||
	 	ft_strstr(room_temp.name, "-"))
	 	finish_prog(lemin, -1, fd, &(room_temp.name));

	//print_list(lemin->list_rooms);
	// if (find_duplicates_rooms(lemin->list_rooms, &room_temp) == 1 ||
	// 	ft_strstr(room_temp.name, "-"))
	// 	finish_prog(lemin, -1, fd, &(room_temp.name));
	// else
	// 	ft_dlst_addcontent_back(&(lemin->list_rooms), &room_temp,
	// 							sizeof(room_temp));
	lemin->count_rooms++;
	*next_flag = 0;
}
