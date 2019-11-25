/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odrinkwa <odrinkwa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 18:48:15 by odrinkwa          #+#    #+#             */
/*   Updated: 2019/11/24 22:56:40 by odrinkwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "libft.h"
#include "lemin.h"
#include "float.h"
#include <stdio.h>
#include <time.h>

clock_t llinks;

void			check_data(t_lemin *l)
{
	if (errno != 0)
		finish_prog(l, -1, -1, NULL);
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
	clock_t start, end;

	llinks = 0;
	lemin_init(&lemin);
	errno = 0;
	start = clock();
	open_file_load_data(&lemin, argc, argv);
	check_data(&lemin);
	end = clock();
	ft_printf("%w# load data: %lf\n", 2, ((double)end - (double)start) / (double)(CLOCKS_PER_SEC));
	ft_printf("%w# llinks: %lf\n", 2, ((double)llinks) / (double)(CLOCKS_PER_SEC));
	start = clock();
	prepare_data(&lemin);
	end = clock();
	ft_printf("%w# prepare data: %lf\n", 2, ((double)end - (double)start) / (double)(CLOCKS_PER_SEC));
	start = clock();
	solve(&lemin);
	end = clock();
	ft_printf("%w# solve: %lf\n", 2, ((double)end - (double)start) / (double)(CLOCKS_PER_SEC));
	if (lemin.count_ways == 0)
		finish_prog(&lemin, -1, -1, NULL);
	print_anthill(&lemin);
	going_ants(&lemin);
	finish_prog(&lemin, 0, -1, NULL);
}
