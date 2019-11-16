/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odrinkwa <odrinkwa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 18:48:15 by odrinkwa          #+#    #+#             */
/*   Updated: 2019/11/16 22:31:43 by odrinkwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "libft.h"
#include "lemin.h"
#include "mlx.h"
#include "fdf.h"
#include "float.h"
#include <stdio.h>

void			open_file_load_data(t_lemin *lemin, int argc, char **argv)
{
	int		fd;

	if (argc == 1)
		load_data(lemin, 0, 0);
	else if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		load_data(lemin, fd, 0);
		close(fd);
	}
	else
		finish_prog(lemin, -1, -1, NULL);
}

int				main(int argc, char **argv)
{
	t_lemin		lemin;
	// t_mlx		m;
	// t_lemin_mlx	lm;

	lemin_init(&lemin);
	errno = 0;
	open_file_load_data(&lemin, argc, argv);
	prepare_data(&lemin);
	solve(&lemin);
	print_anthill(&lemin);
	going_ants(&lemin);
	// tmlx_initialize(&m, 1800, 1200);
	// load_anthill(&m, &lemin);
	// calc_parameter_maps(&m);
	// make_map_points(&m);

	// lm.m = &m;
	// lm.lem = &lemin;

	// tmlx_create_mlx(&m, "lemin");

	// lemin_keyhook(-1, (void*)&lm);
	// mlx_key_hook(m.win, lemin_keyhook, (void*)&lm);
	// mlx_loop_hook(m.ptr, test_func, (void*)&lm);
	// mlx_loop(m.ptr);
	finish_prog(&lemin, 0, -1, NULL);
}
