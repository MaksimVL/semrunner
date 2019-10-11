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
#include <fcntl.h>

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

void	print_map(t_mlx *m)
{
	int		i;
	int		j;

	i = 0;
	while (i < m->map_y)
	{
		j = 0;
		while (j < m->map_x)
		{
			ft_printf("%d ", m->map[i * m->map_x + j]);
			j++;
		}
		ft_printf("\n");
		i++;
	}
}

int main(int argc, char **argv)
{
	t_mlx m;
	int		fd;

	tmlx_initialize(&m, 1000, 1000, "test");

	if (argc != 2)
	{
		ft_printf("usage: fdf map_file\n");
		exit(0);
	}

	fd = open(argv[1], O_RDONLY);
	if (check_file(&m, fd) < 0)
		{
			close(fd);
			return (-1);
		}
	close(fd);

	fd = open(argv[1], O_RDONLY);

//выделяем память под карту
	m.map = (int*)ft_memalloc(sizeof(int) * m.map_x * m.map_y);
	m.map_points = (t_point*)ft_memalloc(sizeof(t_point) * m.map_x * m.map_y); //TODO учесть очистку памяти

	if (put_map(&m, fd) < 0)
	{
		close(fd);
		ft_memdel((void**)m.map);
		ft_memdel((void**)m.map_points);
		return (-1);
	}
	close(fd);

	print_map(&m);

	make_map_points(&m, 0, 0xFFFFFF);
	make_map_iso_points(&m);

	draw_surface(&m);

	mlx_put_image_to_window(m.ptr, m.win, m.main_im, 0, 0);
	mlx_mouse_hook(m.win, mousehook, (void*)&m);
	mlx_key_hook(m.win, keyhook, (void*)&m);
	mlx_loop(m.ptr);
	return (0);
}
