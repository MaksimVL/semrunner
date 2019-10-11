#include "./mlx/mlx.h"
#include "./libft/includes/libft.h"
#include "./includes/fdf.h"

t_point		*get_point(t_mlx *m, int i, int j)
{
	return &(m->map_points[i * m->map_x + j]);
}

void	putpixel(t_mlx *m, int x, int y, int color)
{
	if ((0 <= x && x < m->width) && (0 <= y && y < m->height))
		m->data_mainim[y * (m->size_line / sizeof(int)) + x] = color;
}

void	putpoint(t_mlx *m, t_point p)
{
	putpixel(m, p.x, p.y, p.color);
}

static void		putline_low(t_mlx *m, t_point start, t_point end, int color)
{
	t_point	dxy;
	t_point	xy;
	int		yi;
	int		D;

	dxy.x = end.x - start.x;
	dxy.y = end.y - start.y;
	yi = 1;
	if (dxy.y < 0)
	{
		yi = -1;
		dxy.y = -dxy.y;
	}
	D = 2 * dxy.y - dxy.x;
	xy.y = start.y;
	xy.x = start.x;
	while (xy.x <= end.x)
	{
		putpixel(m, xy.x, xy.y, color);
		if (D > 0)
		{
			xy.y = xy.y + yi;
			D = D - 2 * dxy.x;
		}
		D = D + 2 * dxy.y;
		xy.x++;
	}
}

static void		putline_high(t_mlx *m, t_point start, t_point end, int color)
{
	t_point	dxy;
	t_point	xy;
	int		xi;
	int		D;

	dxy.x = end.x - start.x;
	dxy.y = end.y - start.y;
	xi = 1;
	if (dxy.x < 0)
	{
		xi = -1;
		dxy.x = -dxy.x;
	}
	D = 2 * dxy.x - dxy.y;
	xy.x = start.x;
	xy.y = start.y;
	while (xy.y <= end.y)
	{
		putpixel(m, xy.x, xy.y, color);
		if (D > 0)
		{
			xy.x = xy.x + xi;
			D = D - 2 * dxy.y;
		}
		D = D + 2 * dxy.x;
		xy.y++;
	}
}

void			putline(t_mlx *m, t_point start, t_point end, int color)
{
	if (ABS(end.y - start.y) < ABS(end.x - start.x))
	{
		if (start.x > end.x)
			putline_low(m, end, start, color);
		else
			putline_low(m, start, end, color);
	}
	else
	{
		if (start.y > end.y)
			putline_high(m, end, start, color);
		else
			putline_high(m, start, end, color);
	}
}

void			draw_surface(t_mlx *m)
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
				putline(m, *get_point(m, i, j), *get_point(m, i, j + 1), get_point(m, i, j)->color);
			if (i + 1 < m->map_y)
				putline(m, *get_point(m, i, j), *get_point(m, i + 1, j), get_point(m, i, j)->color);
			j++;
		}
		i++;
	}
}

void iso(int *x, int *y, int z)
{
	int prev_x;
	int prev_y;

	prev_x = *x;
	prev_y = *y;
	*x = (prev_x - prev_y) * cos(30.0 * M_PI / 180.0);
	*y = -z + (prev_x + prev_y) * sin(30.0 * M_PI / 180.0);
}

void iso_point(t_mlx *m, int i, int j)
{
	t_point		*p;
	int			shift_x;
	int			shift_y;

	p = get_point(m, i, j);

	shift_x = m->width / 2;
	shift_y = m->width / 2;

	p->x -= shift_x;
	p->y -= shift_y;
	iso(&(p->x), &(p->y), p->z);
	p->x += shift_x;
	p->y += shift_y;

}

void			make_map_points(t_mlx *m, int zoom, int color)
{
	int shift_x;
	int shift_y;
	int i;
	int j;

	shift_x = m->width / (m->map_x + 1 + zoom * 2);
	shift_y = m->height / (m->map_y + 1 + zoom * 2);
	i = 0;
	while (i < m->map_y)
	{
		j = 0;
		while (j < m->map_x)
		{
			get_point(m, i, j)->x = shift_x * (zoom + 1) + shift_x * j;
			get_point(m, i, j)->y = shift_y * (zoom + 1) + shift_y * i;
			get_point(m, i, j)->z = m->map[i * m->map_y + j];
			get_point(m, i, j)->color = color;
			j++;
		}
		i++;
	}
}

void			make_map_iso_points(t_mlx *m)
{
	int i;
	int j;

	i = 0;
	while (i < m->map_y)
	{
		j = 0;
		while (j < m->map_x)
		{
			iso_point(m, i, j);
			j++;
		}
		i++;
	}
}
