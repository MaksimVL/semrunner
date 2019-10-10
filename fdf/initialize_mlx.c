#include "./mlx/mlx.h"
#include "./libft/includes/libft.h"
#include "./includes/fdf.h"

void	tmlx_destroy(t_mlx *m)
{
	if (m->main_im != NULL)
		mlx_destroy_image(m->ptr, m->main_im);
	if (m->win != NULL)
		mlx_destroy_window(m->ptr, m->win);
	if (m->ptr != NULL)
		ft_memdel((void**)m->ptr);
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
	m->point1.x = -1;
	m->point1.y = -1;
	m->point2.x = -1;
	m->point2.y = -1;
	return (1);
}
