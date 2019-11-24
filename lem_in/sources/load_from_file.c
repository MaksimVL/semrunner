/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_from_file.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odrinkwa <odrinkwa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/24 16:00:01 by odrinkwa          #+#    #+#             */
/*   Updated: 2019/11/24 16:00:01 by odrinkwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "libft.h"
#include "lemin.h"
#include "mlx.h"
#include "fdf.h"

void			open_file_load_data(t_lemin *lemin, int argc, char **argv)
{
	int		fd;

	if (argc == 1)
		load_data(lemin, 0, 1);
	else if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		load_data(lemin, fd, 1);
		close(fd);
	}
	else
		finish_prog(lemin, -1, -1, NULL);
	if (errno)
		finish_prog(lemin, -1, -1, NULL);
}
