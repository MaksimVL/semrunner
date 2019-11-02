/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readfile2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odrinkwa <odrinkwa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/02 15:44:56 by odrinkwa          #+#    #+#             */
/*   Updated: 2019/11/02 16:25:24 by odrinkwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void			calculate_max_min_h_in_map(t_mlx *m)
{
	int i;
	int j;

	m->min_h = m->map[0];
	m->max_h = m->map[0];
	i = 0;
	while (i < m->map_y)
	{
		j = 0;
		while (j < m->map_x)
		{
			if (m->map[i * m->map_x + j] > m->max_h)
				m->max_h = m->map[i * m->map_x + j];
			if (m->map[i * m->map_x + j] < m->min_h)
				m->min_h = m->map[i * m->map_x + j];
			j++;
		}
		i++;
	}
}

static t_point	*get_point_mapxy(t_mlx *m, int i, int j)
{
	return (&(m->map_points[i * m->map_x + j]));
}

void			set_base_coord(t_mlx *m)
{
	int i;
	int j;

	i = -1;
	while (++i < m->map_y)
	{
		j = -1;
		while (++j < m->map_x)
		{
			get_point_mapxy(m, i, j)->x0 = j;
			get_point_mapxy(m, i, j)->y0 = i;
			get_point_mapxy(m, i, j)->z0 = m->map[i * m->map_x + j];
			get_point_mapxy(m, i, j)->color = 0x0;
		}
	}
}
