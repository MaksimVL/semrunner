#include "./mlx/mlx.h"
#include "./libft/includes/libft.h"
#include "./includes/fdf.h"

void	putpixel(t_mlx *m, int x, int y, int color)
{
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
