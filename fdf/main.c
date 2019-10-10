/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odrinkwa <odrinkwa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 18:48:15 by odrinkwa          #+#    #+#             */
/*   Updated: 2019/10/09 22:11:34 by odrinkwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <math.h>

#include "./mlx/mlx.h"
#include "./libft/includes/libft.h"
#include "./includes/fdf.h"

int		mousehook(int button, int x, int y, void *m_param)
{
	t_mlx *m;

	m = (t_mlx*)m_param;
	ft_printf("button pressed = %d\n", button);
	ft_printf("x = %d\n", x);
	ft_printf("y = %d\n", y);
	if (button == 1)
		putpixel(m, x, y, 0xFFFFFF);
	else if (button == 2)
	{
		if (m->point1.x == -1)
		{
			m->point1.x = x;
			m->point1.y = y;
		}
		else
		{
			m->point2.x = x;
			m->point2.y = y;
			putline(m, m->point1, m->point2, 0xFFFFFF);
			m->point1.x = -1;
		}
	}
	mlx_put_image_to_window(((t_mlx*)m)->ptr, ((t_mlx*)m)->win, ((t_mlx*)m)->main_im, 0, 0);
	return (1);
}

int		keyhook(int keycode, void *m)
{
	if (m != NULL)
		;
	ft_printf("key pressed = %d\n", keycode);
	if (keycode == 53 || keycode == 12)
	{
		tmlx_destroy(m);
		exit(0);
	}
	return (1);
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


void putline_temp(t_mlx *m, int x0, int y0, int x1, int y1, int color)
{
	t_point p1;
	t_point p2;

	p1.x = x0;
	p1.y = y0;
	p2.x = x1;
	p2.y = y1;
	putline(m, p1, p2, color);

}

int main()
{
	t_mlx m;
	int i;
	int x[6];
	int y[6];

	x[0] = 200; y[0] = 250;
	x[1] = 400; y[1] = 250;
	x[2] = 400; y[2] = 450;
	x[3] = 200; y[3] = 450;
	x[4] = x[0]; y[4] = y[0];
	x[5] = 300;
	y[5] = 150;

	printf("test123\n");
	tmlx_initialize(&m, 1000, 1000, "test");

	ft_printf("size_line = %d\n", m.size_line);

	for (i = 0; i < 2000; i++)
		putpixel(&m, i, 0, 0xFF0000);

	for (i = 0; i < 1000; i++)
		putpixel(&m, i, 1, 0xFFFFFF);
	for (i = 0; i < 1000; i++)
		putpixel(&m, i, 2, 0x00FF00);

	t_point	start;
	t_point	end;

	start.x = 10;
	start.y = 10;
	end.x = 400;
	end.y = 400;
	void *param;
	param = (void*)(&i);
	putline(&m, start, end, 0xFFFFFF);

	for (i = 0; i < 4; i++)
	{
		putline_temp(&m, x[i], y[i], x[i+1], y[i+1], 0xFF0000);
	}
	putline_temp(&m, x[0], y[0], x[5], y[5], 0xFF0000);
	putline_temp(&m, x[5], y[5], x[1], y[1], 0xFF0000);

	t_point center;
	center.x = 300;
	center.y = 350;

	for (i = 0; i < 6; i++)
	{
		x[i] -= center.x;
		y[i] -= center.y;
	}

	for (i = 0; i < 6; i++)
	{
		iso(&x[i], &y[i], 0);
	}

	for (i = 0; i < 6; i++)
	{
		x[i] += center.x;
		y[i] += center.y;
	}

	for (i = 0; i < 4; i++)
	{
		putline_temp(&m, x[i], y[i], x[i+1], y[i+1], 0xFFFFFF);
	}


	putline_temp(&m, x[0], y[0], x[5], y[5], 0xFFFFFF);
	putline_temp(&m, x[5], y[5], x[1], y[1], 0xFFFFFF);



	mlx_put_image_to_window(m.ptr, m.win, m.main_im, 0, 0);

	mlx_mouse_hook(m.win, mousehook, (void*)&m);
	mlx_key_hook(m.win, keyhook, (void*)&m);
	mlx_loop(m.ptr);
	return (0);
}
