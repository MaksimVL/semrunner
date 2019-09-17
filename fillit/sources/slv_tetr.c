/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solvetet.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odrinkwa <odrinkwa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 21:45:42 by odrinkwa          #+#    #+#             */
/*   Updated: 2019/09/17 22:02:08 by odrinkwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "slv_tetr.h"

void			printmap(t_map *m)
{
	int i;

	i = 0;
	while (m->map[i])
	{
		ft_putchar(m->map[i]);
		i++;
	}
}

static int		count_side_minimal_map(int count_figures)
{
	int count_boxes;
	int i;

	count_boxes = count_figures * 4;
	i = 1;
	while (i * i < count_boxes)
		i++;
	return (i);
}

static void		initialize_map(char *map, int size_map)
{
	int i;
	int j;

	i = 0;
	while (i < size_map)
	{
		j = 0;
		while (j < size_map)
		{
			map[i * (size_map + 1) + j] = '.';
			j++;
		}
		map[i * (size_map + 1) + j] = '\n';
		i++;
	}
	map[i * (size_map + 1) + size_map] = '\0';
}

static int		solve_recursion(t_map *m, t_fig figs[26],
								int count_figures, int i_figs)
{
	int		row;
	int		col;

	if (i_figs == count_figures)
		return (1);
	row = -1;
	while (++row < m->size_map)
	{
		col = -1;
		while (++col < m->size_map)
		{
			if (get_point(m, row, col) == '.')
				if (check_figure(m, row, col, &figs[i_figs]))
				{
					put_figure(m, row, col, &figs[i_figs]);
					if (solve_recursion(m, figs, count_figures,
							i_figs + 1) == 1)
						return (1);
					else
						remove_figure(m, row, col, &figs[i_figs]);
				}
		}
	}
	return (0);
}

int				solve_tetrimino(t_fig figs[], int count_figures)
{
	t_map	*m;
	char	*map;
	int		size_map;

	m = (t_map*)ft_memalloc(sizeof(t_map));
	m->map = (char*)ft_memalloc(sizeof(char) * (21 * 21 + 1));
	m->size_map = count_side_minimal_map(count_figures);
	initialize_map(m->map, m->size_map);
	printmap(m);
	while (solve_recursion(m, figs, count_figures, 0) == 0)
	{
		m->size_map++;
		initialize_map(m->map, m->size_map);
	}
	ft_putchar('\n');
	printmap(m);
	free(m->map);
	free(m);
	return (0);
}
