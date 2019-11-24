/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odrinkwa <odrinkwa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/16 17:43:13 by odrinkwa          #+#    #+#             */
/*   Updated: 2019/11/17 00:39:15 by odrinkwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "libft.h"
#include "lemin.h"

static void		load_number_of_ants(t_lemin *lemin, int fd)
{
	char	*line;
	int		res;

	line = NULL;
	while ((res = get_next_line(fd, &line)) == 1)
	{
		if (line[0] == '#')
			{
				ft_memdel((void**)&line);
				continue ;
			}
		else if (ft_isint(line))
		{
			lemin->number_of_ants = ft_atoi(line);
			ft_memdel((void**)&line);
			if (lemin->number_of_ants <= 0)
				finish_prog(lemin, -1, fd, NULL);
			else
				if (!(lemin->ants_moving = (t_dlist**)ft_memalloc(sizeof(t_dlist) * lemin->number_of_ants)))
					finish_prog(lemin, -1, fd, NULL);
			break ;
		}
		else
			finish_prog(lemin, -1, fd, NULL);
	}
	if (res < 0)
		finish_prog(lemin, -1, fd, NULL);
}

static void		load_link(t_lemin *lemin, char **line, int *next_flag, int fd)
{
	char			**strings;
	t_room_ways		room_ways_temp;

	strings = NULL;
	if (!(strings = ft_strsplit(*line, '-')))
		finish_prog(lemin, -1, fd, line);
	if (strings[0] == NULL || strings[1] == NULL)
	{
		ft_del_strsplit(&strings);
		finish_prog(lemin, -1, fd, line);
	}
	room_ways_temp.start_room = ft_strdup(strings[0]);
	room_ways_temp.end_room = ft_strdup(strings[1]);
	ft_del_strsplit(&strings);
	ft_dlst_addcontent_back(&(lemin->room_ways), &room_ways_temp,
							sizeof(room_ways_temp));
	lemin->count_edges++;
	*next_flag = 0;
}

static void		load_room(t_lemin *lemin, char **line, int *next_flag, int fd)
{
	char		**strings;
	t_room		room_temp;

	strings = ft_strsplit(*line, ' ');
	if (strings == NULL)
		finish_prog(lemin, -1, fd, line);
	if (strings[0] == NULL || strings[1] == NULL || strings[2] == NULL)
	{
		ft_del_strsplit(&strings);
		finish_prog(lemin, -1, fd, line);
	}
	room_temp = set_room_property(strings, *next_flag);
	ft_del_strsplit(&strings);
	room_temp.number = (lemin->count_rooms);
	if (*next_flag == 1)
	{
		if (lemin->start_room == -1)
			lemin->start_room = lemin->count_rooms;
		else
			finish_prog(lemin, -1, fd, line);
	}
	if (*next_flag == 2)
	{
		if (lemin->end_room == -1)
			lemin->end_room = lemin->count_rooms;
		else
			finish_prog(lemin, -1, fd, line);
	}
	if (find_duplicates_rooms(lemin->list_rooms, room_temp) == 1 ||
		ft_strstr(room_temp.name, "-"))
		{
			ft_dlst_addcontent_back(&(lemin->list_rooms), &room_temp,
								sizeof(room_temp));
			finish_prog(lemin, -1, fd, line);
		}
	else
		ft_dlst_addcontent_back(&(lemin->list_rooms), &room_temp,
								sizeof(room_temp));
	lemin->count_rooms++;
	*next_flag = 0;
}

static void		load_line(t_lemin *lemin, char **line, int *next_flag, int fd)
{
	if (ft_strequ(*line, "##start"))
		*next_flag = 1;
	else if (ft_strequ(*line, "##end"))
		*next_flag = 2;
	else if (ft_strnstr(*line, "#", 1))
		*next_flag = 0;
	else if (ft_strstr(*line, " "))
		load_room(lemin, line, next_flag, fd);
	else if (ft_strstr(*line, "-"))
		load_link(lemin, line, next_flag, fd);
	ft_memdel((void**)line);
	if (errno)
		finish_prog(lemin, -1, fd, NULL);
}

int				load_position_ant(t_lemin *lemin, char *line, int step)
{
	char		**strings;
	t_ant_move	am;
	int			num_ant;

	if (!(strings = ft_strsplit(line + 1, '-')))
		return (0);
	if (strings[0] == NULL || strings[1] == NULL)
	{
		ft_del_strsplit(&strings);
		return (0);
	}
	else
	{
		num_ant = ft_atoi(strings[0]);
		am.step = step;
		am.to_name = ft_strdup(strings[1]);
		am.to = -1;
		ft_dlst_addcontent_back(&(lemin->ants_moving[num_ant - 1]), &am,
							sizeof(am));
	}
	ft_del_strsplit(&strings);
	return (1);
}

void			load_line_moving_ants(t_lemin *lemin, char **line, int fd, int step)
{
	char		**strings;
	int			i;

	strings = NULL;
	if (!(strings = ft_strsplit(*line, ' ')))
		finish_prog(lemin, -1, fd, NULL);
	lemin->max_step++;
	i = 0;
	while (strings[i] != NULL)
	{
		if (load_position_ant(lemin, strings[i], step) == 0)
		{
			ft_del_strsplit(&strings);
			finish_prog(lemin, -1, fd, NULL);
		}
		i++;
	}
	ft_del_strsplit(&strings);
}



void			load_data(t_lemin *lemin, int fd, char flag_visu)
{
	int				res;
	char			*line;
	int				next_flag;
	int				step;

	line = NULL;
	next_flag = 0;
	step = 0;
	if (fd < 0)
		finish_prog(lemin, -1, fd, NULL);
	load_number_of_ants(lemin, fd);
	while ((res = get_next_line(fd, &line)) == 1)
	{
		if (flag_visu == 1 && line[0] == 'L')
			load_line_moving_ants(lemin, &line, fd, ++step);
		else if (flag_visu == 1 && line[0] == '\0')
			;
		else
			load_line(lemin, &line, &next_flag, fd);
	}
	ft_memdel((void**)&line);
	if (res == -1)
		finish_prog(lemin, -1, fd, NULL);
	if (lemin->count_rooms == 0 || lemin->count_edges == 0)
		finish_prog(lemin, -1, fd, NULL);
	lemin->size_matrix = lemin->count_rooms * 2;
}
