/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odrinkwa <odrinkwa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 13:15:24 by odrinkwa          #+#    #+#             */
/*   Updated: 2019/10/14 13:18:44 by odrinkwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

double			perc(int start, int end, int curr)
{
	double	place;
	double	dist;

	place = curr - start;
	dist = end - start;
	return (dist == 0) ? 1.0 : (place / dist);
}

static int		calc_gradient(int start, int end, double percent)
{
	return ((int)(start + percent * (end - start)));
}

int				color_gradient(t_point start, t_point end, double perc)
{
	int		red;
	int		green;
	int		blue;

	red = calc_gradient((start.color >> 16) & 0xFF,
			(end.color >> 16) & 0xFF, perc);
	green = calc_gradient((start.color >> 8) & 0xFF,
			(end.color >> 8) & 0xFF, perc);
	blue = calc_gradient(start.color & 0xFF,
			end.color & 0xFF, perc);
	return ((red << 16) | (green << 8) | blue);
}

static int		calc_color_spectrum(t_mlx *m, int percent)
{
	if (m->type_color_spectrum == 0)
	{
		if (0 <= percent && percent <= 70)
			return (0xFFFFFF);
		else
			return (0xFC93F9);
	}
	if (m->type_color_spectrum == 1)
	{
		if (0 <= percent && percent <= 15)
			return (0x006000);
		else if (15 < percent && percent <= 40)
			return (0x5a5a00);
		else if (40 < percent && percent <= 60)
			return (0x733c00);
		else if (60 < percent && percent <= 85)
			return (0x915f50);
		else
			return (0xFFFFFF);
	}
	return (0xFFFFFF);
}

void			correct_color(t_mlx *m)
{
	int i;
	int j;
	int percent;
	int color;

	i = 0;
	while (i < m->map_y)
	{
		j = 0;
		while (j < m->map_x)
		{
			percent = (int)(100.0 * perc(m->min_h, m->max_h,
					m->map[i * m->map_x + j]));
			color = calc_color_spectrum(m, percent);
			get_point(m, i, j)->color = color;
			j++;
		}
		i++;
	}
}
