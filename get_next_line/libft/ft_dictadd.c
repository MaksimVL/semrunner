

#include "libft.h"

void	ft_dictadd(t_dict **adict, t_dict *new)
{
	t_dict *next;

	if (*adict)
	{
		*adict = new;
		return ;
	}
	if (new)
	{
		if (!((*adict)->next))
			(*adict)->next = new;
		else
		{
			next = (*adict)->next;
			(*adict)->next = new;
			new->next = next;
		}
	}
}
