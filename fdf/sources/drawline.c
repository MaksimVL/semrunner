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

t_point			*get_point(t_mlx *m, int i, int j)
{
	return (&(m->map_points[i * m->map_x + j]));
}

void			iso(t_mlx *m, int *x, int *y, int z)
{
	int		prev_x;
	int		prev_y;
	double	angle_projection;

	if (m->angle_projection_type == 0)
		angle_projection = 26.57;
	else if (m->angle_projection_type == 1)
		angle_projection = 30;
	else
		angle_projection = 45;
	prev_x = *x;
	prev_y = *y;
	*x = (prev_x - prev_y) * cos(angle_projection * M_PI / 180.0);
	*y = -z + (prev_x + prev_y) * sin(angle_projection * M_PI / 180.0);
}

static void		calculate_max_min_h(t_mlx *m)
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

static void		correcting_map(t_mlx *m)
{
	calculate_max_min_h(m);
	correct_color(m);
	if (m->x_angle != 0)
		x_rotation(m);
	if (m->z_angle != 0)
		z_rotation(m);
	if (m->y_angle != 0)
		y_rotation(m);
}

void			make_map_points(t_mlx *m, int color)
{
	double	shift_x;
	double	shift_y;
	double	step;
	int		i;
	int		j;

	step = m->width / (m->map_x + 1) < m->height / (m->map_y + 1) ?
			m->width / (m->map_x + 1) : m->height / (m->map_y + 1);
	step *= m->zoom;
	shift_x = (m->width - (m->map_x * step)) / 2;
	shift_y = (m->height - (m->map_y * step)) / 2;
	i = -1;
	while (++i < m->map_y)
	{
		j = 0;
		while (j < m->map_x)
		{
			get_point(m, i, j)->x = shift_x + step * j;
			get_point(m, i, j)->y = shift_y + step * i;
			get_point(m, i, j)->z = m->map[i * m->map_x + j] * m->h;
			get_point(m, i, j)->color = color;
			j++;
		}
	}
	correcting_map(m);
}
