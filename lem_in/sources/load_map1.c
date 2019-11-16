/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_map1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odrinkwa <odrinkwa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/16 17:50:59 by odrinkwa          #+#    #+#             */
/*   Updated: 2019/11/16 20:15:08 by odrinkwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
		room_temp.z = NO_DEFINE;
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
