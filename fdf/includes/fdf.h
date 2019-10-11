#ifndef FDF_H
# define FDF_H

#include <math.h>

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
	int				color;
	t_point			point1;
	t_point			point2;
}					t_mlx;

void				tmlx_destroy(t_mlx *m);
int					tmlx_initialize(t_mlx *m, int x, int y, char *title);
void				putpixel(t_mlx *m, int x, int y, int color);
void				putline(t_mlx *m, t_point start, t_point end, int color);
int					check_file(t_mlx *m, int fd);
int					put_map(t_mlx *m, int fd);
void				putpoint(t_mlx *m, t_point p);
t_point				*get_point(t_mlx *m, int i, int j);
void				draw_surface(t_mlx *m);
void				make_map_points(t_mlx *m, int zoom, int color);
void				make_map_iso_points(t_mlx *m);

#endif
