/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odrinkwa <odrinkwa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 13:19:24 by odrinkwa          #+#    #+#             */
/*   Updated: 2019/11/03 00:19:31 by odrinkwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <math.h>

# define FDF_ANGLE_ROTATE_PRECISION 15

typedef struct		s_point
{
	int				x;
	int				y;
	int				z;
	int				color;
	int				x0;
	int				y0;
	int				z0;
}					t_point;

typedef struct		s_mlx
{
	void			*ptr;
	void			*win;
	void			*main_im;
	int				*data_mainim;
	int				width;
	int				height;
	int				bits_pixel;
	int				size_line;
	int				endian;
	int				*map;
	int				map_x;
	int				map_y;
	int				max_h;
	int				min_h;
	t_point			*map_points;
	int				quantity_points;
	int				zoom_coef;
	double			zoom;
	int				h_coef;
	double			h;
	int				x_angle;
	int				y_angle;
	int				z_angle;
	int				rotate_prec;
	int				angle_projection_type;
	int				prev_ang_proj_type;
	int				projection_type;
	int				prev_proj_type;
	int				camera_x;
	int				camera_y;
	int				type_color_spectrum;
}					t_mlx;

/*
** init and destroy data
** file initialize_mlx.c
*/

void				tmlx_destroy(t_mlx *m, int value_exit);
void				tmlx_initialize(t_mlx *m, int x, int y);
int					tmlx_create_mlx(t_mlx *m, char *title);
void				reset_map(t_mlx *m);

/*
** load data
** file readfile0.c readfile1.c readfile2.c
*/

void				first_check_file(t_mlx *m, char *filename);
void				load_map(t_mlx *m, char *filename);
int					check_file(t_mlx *m, int fd);
int					put_map(t_mlx *m, int fd);
void				set_base_coord(t_mlx *m);
void				calculate_max_min_h_in_map(t_mlx *m);

/*
** working functions
** files legend.c keyhook.c
*/

void				main_legend(t_mlx *m);
int					keyhooks(int keycode, t_mlx *m);
int					check_keyhooks_fdf(int k);

/*
** making map_points from map. it's doing on every iteration, in map_points
** putting base points, than that points changing
** file make_map_points.c
*/

void				make_map_points(t_mlx *m);
void				calc_parameter_maps(t_mlx *m);

void				draw_surface(t_mlx *m, int not_black);

/*
** rotation functions
** file rotation.c
*/

void				z_rotation(t_mlx *m);
void				x_rotation(t_mlx *m);
void				y_rotation(t_mlx *m);
void				rotate_points(t_mlx *m);

/*
** draw pixel, line, figures
** file draw.c draw_point.c get_proj_point.c iso_transform.c
**      fdf_draw_figures.c
*/

void				putpixel(t_mlx *m, int x, int y, int color);
void				putline(t_mlx *m, t_point start, t_point end,
							int not_black);
void				putpoint(t_mlx *m, int i);
t_point				get_point_to_draw(t_mlx *m, int i);
t_point				get_proj_point_to_draw(t_mlx *m, int i);
void				iso(t_mlx *m, int *x, int *y, int z);
void				putbox(t_mlx *m, t_point center, int size, int not_black);
void				put_full_box(t_mlx *m, t_point center, int size, int not_black);
void				putcircle(t_mlx *m, t_point center, int radius,
							int not_black);
void				put_thickcircle(t_mlx *m, t_point center, int radius,
							int not_black);
void				put_full_thickcircle(t_mlx *m, t_point center,
								int radius, int not_black);
void				put_thickline(t_mlx *m, t_point start, t_point end,
							int not_black);

/*
** work with color
** file color.c
*/

double				perc(int start, int end, int curr);
int					calc_gradient(int start, int end, double percent);
int					color_gradient(t_point start, t_point end, double perc);
int					calc_color_spectrum(int type_color_spectrum, int percent);
void				correct_color(t_mlx *m);

#endif
