/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odrinkwa <odrinkwa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 18:48:15 by odrinkwa          #+#    #+#             */
/*   Updated: 2019/10/16 19:01:47 by odrinkwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>

#include "mlx.h"
#include "libft.h"
#include "fdf.h"

static void		first_check_file(t_mlx *m, char *filename)
{
	int fd;
	int res;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		ft_printf("%werror open file\n", 2);
		tmlx_destroy(m, -1);
	}
	res = check_file(m, fd);
	close(fd);
	if (res < 0)
	{
		ft_printf("%werror read file\n", 2);
		tmlx_destroy(m, -1);
	}
}

static void		load_map(t_mlx *m, char *filename)
{
	int fd;
	int res;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		ft_printf("%werror open file\n", 2);
		tmlx_destroy(m, -1);
	}
	res = put_map(m, fd);
	close(fd);
	if (res < 0)
	{
		ft_printf("%error load map\n", 2);
		tmlx_destroy(m, -1);
	}
}

int				main(int argc, char **argv)
{
	t_mlx	m;

	if (argc != 2)
	{
		ft_printf("usage: fdf map_file\n");
		exit(0);
	}
	tmlx_initialize(&m, 1400, 800);
	first_check_file(&m, argv[1]);
	if (!(m.map = (int*)ft_memalloc(sizeof(int) * m.map_x * m.map_y)))
		tmlx_destroy(&m, -1);
	if (!(m.map_points = (t_point*)ft_memalloc(sizeof(t_point) *
			m.map_x * m.map_y)))
		tmlx_destroy(&m, -1);
	load_map(&m, argv[1]);
	tmlx_create_mlx(&m, "fdf");
	keyhook(-1, (void*)&m);
	mlx_key_hook(m.win, keyhook, (void*)&m);
	mlx_loop(m.ptr);
	exit(0);
}
