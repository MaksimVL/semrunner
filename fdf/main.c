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

#include "./mlx/mlx.h"
#include "./libft/includes/libft.h"

typedef struct		s_point
{
	int				x;
	int				y;
}					t_point;

typedef struct		s_mlx
{
	void 			*ptr;
	void			*win;
	void			*main_im;
	int				*data_mainim;
	int 			bits_pixel;
	int				size_line;
	int				endian;
	int				color;
	t_point			point1;
	t_point			point2;
}					t_mlx;

void	tmlx_destroy(t_mlx *m)
{
	if (m->ptr != NULL)
		ft_memdel((void**)m->ptr);
	if (m->win != NULL)
		ft_memdel((void**)m->win);
	if (m->main_im != NULL)
		ft_memdel((void**)m->main_im);
}

int		tmlx_initialize(t_mlx *m, int x, int y, char *title)
{
	m->bits_pixel = sizeof(int) * 8;
	m->size_line = x * (int)sizeof(int);
	m->endian = 0;
	m->ptr = NULL;
	m->win = NULL;
	m->main_im = NULL;
	if (!(m->ptr = mlx_init()))
		tmlx_destroy(m);
	else if (!(m->win = mlx_new_window(m->ptr, x, y, title)))
		tmlx_destroy(m);
	else if (!(m->main_im = mlx_new_image(m->ptr, x, y)))
		tmlx_destroy(m);
	if (m->ptr == NULL)
		return (0);
	m->data_mainim = (int*)mlx_get_data_addr(m->main_im, &(m->bits_pixel), &(m->size_line), &(m->endian));
	m->point1.x = -1;
	m->point1.y = -1;
	m->point2.x = -1;
	m->point2.y = -1;
	return (1);
}

void	putpixel(t_mlx *m, int x, int y, int color)
{
	m->data_mainim[y * (m->size_line / sizeof(int)) + x] = color;
}

void	putline_low(t_mlx *m, t_point start, t_point end, int color)
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

void	putline_high(t_mlx *m, t_point start, t_point end, int color)
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

void	putline(t_mlx *m, t_point start, t_point end, int color)
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
	if (keycode == 53)
	{
		exit(0);
	}
	return (1);
}
int main()
{
	t_mlx m;
	int i;

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
	mlx_put_image_to_window(m.ptr, m.win, m.main_im, 0, 0);

	mlx_mouse_hook(m.win, mousehook, (void*)&m);
	mlx_key_hook(m.win, keyhook, (void*)&m);
	mlx_loop(m.ptr);
	return (0);
}
