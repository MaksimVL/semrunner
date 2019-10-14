/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odrinkwa <odrinkwa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 12:34:23 by odrinkwa          #+#    #+#             */
/*   Updated: 2019/10/14 12:38:21 by odrinkwa         ###   ########.fr       */
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
	int		j;
	double	angle;
	t_point	prev;

	i = 0;
	correct_angles(m);
	angle = m->x_angle * M_PI / 180;
	while (i < m->map_y)
	{
		j = 0;
		while (j < m->map_x)
		{
			prev = *get_point(m, i, j);
			prev.y -= m->height / 2;
			get_point(m, i, j)->y = prev.y * cos(angle) -
					prev.z * sin(angle) + m->height / 2;
			get_point(m, i, j)->z = -prev.y * sin(angle) +
					prev.z * cos(angle);
			j++;
		}
		i++;
	}
}

void			y_rotation(t_mlx *m)
{
	int		i;
	int		j;
	int		shift_x;
	double	angle;
	t_point	prev;

	shift_x = m->width / 2;
	i = 0;
	correct_angles(m);
	angle = m->y_angle * M_PI / 180;
	while (i < m->map_y)
	{
		j = 0;
		while (j < m->map_x)
		{
			prev = *get_point(m, i, j);
			prev.x -= shift_x;
			get_point(m, i, j)->x = prev.x * cos(angle) +
					prev.z * sin(angle) + shift_x;
			get_point(m, i, j)->z = -prev.x * sin(angle) + prev.z * cos(angle);
			j++;
		}
		i++;
	}
}

void			z_rotation(t_mlx *m)
{
	int		i;
	int		j;
	double	angle;
	t_point	prev;

	correct_angles(m);
	angle = m->z_angle * M_PI / 180;
	i = 0;
	while (i < m->map_y)
	{
		j = 0;
		while (j < m->map_x)
		{
			prev = *get_point(m, i, j);
			prev.x -= m->width / 2;
			prev.y -= m->height / 2;
			get_point(m, i, j)->x = prev.x * cos(angle) -
					prev.y * sin(angle) + m->width / 2;
			get_point(m, i, j)->y = prev.x * sin(angle) +
					prev.y * cos(angle) + m->height / 2;
			j++;
		}
		i++;
	}
}
