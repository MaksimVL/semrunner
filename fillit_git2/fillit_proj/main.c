/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwolf <hwolf@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 21:51:44 by odrinkwa          #+#    #+#             */
/*   Updated: 2019/09/18 21:36:08 by hwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "slv_tetr.h"

int	main(int argc, char **argv)
{
	t_fig	figs[26];
	int		fd;
	int		size;

	if (argc != 2 || (fd = open(argv[1], O_RDONLY)) == -1)
	{
		ft_putstr("usage: fillit source_file\n");
		return (0);
	}
	size = read_figs(fd, figs);
	if (size == 0)
	{
		ft_putstr("error\n");
		return (0);
	}
	solve_tetrimino(figs, size);
	return (0);
}
