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
