#include "libft.h"

void	bin32(unsigned long k)
{
	int i;

	i = 0;
	while (i < 32)
	{
		ft_putchar((k & 0x80000000ULL) ? '1' : '0');
		k <<= 1;
		i++;
	}
}