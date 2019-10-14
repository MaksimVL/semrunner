/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_surface.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odrinkwa <odrinkwa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 13:10:22 by odrinkwa          #+#    #+#             */
/*   Updated: 2019/10/14 13:10:23 by odrinkwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void			draw_surface(t_mlx *m, int not_black)
{
	int		i;
	int		j;

	i = 0;
	while (i < m->map_y)
	{
		j = 0;
		while (j < m->map_x)
		{
			if (j + 1 < m->map_x)
				putline(m, get_proj_point(m, i, j),
						get_proj_point(m, i, j + 1), not_black);
			if (i + 1 < m->map_y)
				putline(m, get_proj_point(m, i, j),
						get_proj_point(m, i + 1, j), not_black);
			j++;
		}
		i++;
	}
}
