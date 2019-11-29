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

void			calc_r_x(t_mlx *m)
{
	double	angle;

	angle = m->x_angle * M_PI / 180;
	m->r_x[0][0] = 1;
	m->r_x[0][1] = 0;
	m->r_x[0][2] = 0;
	m->r_x[0][3] = 0;
	m->r_x[1][0] = 0;
	m->r_x[1][1] = cos(angle);
	m->r_x[1][2] = -sin(angle);
	m->r_x[1][3] = 0;
	m->r_x[2][0] = 0;
	m->r_x[2][1] = sin(angle);
	m->r_x[2][2] = cos(angle);
	m->r_x[2][3] = 0;
	m->r_x[3][0] = 0;
	m->r_x[3][1] = 0;
	m->r_x[3][2] = 0;
	m->r_x[3][3] = 1;
}

void			calc_r_y(t_mlx *m)
{
	double	angle;

	angle = m->y_angle * M_PI / 180;
	m->r_y[0][0] = cos(angle);
	m->r_y[0][1] = 0;
	m->r_y[0][2] = sin(angle);
	m->r_y[0][3] = 0;
	m->r_y[1][0] = 0;
	m->r_y[1][1] = 1;
	m->r_y[1][2] = 0;
	m->r_y[1][3] = 0;
	m->r_y[2][0] = -sin(angle);
	m->r_y[2][1] = 0;
	m->r_y[2][2] = cos(angle);
	m->r_y[2][3] = 0;
	m->r_y[3][0] = 0;
	m->r_y[3][1] = 0;
	m->r_y[3][2] = 0;
	m->r_y[3][3] = 1;
}

void			calc_r_z(t_mlx *m)
{
	double	angle;

	angle = m->z_angle * M_PI / 180;
	m->r_z[0][0] = cos(angle);
	m->r_z[0][1] = -sin(angle);
	m->r_z[0][2] = 0;
	m->r_z[0][3] = 0;
	m->r_z[1][0] = sin(angle);
	m->r_z[1][1] = cos(angle);
	m->r_z[1][2] = 0;
	m->r_z[1][3] = 0;
	m->r_z[2][0] = 0;
	m->r_z[2][1] = 0;
	m->r_z[2][2] = 1;
	m->r_z[2][3] = 0;
	m->r_z[3][0] = 0;
	m->r_z[3][1] = 0;
	m->r_z[3][2] = 0;
	m->r_z[3][3] = 1;
}

void			mult_matrix(double res[4][4], double a[4][4], double b[4][4])
{
	int		i;
	int		j;
	int		k;

	i = -1;
	while (++i < 4)
	{
		j = -1;
		while (++j < 4)
		{
			res[i][j] = 0;
			k = -1;
			while (++k < 4)
			{
				res[i][j] += a[i][k] * b[k][j];
			}

		}
	}
}

void			calc_r_xyz(t_mlx *m)
{
	calc_r_x(m);
	calc_r_y(m);
	calc_r_z(m);
	mult_matrix(m->r_xyz, m->r_x, m->r_y);
}

void			calc_point_x(t_mlx *m, int i)
{
	t_point		prev;

	calc_r_x(m);
	prev = m->map_points[i];
	prev.x -= m->width / 2;
	prev.y -= m->height / 2;
	m->map_points[i].x = prev.x * m->r_x[0][0] + prev.y * m->r_x[0][1] + prev.z * m->r_x[0][2];
	m->map_points[i].y = prev.x * m->r_x[1][0] + prev.y * m->r_x[1][1] + prev.z * m->r_x[1][2];
	m->map_points[i].z = prev.x * m->r_x[2][0] + prev.y * m->r_x[2][1] + prev.z * m->r_x[2][2];
	m->map_points[i].x += m->width / 2;
	m->map_points[i].y += m->height / 2;
}

void			calc_point_y(t_mlx *m, int i)
{
	t_point		prev;

	calc_r_y(m);
	prev = m->map_points[i];
	prev.x -= m->width / 2;
	prev.y -= m->height / 2;
	m->map_points[i].x = prev.x * m->r_y[0][0] + prev.y * m->r_y[0][1] + prev.z * m->r_y[0][2];
	m->map_points[i].y = prev.x * m->r_y[1][0] + prev.y * m->r_y[1][1] + prev.z * m->r_y[1][2];
	m->map_points[i].z = prev.x * m->r_y[2][0] + prev.y * m->r_y[2][1] + prev.z * m->r_y[2][2];
	m->map_points[i].x += m->width / 2;
	m->map_points[i].y += m->height / 2;
}

