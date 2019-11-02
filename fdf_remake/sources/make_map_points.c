/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawline.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odrinkwa <odrinkwa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 13:12:43 by odrinkwa          #+#    #+#             */
/*   Updated: 2019/10/14 13:13:20 by odrinkwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void			make_map_points(t_mlx *m, int color)
{
	double	shift_x;
	double	shift_y;
	double	step;
	int		i;
	//int		j;

	step = m->width / (m->map_x + 1) < m->height / (m->map_y + 1) ?
			m->width / (m->map_x + 1) : m->height / (m->map_y + 1);
	step *= m->zoom;
	shift_x = (m->width - (m->map_x * step)) / 2;
	shift_y = (m->height - (m->map_y * step)) / 2;
	i = -1;
	while (++i < m->quantity_points)
	{
		m->map_points[i].x = shift_x + step * m->map_points[i].x0;
		m->map_points[i].y = shift_y + step * m->map_points[i].y0;
		m->map_points[i].z = m->map_points[i].z0 * m->h;
		m->map_points[i].color = color;
	}
	correct_color(m);
	rotate_points(m);
}
