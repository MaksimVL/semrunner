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
}					t_point;

typedef struct		s_mlx
{
	void 			*ptr;
	void			*win;
	void			*main_im;
	int				*data_mainim;
	int				width;
	int				height;
	int 			bits_pixel;
	int				size_line;
	int				endian;
	int				*map;
	int				map_x;
	int				map_y;
	t_point			*map_points;
	double			zoom;
	double			h;
	int				x_angle;
	int				y_angle;
	int				z_angle;
	int				rotate_prec;
	int				angle_projection_type;
	int 			projection_type;
	int 			max_h;
	int 			min_h;
	int				type_color_spectrum;
}					t_mlx;

void				tmlx_destroy(t_mlx *m, int value_exit);
void				tmlx_initialize(t_mlx *m, int x, int y, char *title);
void				reset_map(t_mlx *m);
void				putpixel(t_mlx *m, int x, int y, int color);
void				putline(t_mlx *m, t_point start, t_point end, int color);
int					check_file(t_mlx *m, int fd);
int					put_map(t_mlx *m, int fd);
t_point				*get_point(t_mlx *m, int i, int j);
void				make_map_points(t_mlx *m, int color);
void				z_rotation(t_mlx *m);
void				x_rotation(t_mlx *m);
void				y_rotation(t_mlx *m);
void				draw_surface(t_mlx *m, int not_black);
int 				color_gradient(t_point start, t_point end, double perc);
void				correct_color(t_mlx *m);
double				perc(int start, int end, int curr);
void				iso(t_mlx *m, int *x, int *y, int z);
t_point				get_proj_point(t_mlx *m, int i, int j);
void 				main_legend(t_mlx *m);
int					keyhook(int keycode, void *m);

#endif
