/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readfile0.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odrinkwa <odrinkwa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/02 16:35:48 by odrinkwa          #+#    #+#             */
/*   Updated: 2019/11/02 16:35:50 by odrinkwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "fdf.h"
#include "libft.h"

void			first_check_file(t_mlx *m, char *filename)
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

void			load_map(t_mlx *m, char *filename)
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
