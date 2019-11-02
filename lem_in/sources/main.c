/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odrinkwa <odrinkwa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 18:48:15 by odrinkwa          #+#    #+#             */
/*   Updated: 2019/10/26 19:02:50 by odrinkwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "libft.h"
#include "lemin.h"

# define MAX_N 50

int				main(int argc, char **argv)
{
	t_lemin		lemin;
	int res;

	lemin_init(&lemin);

	load_data(&lemin); //TODO проверка на чтение, полная очистка если ошибка
	lemin.number_of_ants = 1;
	set_rooms_number(&lemin);
	lemin.count_edges = ft_dlst_len(lemin.room_ways);
	edges_assign(&lemin);
	lemin_init_arrays(&lemin);
	print_all_rooms_property(lemin.list_rooms);
	print_all_links(lemin.room_ways);
	print_all_edges(&lemin);

	lemin_fill_matrix(&lemin);
	min_cost_f(&lemin);
	lemin_print_res(&lemin);

	print_intmatrix(lemin.flow, lemin.count_rooms, lemin.count_rooms);



	lemin_destroy(&lemin); // TODO хуйня какая то, надо разобраться с очисткой листов. ну да похуй, это можно позже сделать
}
