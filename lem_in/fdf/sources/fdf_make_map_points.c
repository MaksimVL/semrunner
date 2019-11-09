/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_make_map_points.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odrinkwa <odrinkwa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 13:12:43 by odrinkwa          #+#    #+#             */
/*   Updated: 2019/11/09 22:39:18 by odrinkwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void			make_map_points(t_mlx *m)
{
	double	shift_x;
	double	shift_y;
	double	step;
	int		i;

	step = (double)(m->width) / (double)(m->map_x + 1) <
			(double)(m->height) / (double)(m->map_y + 1) ?
			(double)(m->width) / (double)(m->map_x + 1) :
			(double)(m->height) / (double)(m->map_y + 1);
	step *= m->zoom;
	shift_x = ((double)m->width - ((double)m->map_x * step)) / 2.0;
	shift_y = ((double)m->height - ((double)m->map_y * step)) / 2.0;
	i = -1;
	while (++i < m->quantity_points)
	{
		m->map_points[i].x = shift_x + step * m->map_points[i].x0;
		m->map_points[i].y = shift_y + step * m->map_points[i].y0;
		m->map_points[i].z = m->map_points[i].z0 * m->h;
	}
	correct_color(m);
	rotate_points(m);
}
