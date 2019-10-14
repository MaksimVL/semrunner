#include "./mlx/mlx.h"
#include "./libft/includes/libft.h"
#include "./includes/fdf.h"

void	keyhook1(int keycode, void *m)
{
	if (keycode == 13)
		((t_mlx*)m)->zoom *= 1.5;
	else if (keycode == 1)
		((t_mlx*)m)->zoom *= 0.6666667;
	else if (keycode == 2)
		((t_mlx*)m)->h *= 0.6666667;
	else if (keycode == 14)
		((t_mlx*)m)->h *= 1.5;
	else if (keycode == 9)
		((t_mlx*)m)->z_angle -= ((t_mlx*)m)->rotate_prec;
	else if (keycode == 11)
		((t_mlx*)m)->z_angle += ((t_mlx*)m)->rotate_prec;
	else if (keycode == 15)
		((t_mlx*)m)->x_angle -= ((t_mlx*)m)->rotate_prec;
	else if (keycode == 17)
		((t_mlx*)m)->x_angle += ((t_mlx*)m)->rotate_prec;
}

void	keyhook2(int keycode, void *m)
{
	if (keycode == 3)
		((t_mlx*)m)->y_angle -= ((t_mlx*)m)->rotate_prec;
	else if (keycode == 5)
		((t_mlx*)m)->y_angle += ((t_mlx*)m)->rotate_prec;
	else if (keycode == 18)
		((t_mlx*)m)->projection_type = 0;
	else if (keycode == 19)
	((t_mlx*)m)->projection_type = 1;
	else if (keycode == 20)
		((t_mlx*)m)->projection_type = 2;
	else if (keycode == 21)
		((t_mlx*)m)->projection_type = 3;
	else if (keycode == 23)
		((t_mlx*)m)->angle_projection_type =
			++(((t_mlx*)m)->angle_projection_type) % 3;
	else if (keycode == 6)
		((t_mlx*)m)->type_color_spectrum =
			++(((t_mlx*)m)->type_color_spectrum) % 2;
}

int		keyhook(int keycode, void *m)
{
	draw_surface((t_mlx*)m, 0);
	if (keycode == 53 || keycode == 12)
		tmlx_destroy(m, 0);
	else if (keycode == 7)
		reset_map((t_mlx*)m);
	else if (keycode == 13 || keycode == 1 || keycode == 2 || keycode == 14 ||
			keycode == 9 || keycode == 11 || keycode == 15 || keycode == 17)
		keyhook1(keycode, m);
	else
		keyhook2(keycode, m);
	make_map_points((t_mlx*)m, 0xFFFFFF);
	draw_surface((t_mlx*)m, 1);
	mlx_put_image_to_window(((t_mlx*)m)->ptr, ((t_mlx*)m)->win, ((t_mlx*)m)->main_im, 1, 0);
	main_legend(m);
	return (1);
}
