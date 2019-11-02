/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odrinkwa <odrinkwa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 12:34:23 by odrinkwa          #+#    #+#             */
/*   Updated: 2019/11/02 15:39:02 by odrinkwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		correct_angles(t_mlx *m)
{
	m->x_angle %= 360;
	m->y_angle %= 360;
	m->z_angle %= 360;
}

void			x_rotation(t_mlx *m)
{
	int		i;
	double	angle;
	t_point	prev;

	i = 0;
	correct_angles(m);
	angle = m->x_angle * M_PI / 180;
	while (i < m->quantity_points)
	{
		prev = m->map_points[i];
		prev.y -= m->height / 2;
		m->map_points[i].y = prev.y * cos(angle) - prev.z * sin(angle) +
							m->height / 2;
		m->map_points[i].z = -prev.y * sin(angle) + prev.z * cos(angle);
		i++;
	}
}

void			y_rotation(t_mlx *m)
{
	int		i;
	int		shift_x;
	double	angle;
	t_point	prev;

	shift_x = m->width / 2;
	i = 0;
	correct_angles(m);
	angle = m->y_angle * M_PI / 180;
	while (i < m->quantity_points)
	{
		prev = m->map_points[i];
		prev.x -= shift_x;
		m->map_points[i].x = prev.x * cos(angle) + prev.z * sin(angle) +
					shift_x;
		m->map_points[i].z = -prev.x * sin(angle) + prev.z * cos(angle);
		i++;
	}
}

void			z_rotation(t_mlx *m)
{
	int		i;
	double	angle;
	t_point	prev;

	correct_angles(m);
	angle = m->z_angle * M_PI / 180;
	i = 0;
	while (i < m->quantity_points)
	{
		prev = m->map_points[i];
		prev.x -= m->width / 2;
		prev.y -= m->height / 2;
		m->map_points[i].x = prev.x * cos(angle) - prev.y * sin(angle) +
					m->width / 2;
		m->map_points[i].y = prev.x * sin(angle) + prev.y * cos(angle) +
					m->height / 2;
		i++;
	}
}

void			rotate_points(t_mlx *m)
{
	if (m->x_angle != 0)
		x_rotation(m);
	if (m->z_angle != 0)
		z_rotation(m);
	if (m->y_angle != 0)
		y_rotation(m);
}
