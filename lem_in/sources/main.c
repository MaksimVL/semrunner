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

int				main(int argc, char **argv)
{
	t_lemin		lemin;

	lemin_init(&lemin);
	errno = 0;
	open_file_load_data(&lemin, argc, argv);
	prepare_data(&lemin);
	solve(&lemin);
	print_anthill(&lemin);
	going_ants(&lemin);
	finish_prog(&lemin, 0, -1, NULL);
}
