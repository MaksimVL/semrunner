#include "libft.h"

void			vector_int_assign(int *vector, int len, int value)
{
	int i;

	i = 0;
	while (i < len)
	{
		vector[i] = value;
		i++;
	}
}

void			vector_int_print(int *vector, int len)
{
	int i;

	i = 0;
	while (i < len)
	{
		ft_printf("%d ", vector[i]);
		i++;
	}
	ft_printf("\n");
}
