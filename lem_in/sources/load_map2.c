/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_map2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odrinkwa <odrinkwa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/16 17:43:13 by odrinkwa          #+#    #+#             */
/*   Updated: 2019/11/24 16:58:34 by odrinkwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "libft.h"
#include "lemin.h"

void		load_number_of_ants(t_lemin *lemin, int fd)
{
	char	*line;
	int		res;

	line = NULL;
	while ((res = get_next_line(fd, &line)) == 1)
	{
		if (line[0] == '#')
			ft_memdel((void**)&line);
		else if (ft_isint(line))
		{
			lemin->number_of_ants = ft_atoi(line);
			ft_memdel((void**)&line);
			if (lemin->number_of_ants <= 0)
				finish_prog(lemin, -1, fd, NULL);
			else if (!(lemin->ants_moving = (t_dlist**)
					ft_memalloc(sizeof(t_dlist) * lemin->number_of_ants)))
				finish_prog(lemin, -1, fd, NULL);
			break ;
		}
		else
			finish_prog(lemin, -1, fd, NULL);
	}
	ft_memdel((void**)&line);
	if (res < 0)
		finish_prog(lemin, -1, fd, NULL);
}
