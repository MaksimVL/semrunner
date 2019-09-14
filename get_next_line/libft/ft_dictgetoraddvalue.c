
#include "libft.h"

t_dict	*ft_dictgetoraddvalue(t_dict **dict, int key)
{
	t_dict	*new;
	t_dict	*counter;

	counter = *dict;
	while (counter)
	{
		if ((counter)->key == key)
			return (counter);
		else
			counter = (counter)->next;
	}
	new = ft_dictnew(NULL, 0, key);
	ft_dictadd(dict, new);
	return (new);
}
