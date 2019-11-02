#include "fdf.h"

void			iso(t_mlx *m, int *x, int *y, int z)
{
	int		prev_x;
	int		prev_y;
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
