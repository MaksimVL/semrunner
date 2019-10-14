#include "./mlx/mlx.h"
#include "./libft/includes/libft.h"
#include "./includes/fdf.h"

static void		curr_cond_legend(t_mlx *m, int color)
{
	char	str[50];
	char	str1[100];

	str[0] = '\0';
	str1[0] = '\0';
	if (m->projection_type == 0)
		ft_strcat(str, "proj: ISO, ");
	else if (m->projection_type == 1)
		ft_strcat(str, "proj: z, ");
	else if (m->projection_type == 2)
		ft_strcat(str, "proj: x, ");
	else if (m->projection_type == 3)
		ft_strcat(str, "proj: y, ");
	if (m->angle_projection_type == 0)
		ft_strcat(str, "angle of proj = 26.57, ");
	else if (m->angle_projection_type == 1)
		ft_strcat(str, "angle of proj = 30.00, ");
	else if (m->angle_projection_type == 2)
		ft_strcat(str, "angle of proj = 45.00, ");
	ft_printf("%ycurr_cond: %szoom=%.2f, height=%.2f, x_angle = %d, y_angle = %d, z_angle = %d",
		str1, str, m->zoom, m->h, m->x_angle, m->y_angle, m->z_angle);
	mlx_string_put(m->ptr, m->win, 10, 10, color, str1);
}

void 			main_legend(t_mlx *m)
{
	int color;

	color = 0x5f5e70;
	curr_cond_legend(m, color);
	mlx_string_put(m->ptr, m->win, 10, 30, color,
				   "projection: 1: ISO, 2: z, 3: x, 4: y, 5: change ISO angle");
	mlx_string_put(m->ptr, m->win, 10, 47, color, "w, s: +-zoom");
	mlx_string_put(m->ptr, m->win, 10, 64, color, "e, d: +-height");
	mlx_string_put(m->ptr, m->win, 10, 81, color, "r, t: x_rotation");
	mlx_string_put(m->ptr, m->win, 10, 98, color, "f, g: y_rotation");
	mlx_string_put(m->ptr, m->win, 10, 115, color, "v, b: z_rotation");
	mlx_string_put(m->ptr, m->win, 10, 132, color, "x: reset map");
	mlx_string_put(m->ptr, m->win, 10, 149, color, "z: change color spectrum");
	mlx_string_put(m->ptr, m->win, 10, 166, color, "q, esc: exit");
}
