#ifndef FDF_H
# define FDF_H

typedef struct		s_point
{
	int				x;
	int				y;
}					t_point;

typedef struct		s_mlx
{
	void 			*ptr;
	void			*win;
	void			*main_im;
	int				*data_mainim;
	int 			bits_pixel;
	int				size_line;
	int				endian;
	int				color;
	t_point			point1;
	t_point			point2;
}					t_mlx;

void				tmlx_destroy(t_mlx *m);
int					tmlx_initialize(t_mlx *m, int x, int y, char *title);
void				putpixel(t_mlx *m, int x, int y, int color);
void				putline(t_mlx *m, t_point start, t_point end, int color);

#endif
