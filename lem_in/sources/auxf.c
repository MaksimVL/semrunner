#include "libft.h"
#include "lemin.h"

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

void			print_newgraph(t_lemin *l)
{
	int i;
	t_dlist *curr;
	t_gedge *edg;

	i = -1;
	while (++i < l->size_matrix)
	{
		ft_printf("vert %d: ", i);
		curr = l->g[i];
		while (curr != NULL)
		{
			edg = curr->content;
			ft_printf("%d ", edg->to);
			curr = curr->next;
		}
		ft_printf("\n");
	}
}
