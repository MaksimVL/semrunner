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

t_point	get_point_to_draw(t_mlx *m, int i, int j)
{
	t_point	res;
	res = get_proj_point(m, i, j);
	res.x += m->camera_x;
	res.y += m->camera_y;
	return res;
}

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
				// putline(m, get_proj_point(m, i, j),
				// 		get_proj_point(m, i, j + 1), not_black);
				putline(m, get_point_to_draw(m, i, j),
						get_point_to_draw(m, i, j + 1), not_black);
			if (i + 1 < m->map_y)
				// putline(m, get_proj_point(m, i, j),
				// 		get_proj_point(m, i + 1, j), not_black);
				putline(m, get_point_to_draw(m, i, j),
						get_point_to_draw(m, i + 1, j), not_black);
			j++;
		}
		i++;
	}
}
