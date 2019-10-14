/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odrinkwa <odrinkwa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 18:48:15 by odrinkwa          #+#    #+#             */
/*   Updated: 2019/10/12 18:40:37 by odrinkwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <fcntl.h>

#include "./mlx/mlx.h"
#include "./libft/includes/libft.h"
#include "./includes/fdf.h"

void	print_map(t_mlx *m)
{
	int		i;
	int		j;

	i = 0;
	while (i < m->map_y)
	{
		j = 0;
		while (j < m->map_x)
		{
			ft_printf("%d ", m->map[i * m->map_x + j]);
			j++;
		}
		ft_printf("\n");
		i++;
	}
}

void	first_check_file(t_mlx *m, char *filename)
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

void	load_map(t_mlx *m, char *filename)
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

int main(int argc, char **argv)
{
	t_mlx	m;

	if (argc != 2)
	{
		ft_printf("usage: fdf map_file\n");
		exit(0);
	}
	tmlx_initialize(&m, 1200, 800, "fdf");
	first_check_file(&m, argv[1]);
	if (!(m.map = (int*)ft_memalloc(sizeof(int) * m.map_x * m.map_y)))
		tmlx_destroy(&m, -1);
	if (!(m.map_points = (t_point*)ft_memalloc(sizeof(t_point) * m.map_x * m.map_y)))
		tmlx_destroy(&m, -1);
	load_map(&m, argv[1]);
	keyhook(-1, (void*)&m);
	mlx_key_hook(m.win, keyhook, (void*)&m);
	mlx_loop(m.ptr);
	return (0);
}
