#include <stdio.h>
#include <unistd.h>

#include "./mlx/mlx.h"
#include "./libft/includes/libft.h"


typedef struct		s_mlx
{
	void 			*ptr;
	void			*win;
	void			*im;
}					t_mlx;

int deal_key(int key, void *param)
{
	if (param)
	{}
	printf("%d", key);
	return (0);
}

void	tmlx_destroy(t_mlx *m)
{
	if (m->ptr != NULL)
		ft_memdel((void**)m->ptr);
	if (m->win != NULL)
		ft_memdel((void**)m->win);
	if (m->im != NULL)
		ft_memdel((void**)m->im);
}

int		tmlx_initialize(t_mlx *m, int x, int y, char *title)
{
	m->ptr = NULL;
	m->win = NULL;
	m->im = NULL;
	if (!(m->ptr = mlx_init()))
		tmlx_destroy(m);
	if (!(m->win = mlx_new_window(m->ptr, x, y, title)))
		tmlx_destroy(m);
	if (!(m->im = mlx_new_image(m->ptr, x, y)))
		tmlx_destroy(m);

}

int main()
{
	t_mlx m;

	tmlx_initialize(&m, 1000, 1000, "test");
	mlx_loop(m.ptr);
	return (0);
}

