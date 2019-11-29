/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odrinkwa <odrinkwa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 18:48:15 by odrinkwa          #+#    #+#             */
/*   Updated: 2019/11/29 20:50:21 by odrinkwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "libft.h"
#include "lemin.h"
#include "float.h"
#include <stdio.h>

int				main(int argc, char **argv)
{
	t_lemin		lemin;

	lemin_init(&lemin);
	errno = 0;
	open_file_load_data(&lemin, argc, argv);
	set_numbers_rooms(&lemin);
	check_data(&lemin);
	prepare_data(&lemin);
	errno = 0;
	solve(&lemin);
	if (lemin.count_ways == 0 || errno != 0)
		finish_prog(&lemin, -1, -1, NULL);
	print_anthill(&lemin);
	going_ants(&lemin);
	finish_prog(&lemin, 0, -1, NULL);
}
