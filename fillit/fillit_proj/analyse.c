/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   analyse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odrinkwa <odrinkwa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 22:11:56 by hwolf             #+#    #+#             */
/*   Updated: 2019/09/19 00:44:01 by odrinkwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		check(int x1, int y1, int x2, int y2)
{
	if ((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2) == 1)
		return (1);
	return (0);
}

int		analis(t_fig fig)
{
	int i;
	int j;
	int count;

	count = 0;
	i = -1;
	while (++i < 4)
	{
		j = i - 1;
		while (++j < 4)
			count += check(fig.row[i], fig.col[i], fig.row[j], fig.col[j]);
	}
	if (count < 3)
		return (0);
	return (1);
}

int		check_sym(char *str)
{
	int count;

	count = 0;
	while (*str)
	{
		if ((*str) == '#')
			count++;
		else if (*str != '.')
			return (0);
		str++;
	}
	if (count != 4)
		count = 0;
	return (count);
}

void	get_fig(char label, char *line, t_fig *dist)
{
	int tmp;
	int i;
	int j;

	j = 0;
	i = 0;
	tmp = -1;
	(*dist).label = label;
	(*dist).is_set = 0;
	(*dist).row[3] = 0;
	(*dist).col[3] = 0;
	while (line[i])
	{
		if (line[i] == '#')
		{
			if (tmp != -1)
			{
				(*dist).col[j] = i % 4 - tmp % 4;
				(*dist).row[j++] = i / 4 - tmp / 4;
			}
			else
				tmp = i;
		}
		i++;
	}
}
