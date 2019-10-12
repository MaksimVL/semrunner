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

	prev_x = *x;
	prev_y = *y;
	*x = (prev_x - prev_y) * cos(m->angle_projection * M_PI / 180.0);
	*y = -z + (prev_x + prev_y) * sin(m->angle_projection * M_PI / 180.0);
}

void 			calculate_max_min_h(t_mlx *m)
{
	int i;
	int j;
	int max_h;
	int min_h;

	min_h = get_point(m, 0, 0)->z;
	max_h = get_point(m, 0, 0)->z;
	i = 0;
	while (i < m->map_y)
	{
		j = 0;
		while (j < m->map_x)
		{
			if (get_point(m, i, j)->z > max_h)
				max_h = get_point(m, i, j)->z;
			if (get_point(m, i, j)->z < min_h)
				min_h = get_point(m, i, j)->z;
			j++;
		}
		i++;
	}
	m->max_h = max_h;
	m->min_h = min_h;
}

void			make_map_points(t_mlx *m, int color)
{
	int shift_x;
	int shift_y;
	int i;
	int j;

	if ((m->map_x + 1 + m->zoom * 2) <= 0 || (m->map_y + 1 + m->zoom * 2) <= 0)
		m->zoom +=1;

	shift_x = m->width / (m->map_x + 1 + m->zoom * 2);
	shift_y = m->height / (m->map_y + 1 + m->zoom * 2);
	i = 0;
	while (i < m->map_y)
	{
		j = 0;
		while (j < m->map_x)
		{
			get_point(m, i, j)->x = shift_x * (m->zoom + 1) + shift_x * j;
			get_point(m, i, j)->y = shift_y * (m->zoom + 1) + shift_y * i;
			get_point(m, i, j)->z = m->map[i * m->map_x + j] * m->h;
			get_point(m, i, j)->color = color;
			j++;
		}
		i++;
	}
	calculate_max_min_h(m);
	correct_color(m);

	if (m->x_angle != 0)
		x_rotation(m);
	if (m->z_angle != 0)
		z_rotation(m);
	if (m->y_angle != 0)
		y_rotation(m);

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
				putline(m, get_proj_point(m, i, j), get_proj_point(m, i, j + 1), not_black);
			if (i + 1 < m->map_y)
				putline(m, get_proj_point(m, i, j), get_proj_point(m, i + 1, j), not_black);
			j++;
		}
		i++;
	}
}
