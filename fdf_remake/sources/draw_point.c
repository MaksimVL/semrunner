#include "fdf.h"

void			putpoint(t_mlx *m, int i)
{
	t_point tmp;

	tmp = get_point_to_draw(m, i);
	putpixel(m, tmp.x, tmp.y, tmp.color);
}

t_point			get_point_to_draw(t_mlx *m, int i)
{
	t_point		res;

	res = get_proj_point_to_draw(m, i);
	res.x += m->camera_x;
	res.y += m->camera_y;
	return (res);
}
