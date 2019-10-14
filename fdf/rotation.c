#include "./mlx/mlx.h"
#include "./libft/includes/libft.h"
#include "./includes/fdf.h"

static void		correct_angles(t_mlx *m)
{
	m->x_angle %= 360;
	m->y_angle %= 360;
	m->z_angle %= 360;
}

void			x_rotation(t_mlx *m)
{
	int i;
	int j;
	int shift_y;
	int shift_z;
	double angle;
	t_point prev;

	shift_y = m->height / 2;
	shift_z = 0;

	i = 0;
	correct_angles(m);
	angle = m->x_angle * M_PI / 180;
	while (i < m->map_y)
	{
		j = 0;
		while (j < m->map_x)
		{
			prev = *get_point(m, i, j);
			prev.y -= shift_y;
			prev.z -= shift_z;
			get_point(m, i, j)->y = prev.y * cos(angle) - prev.z * sin(angle) + shift_y;
			get_point(m, i, j)->z = -prev.y * sin(angle) + prev.z * cos(angle) + shift_z;
			j++;
		}
		i++;
	}
}

void			y_rotation(t_mlx *m)
{
	int i;
	int j;
	int shift_x;
	int shift_z;
	double angle;
	t_point prev;

	shift_x = m->width / 2;
	shift_z = 0;

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
			prev.z -= shift_z;
			get_point(m, i, j)->x = prev.x * cos(angle) + prev.z * sin(angle) + shift_x;
			get_point(m, i, j)->z = -prev.x * sin(angle) + prev.z * cos(angle) + shift_z;
			j++;
		}
		i++;
	}
}

void			z_rotation(t_mlx *m)
{
	int i;
	int j;
	int shift_x;
	int shift_y;
	double angle;
	t_point prev;

	shift_x = m->width / 2;
	shift_y = m->height / 2;
	correct_angles(m);
	angle = m->z_angle * M_PI / 180;
	i = 0;
	while (i < m->map_y)
	{
		j = 0;
		while (j < m->map_x)
		{
			prev = *get_point(m, i, j);
			prev.x -= shift_x;
			prev.y -= shift_y;
			get_point(m, i, j)->x = prev.x * cos(angle) - prev.y * sin(angle) + shift_x;
			get_point(m, i, j)->y = prev.x * sin(angle) + prev.y * cos(angle) + shift_y;
			j++;
		}
		i++;
	}
}
