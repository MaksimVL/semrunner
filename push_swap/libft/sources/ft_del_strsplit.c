#include "libft.h"

void			ft_del_strsplit(char **strings)
{
	int		i;

	if (strings == NULL)
		return ;
	i = 0;
	while (strings[i] != 0)
	{
		ft_memdel((void**)&(strings[i]));
		i++;
	}
	ft_memdel((void**)&(strings[i]));
	ft_memdel((void**)strings);
}
