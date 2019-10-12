#include "./mlx/mlx.h"
#include "./libft/includes/libft.h"
#include "./includes/fdf.h"

double			perc(int start, int end, int curr)
{
	double	place;
	double	dist;

	place = curr - start;
	dist = end - start;
	return (dist == 0) ? 1.0 : (place / dist);
}

static int		calc_gradient(int start, int end, double percent)
{
	return ((int)((1 - percent) * start + percent * end));
}

int 			color_gradient(t_point start, t_point end, double perc)
{
	int		red;
	int 	green;
	int 	blue;

	red = calc_gradient((start.color >> 16) & 0xFF, (end.color >> 16) & 0xFF, perc);
	green = calc_gradient((start.color >> 8) & 0xFF, (end.color >> 8) & 0xFF, perc);
	blue = calc_gradient(start.color & 0xFF, end.color & 0xFF, perc);
	return ((red << 16) | (green << 8) | blue);
}

void			correct_color(t_mlx *m)
{
	int i;
	int j;
	int percent;
	int color;

	i = 0;
	while (i < m->map_y)
	{
		j = 0;
		while (j < m->map_x)
		{
			percent = (int)(100.0 * perc(m->min_h, m->max_h, get_point(m, i, j)->z));
			if (0 <= percent && percent <= 15)
				color = 0x006000; //green
			else if (15 < percent && percent <= 40)
				color = 0x5a5a00;
			else if (40 < percent && percent <= 60)
				color = 0x733c00;
			else if (60 < percent && percent <= 85)
				color = 0x915f50;
			else
				color = 0xFFFFFF;
			get_point(m, i, j)->color = color;
			j++;
		}
		i++;
	}
}