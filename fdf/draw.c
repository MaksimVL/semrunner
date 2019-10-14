#include "./mlx/mlx.h"
#include "./libft/includes/libft.h"
#include "./includes/fdf.h"

void			putpixel(t_mlx *m, int x, int y, int color)
{
	if ((0 <= x && x < m->width) && (0 <= y && y < m->height))
		m->data_mainim[y * (m->size_line / sizeof(int)) + x] = color;
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
		if (color == 0x0)
			putpixel(m, xy.x, xy.y, color);
		else
			putpixel(m, xy.x, xy.y, color_gradient(start, end, perc(start.x, end.x, xy.x)));
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
		if (color == 0x0)
			putpixel(m, xy.x, xy.y, color);
		else
			putpixel(m, xy.x, xy.y, color_gradient(start, end, perc(start.y, end.y, xy.y)));
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

