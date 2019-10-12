/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odrinkwa <odrinkwa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 18:48:15 by odrinkwa          #+#    #+#             */
/*   Updated: 2019/10/12 18:40:37 by odrinkwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <math.h>
#include <fcntl.h>

#include "./mlx/mlx.h"
#include "./libft/includes/libft.h"
#include "./includes/fdf.h"

void 	main_legend(t_mlx *m)
{
	mlx_string_put(m->ptr, m->win, 10, 10, 0x5f5e70,
				   "projection: 1: ISO, 2: z, 3: x, 4: y");
	mlx_string_put(m->ptr, m->win, 10, 30, 0x5f5e70, "w, s: +-zoom");
	mlx_string_put(m->ptr, m->win, 10, 50, 0x5f5e70, "e, d: +-height");
	mlx_string_put(m->ptr, m->win, 10, 70, 0x5f5e70, "r, t: x rotation");
	mlx_string_put(m->ptr, m->win, 10, 90, 0x5f5e70, "f, g: y_rotation");
	mlx_string_put(m->ptr, m->win, 10, 110, 0x5f5e70, "v, b: z_rotation");
	mlx_string_put(m->ptr, m->win, 10, 130, 0x5f5e70, "q, esc: exit");
}

int		mousehook(int button, int x, int y, void *m_param)
{
	t_mlx *m;

	m = (t_mlx*)m_param;
	ft_printf("button pressed = %d\n", button);
	ft_printf("x = %d\n", x);
	ft_printf("y = %d\n", y);
	return (1);
}

int		keyhook(int keycode, void *m)
{
	if (m != NULL)
		;
	ft_printf("key pressed = %d\n", keycode);
	if (keycode == 53 || keycode == 12)
	{
		tmlx_destroy(m, 0);
	}
	if (keycode == 13)
		((t_mlx*)m)->zoom -= 1;
	else if (keycode == 1)
		((t_mlx*)m)->zoom += 1;
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
	else if (keycode == 3)
		((t_mlx*)m)->y_angle -= ((t_mlx*)m)->rotate_prec;
	else if (keycode == 5)
		((t_mlx*)m)->y_angle += ((t_mlx*)m)->rotate_prec;
	draw_surface((t_mlx*)m, 0);

	if (keycode == 18)
		((t_mlx*)m)->projection_type = 0;
	else if (keycode == 19)
	((t_mlx*)m)->projection_type = 1;
	else if (keycode == 20)
		((t_mlx*)m)->projection_type = 2;
	else if (keycode == 21)
		((t_mlx*)m)->projection_type = 3;

	make_map_points((t_mlx*)m, 0xFFFFFF);
	draw_surface((t_mlx*)m, 1);
	mlx_put_image_to_window(((t_mlx*)m)->ptr, ((t_mlx*)m)->win, ((t_mlx*)m)->main_im, 1, 0);
	main_legend(m);
	return (1);
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
	t_mlx	m;
	int		fd;
	int		res;

	if (argc != 2)
	{
		ft_printf("usage: fdf map_file\n");
		exit(0);
	}

	tmlx_initialize(&m, 1200, 1200, "fdf");
	fd = open(argv[1], O_RDONLY);
	res = check_file(&m, fd);
	close(fd);
	if (res < 0)
		{
			ft_printf("%werror read file\n", 2);
			tmlx_destroy(&m, -1);
		}

	if (!(m.map = (int*)ft_memalloc(sizeof(int) * m.map_x * m.map_y)))
		tmlx_destroy(&m, -1);
	if (!(m.map_points = (t_point*)ft_memalloc(sizeof(t_point) * m.map_x * m.map_y)))
		tmlx_destroy(&m, -1);

	fd = open(argv[1], O_RDONLY);
	res = put_map(&m, fd);
	close(fd);
	if (res < 0)
		tmlx_destroy(&m, -1);
	print_map(&m);
	keyhook(-1, (void*)&m);
	mlx_mouse_hook(m.win, mousehook, (void*)&m);
	mlx_key_hook(m.win, keyhook, (void*)&m);
	mlx_loop(m.ptr);
	return (0);
}