void			calc_point_z(t_mlx *m, int i)
{
	t_point		prev;

	calc_r_z(m);
	prev = m->map_points[i];
	prev.x -= m->width / 2;
	prev.y -= m->height / 2;
	m->map_points[i].x = prev.x * m->r_z[0][0] + prev.y * m->r_z[0][1] + prev.z * m->r_z[0][2];
	m->map_points[i].y = prev.x * m->r_z[1][0] + prev.y * m->r_z[1][1] + prev.z * m->r_z[1][2];
	m->map_points[i].z = prev.x * m->r_z[2][0] + prev.y * m->r_z[2][1] + prev.z * m->r_z[2][2];
	m->map_points[i].x += m->width / 2;
	m->map_points[i].y += m->height / 2;
}

void			calc_point_xyz(t_mlx *m, int i)
{
	t_point		prev;

	prev = m->map_points[i];
	prev.x -= m->width / 2;
	prev.y -= m->height / 2;
	m->map_points[i].x = prev.x * m->r_xyz[0][0] + prev.y * m->r_xyz[0][1] + prev.z * m->r_xyz[0][2];
	m->map_points[i].y = prev.x * m->r_xyz[1][0] + prev.y * m->r_xyz[1][1] + prev.z * m->r_xyz[1][2];
	m->map_points[i].z = prev.x * m->r_xyz[2][0] + prev.y * m->r_xyz[2][1] + prev.z * m->r_xyz[2][2];
	m->map_points[i].x += m->width / 2;
	m->map_points[i].y += m->height / 2;
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
		calc_point_x(m, i);

		// prev = m->map_points[i];
		// prev.y -= m->height / 2;
		// m->map_points[i].y = prev.y * cos(angle) - prev.z * sin(angle) +
		// 					m->height / 2;
		// m->map_points[i].z = -prev.y * sin(angle) + prev.z * cos(angle);
		i++;
	}
}

// void			x_rotation(t_mlx *m)
// {
// 	int		i;
// 	double	angle;
// 	t_point	prev;

// 	i = 0;
// 	correct_angles(m);
// 	angle = m->x_angle * M_PI / 180;
// 	while (i < m->quantity_points)
// 	{
// 		prev = m->map_points[i];
// 		prev.y -= m->height / 2;
// 		m->map_points[i].y = prev.y * cos(angle) - prev.z * sin(angle) +
// 							m->height / 2;
// 		m->map_points[i].z = -prev.y * sin(angle) + prev.z * cos(angle);
// 		i++;
// 	}
// }

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
		calc_point_y(m, i);

		// prev = m->map_points[i];
		// prev.x -= shift_x;
		// m->map_points[i].x = prev.x * cos(angle) + prev.z * sin(angle) +
		// 			shift_x;
		// m->map_points[i].z = -prev.x * sin(angle) + prev.z * cos(angle);
		i++;
	}
}

void			calc_rotation_matrix(t_mlx *m)
{

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
		calc_point_z(m, i);

		// prev = m->map_points[i];
		// prev.x -= m->width / 2;
		// prev.y -= m->height / 2;
		// m->map_points[i].x = prev.x * cos(angle) - prev.y * sin(angle) +
		// 			m->width / 2;
		// m->map_points[i].y = prev.x * sin(angle) + prev.y * cos(angle) +
		// 			m->height / 2;
		i++;
	}
}

void			print_rmatrix(double matrix[4][4])
{
	int i, j;

	for(i = 0; i < 4; i++)
	{
		for (j = 0; j < 4; j++)
			ft_printf("%8f ", matrix[i][j]);
		ft_printf("\n");
	}
}
void			rotate_points(t_mlx *m)
{
	int		i;

	// correct_angles(m);
	// calc_r_xyz(m);
	// print_rmatrix(m->r_xyz);

	// i = -1;
	// while (++i < m->quantity_points)
	// {
	// 	calc_point_xyz(m, i);
	// 	ft_printf("i = %d, x=%d, y=%d, z=%d\n", i, m->map_points[i].x, m->map_points[i].y, m->map_points[i].z);
	// }

	if (m->x_angle != 0)
		x_rotation(m);
	if (m->z_angle != 0)
		z_rotation(m);
	if (m->y_angle != 0)
		y_rotation(m);
	i = -1;
	while (++i < m->quantity_points)
	{
		calc_point_xyz(m, i);
		ft_printf("i = %d, x=%d, y=%d, z=%d\n", i, m->map_points[i].x, m->map_points[i].y, m->map_points[i].z);
	}
}
