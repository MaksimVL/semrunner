/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   slv_auxf.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odrinkwa <odrinkwa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 21:49:03 by odrinkwa          #+#    #+#             */
/*   Updated: 2019/09/17 22:03:08 by odrinkwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "slv_tetr.h"

char	get_point(t_map *m, int row, int col)
{
	return (m->map[row * (m->size_map + 1) + col]);
}

void	put_point(t_map *m, int row, int col, char c)
{
	m->map[row * (m->size_map + 1) + col] = c;
}

int		check_figure(t_map *m, int row, int col, t_fig *fig)
{
	int i;

	i = 0;
	while (i < 3)
	{
		if (row + fig->row[i] >= m->size_map || row + fig->row[i] < 0)
			return (0);
		if (col + fig->col[i] >= m->size_map || col + fig->col[i] < 0)
			return (0);
		if (get_point(m, row + fig->row[i], col + fig->col[i]) != '.')
			return (0);
		i++;
	}
	return (1);
}

void	put_figure(t_map *m, int row, int col, t_fig *fig)
{
	int i;

	put_point(m, row, col, fig->label);
	i = 0;
	while (i < 3)
	{
		put_point(m, row + fig->row[i], col + fig->col[i], fig->label);
		i++;
	}
	fig->is_set = 1;
}

void	remove_figure(t_map *m, int row, int col, t_fig *fig)
{
	int i;

	put_point(m, row, col, '.');
	i = 0;
	while (i < 3)
	{
		put_point(m, row + fig->row[i], col + fig->col[i], '.');
		i++;
	}
	fig->is_set = 0;
}
