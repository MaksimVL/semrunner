#include <stdio.h>
#include <unistd.h>

#include "./mlx/mlx.h"
#include "./libft/includes/libft.h"


typedef struct		s_mlx
{
	void 			*ptr;
	void			*win;
	void			*main_im;
	int				*data_mainim;
	int 			bits_pixel;
	int				size_line;
	int				endian;
}					t_mlx;

/*int deal_key(int key, void *param)
{
	if (param)
	{}
	return (0);
}*/

void	tmlx_destroy(t_mlx *m)
{
	if (m->ptr != NULL)
		ft_memdel((void**)m->ptr);
	if (m->win != NULL)
		ft_memdel((void**)m->win);
	if (m->main_im != NULL)
		ft_memdel((void**)m->main_im);
}

int		tmlx_initialize(t_mlx *m, int x, int y, char *title)
{
	m->bits_pixel = sizeof(int) * 8;
	m->size_line = x * (int)sizeof(int);
	m->endian = 0;
	m->ptr = NULL;
	m->win = NULL;
	m->main_im = NULL;
	if (!(m->ptr = mlx_init()))
		tmlx_destroy(m);
	else if (!(m->win = mlx_new_window(m->ptr, x, y, title)))
		tmlx_destroy(m);
	else if (!(m->main_im = mlx_new_image(m->ptr, x, y)))
		tmlx_destroy(m);
	if (m->ptr == NULL)
		return (0);
	m->data_mainim = (int*)mlx_get_data_addr(m->main_im, &(m->bits_pixel), &(m->size_line), &(m->endian));
	return (1);
}

void	putpixel_mainimage(t_mlx *m, int x, int y, int color)
{
	m->data_mainim[y * (m->size_line / sizeof(int)) + x] = color;
}
int main()
{
	t_mlx m;
	int i;

	printf("test123\n");
	tmlx_initialize(&m, 1000, 1000, "test");

	ft_printf("size_line = %d\n", m.size_line);

	for (i = 0; i < 2000; i++)
		putpixel_mainimage(&m, i, 0, 0xFF0000);

	for (i = 0; i < 1000; i++)
		putpixel_mainimage(&m, i, 1, 0xFFFFFF);
	for (i = 0; i < 1000; i++)
		putpixel_mainimage(&m, i, 2, 0x00FF00);
	mlx_put_image_to_window(m.ptr, m.win, m.main_im, 0, 0);

	mlx_loop(m.ptr);
	return (0);
}

