/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   legend.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odrinkwa <odrinkwa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 12:47:01 by odrinkwa          #+#    #+#             */
/*   Updated: 2019/10/14 15:44:58 by odrinkwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "libft.h"
#include "fdf.h"

static void		strcatnbr(char *str, int nbr)
{
	char *tmp_str;

	tmp_str = ft_itoa(nbr);
	ft_strcat(str, tmp_str);
	ft_memdel((void**)&tmp_str);
}

static void		curr_cond_legend(t_mlx *m, int color)
{
	char	str[100];

	str[0] = '\0';
	if (m->projection_type == 0)
		ft_strcat(str, "curr_cond: proj: ISO, ");
	else if (m->projection_type == 1)
		ft_strcat(str, "curr_cond: proj: z, ");
	else if (m->projection_type == 2)
		ft_strcat(str, "curr_cond: proj: x, ");
	else if (m->projection_type == 3)
		ft_strcat(str, "curr_cond: proj: y, ");
	if (m->angle_projection_type == 0)
		ft_strcat(str, "angle of proj = 26.57, ");
	else if (m->angle_projection_type == 1)
		ft_strcat(str, "angle of proj = 30.00, ");
	else if (m->angle_projection_type == 2)
		ft_strcat(str, "angle of proj = 45.00, ");
	ft_strcat(str, "x_ang = ");
	strcatnbr(str, m->x_angle);
	ft_strcat(str, ", y_ang = ");
	strcatnbr(str, m->y_angle);
	ft_strcat(str, ", z_ang = ");
	strcatnbr(str, m->z_angle);
	mlx_string_put(m->ptr, m->win, 10, 10, color, str);
}

void			main_legend(t_mlx *m)
{
	int color;

	color = 0x5f5e70;
	curr_cond_legend(m, color);
	mlx_string_put(m->ptr, m->win, 10, 30, color,
			"projection: 1: ISO, 2: z, 3: x, 4: y, 5: change ISO angle");
	mlx_string_put(m->ptr, m->win, 10, 47, color, "up, down: +-zoom");
	mlx_string_put(m->ptr, m->win, 10, 64, color, "r, f: +-height");
	mlx_string_put(m->ptr, m->win, 10, 81, color, "w, s: x_rotation");
	mlx_string_put(m->ptr, m->win, 10, 98, color, "a, d: y_rotation");
	mlx_string_put(m->ptr, m->win, 10, 115, color, "left, right: z_rotation");
	mlx_string_put(m->ptr, m->win, 10, 132, color, "x: reset map");
	mlx_string_put(m->ptr, m->win, 10, 149, color, "z: change color spectrum");
	mlx_string_put(m->ptr, m->win, 10, 166, color, "q, esc: exit");
}
