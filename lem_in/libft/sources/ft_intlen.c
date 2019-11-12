#include "libft.h"

int			ft_intlen(int a)
{
	char	*s;
	int		tmp;

	s = ft_itoa(a);
	tmp = ft_strlen(s);
	ft_memdel((void**)&s);
	return (tmp);
}
