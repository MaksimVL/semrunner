#include <stdio.h>
#include <unistd.h>

#include "./mlx/mlx.h"
#include "libft.h"

int deal_key(int key, void *param)
{
	if (param)
	{}
	printf("%d", key);
	return (0);
}

int main()
{
	void *mlx_ptr;
	void *win_ptr;
	char *str = "test";

	printf("tes3434aat");
	ft_putchar('a');
	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 640, 480, str);
	mlx_key_hook(win_ptr, deal_key, (void *)0);
	mlx_loop(mlx_ptr);
	return 0;
}

