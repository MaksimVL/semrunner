#include "./mlx/mlx.h"
#include "./libft/includes/libft.h"
#include "./includes/fdf.h"

t_point			*get_point(t_mlx *m, int i, int j)
{
	return &(m->map_points[i * m->map_x + j]);
}

void			iso(t_mlx *m, int *x, int *y, int z)
{
	int prev_x;
	int prev_y;
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

	m->min_h = get_point(m, 0, 0)->z;
	m->max_h = get_point(m, 0, 0)->z;
	i = 0;
	while (i < m->map_y)
	{
		j = 0;
		while (j < m->map_x)
		{
			if (get_point(m, i, j)->z > m->max_h)
				m->max_h = get_point(m, i, j)->z;
			if (get_point(m, i, j)->z < m->min_h)
				m->min_h = get_point(m, i, j)->z;
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
	double shift_x;
	double shift_y;
	double step;
	int i;
	int j;

	step = m->width / (m->map_x + 1) < m->height / (m->map_y + 1) ?
			m->width / (m->map_x + 1) : m->height / (m->map_y + 1);
	step *= m->zoom;
	shift_x = (m->width - (m->map_x * step)) / 2;
	shift_y = (m->height - (m->map_y * step)) / 2;
	i = 0;
	while (i < m->map_y)
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
		i++;
	}
	correcting_map(m);
}
