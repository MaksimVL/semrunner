/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_proj_point.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odrinkwa <odrinkwa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 12:46:34 by odrinkwa          #+#    #+#             */
/*   Updated: 2019/10/14 12:46:35 by odrinkwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static t_point	get_iso_point(t_mlx *m, int i, int j)
{
	t_point		p;
	int			shift_x;
	int			shift_y;

	p = *get_point(m, i, j);
	shift_x = m->width / 2;
	shift_y = m->height / 2;
	p.x -= shift_x;
	p.y -= shift_y;
	iso(m, &(p.x), &(p.y), p.z);
	p.x += shift_x;
	p.y += shift_y;
	return (p);
}

static t_point	get_zproj_point(t_mlx *m, int i, int j)
{
	t_point		p;

	p = *get_point(m, i, j);
	return (p);
}

static t_point	get_xproj_point(t_mlx *m, int i, int j)
{
	t_point		p;
	int			shift_z;
	int			prev;

	p = *get_point(m, i, j);
	shift_z = m->width / 2;
	prev = p.x;
	p.x = p.z + shift_z;
	p.z = -prev;
	return (p);
}

static t_point	get_yproj_point(t_mlx *m, int i, int j)
{
	t_point		p;
	int			shift_z;
	int			prev;

	p = *get_point(m, i, j);
	shift_z = m->height / 2;
	prev = p.y;
	p.y = -p.z + shift_z;
	p.z = -prev;
	return (p);
}

t_point			get_proj_point(t_mlx *m, int i, int j)
{
	if (m->projection_type == 1)
		return (get_zproj_point(m, i, j));
	else if (m->projection_type == 2)
		return (get_xproj_point(m, i, j));
	else if (m->projection_type == 3)
		return (get_yproj_point(m, i, j));
	return (get_iso_point(m, i, j));
}
