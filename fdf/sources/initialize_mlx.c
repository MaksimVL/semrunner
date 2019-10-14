/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_mlx.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odrinkwa <odrinkwa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 13:11:45 by odrinkwa          #+#    #+#             */
/*   Updated: 2019/10/14 17:12:00 by odrinkwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "libft.h"
#include "fdf.h"

void	tmlx_destroy(t_mlx *m, int value_exit)
{
	if (m->main_im != NULL)
		mlx_destroy_image(m->ptr, m->main_im);
	if (m->win != NULL)
		mlx_destroy_window(m->ptr, m->win);
	if (m->ptr != NULL)
		ft_memdel((void**)&(m->ptr));
	if (m->map != NULL)
		ft_memdel((void**)&(m->map));
	if (m->map_points != NULL)
		ft_memdel((void**)&(m->map_points));
	exit(value_exit);
}

void	reset_map(t_mlx *m)
{
	m->zoom = 1;
	m->h = 1;
	m->x_angle = 0;
	m->y_angle = 0;
	m->z_angle = 0;
	m->projection_type = 0;
	m->type_color_spectrum = 1;
}

void	tmlx_initialize(t_mlx *m, int x, int y)
{
	m->bits_pixel = sizeof(int) * 8;
	m->size_line = x * (int)sizeof(int);
	m->endian = 0;
	m->ptr = NULL;
	m->win = NULL;
	m->main_im = NULL;
	m->data_mainim = NULL;
	m->map = NULL;
	m->map_points = NULL;
	m->width = x;
	m->height = y;
	m->map_x = 0;
	m->map_y = 0;
	reset_map(m);
	m->rotate_prec = FDF_ANGLE_ROTATE_PRECISION;
	m->angle_projection_type = 0;
	m->projection_type = 0;
}

void	tmlx_create_mlx(t_mlx *m, char *title)
{
	if (!(m->ptr = mlx_init()))
		tmlx_destroy(m, -1);
	else if (!(m->win = mlx_new_window(m->ptr, m->width, m->height, title)))
		tmlx_destroy(m, -1);
	else if (!(m->main_im = mlx_new_image(m->ptr, m->width, m->height)))
		tmlx_destroy(m, -1);
	m->data_mainim = (int*)mlx_get_data_addr(m->main_im,
											 &(m->bits_pixel), &(m->size_line), &(m->endian));
}