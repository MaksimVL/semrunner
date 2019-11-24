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

void			check_data(t_lemin *l)
{
	// check ant
	if (l->number_of_ants <= 0)
		finish_prog(l, -1, -1, NULL);
	if (l->count_rooms == 0)
		finish_prog(l, -1, -1, NULL);
	if (l->count_edges == 0)
		finish_prog(l, -1, -1, NULL);
	if (l->start_room == -1 || l->end_room == -1)
		finish_prog(l, -1, -1, NULL);
}

int				main(int argc, char **argv)
{
	t_lemin		lemin;

	lemin_init(&lemin);
	errno = 0;
	open_file_load_data(&lemin, argc, argv);
	check_data(&lemin);
	prepare_data(&lemin);
	solve(&lemin);
	if (lemin.count_ways == 0)
		finish_prog(&lemin, -1, -1, NULL);
	print_anthill(&lemin);
	going_ants(&lemin);
	finish_prog(&lemin, 0, -1, NULL);
}
