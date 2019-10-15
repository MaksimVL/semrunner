/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyhook.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odrinkwa <odrinkwa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 12:40:57 by odrinkwa          #+#    #+#             */
/*   Updated: 2019/10/14 14:12:29 by odrinkwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "libft.h"
#include "fdf.h"

void	keyhook1(int keycode, t_mlx *m)
{
	if (keycode == 126)
	{
		if (m->zoom < 1000 && m->h < 10000)
		{
			m->zoom *= 1.5;
			m->h *= 1.5;
		}
	}
	else if (keycode == 125)
	{
		if (m->zoom > 0.001 && m->h > 0.0001)
		{
			m->zoom *= 0.6666667;
			m->h *= 0.6666667;
		}
	}
	else if (keycode == 123)
		m->z_angle -= m->rotate_prec;
	else if (keycode == 124)
		m->z_angle += m->rotate_prec;
	else if (keycode == 13)
		m->x_angle -= m->rotate_prec;
	else if (keycode == 1)
		m->x_angle += m->rotate_prec;
}

void	keyhook2(int keycode, t_mlx *m)
{
	if (keycode == 0)
		m->y_angle -= m->rotate_prec;
	else if (keycode == 2)
		m->y_angle += m->rotate_prec;
	else if (keycode == 18)
		m->projection_type = 0;
	else if (keycode == 19)
		m->projection_type = 1;
	else if (keycode == 20)
		m->projection_type = 2;
	else if (keycode == 21)
		m->projection_type = 3;
	else if (keycode == 23)
		m->angle_projection_type =
			++(m->angle_projection_type) % 3;
	else if (keycode == 6)
		m->type_color_spectrum =
			++(m->type_color_spectrum) % 2;
}

void	keyhook3(int keycode, t_mlx *m)
{
	if (keycode == 32)
		m->camera_y += 40 * m->zoom;
	else if (keycode == 38)
		m->camera_y -= 40 * m->zoom;
	else if (keycode == 4)
		m->camera_x += 40 * m->zoom;
	else if (keycode == 40)
		m->camera_x -= 40 * m->zoom;
	else if (keycode == 3)
		m->h *= (m->h > 0.001) ? 0.6666667 : 1;
	else if (keycode == 15)
		m->h *= (m->h < 1000) ? 1.5 : 1;
}

int		keyhook(int keycode, void *m)
{
	draw_surface((t_mlx*)m, 0);
	if (keycode == 53 || keycode == 12)
		tmlx_destroy((t_mlx*)m, 0);
	else if (keycode == 7)
		reset_map((t_mlx*)m);
	keyhook1(keycode, (t_mlx*)m);
	keyhook2(keycode, (t_mlx*)m);
	keyhook3(keycode, (t_mlx*)m);
	make_map_points((t_mlx*)m, 0xFFFFFF);
	draw_surface((t_mlx*)m, 1);
	mlx_put_image_to_window(((t_mlx*)m)->ptr, ((t_mlx*)m)->win,
							((t_mlx*)m)->main_im, 1, 0);
	main_legend(m);
	return (1);
}
