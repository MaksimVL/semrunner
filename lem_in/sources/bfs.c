#include "libft.h"
#include "lemin.h"

void			lemin_init_vectors(t_lemin *lem)
{
	vector_int_assign(lem->mark, lem->size_matrix, 0);
	vector_int_assign(lem->push, lem->size_matrix, 0);
	vector_int_assign(lem->pred, lem->size_matrix, 0);
	vector_int_assign(lem->dist, lem->size_matrix, INF);
}

int				bfs(t_lemin *lem)
{
	t_queue q;
	int u;
	int v;

	ft_printf("start calc bfs...\n");
	queue_init(&q);
	lemin_init_vectors(lem);
	lem->mark[lem->s] = 1;
	lem->pred[lem->s] = lem->s;
	lem->push[lem->s] = INF;
	qi_push(&q, lem->s);
	while (!lem->mark[lem->t] && !qi_empty(&q))
	{
		u = qi_pop(&q);
		v = 0;
		while (v < lem->size_matrix)
		{
			if (!lem->mark[v] && (lem->capacity[u][v] - lem->flow[u][v] > 0))
			{
				lem->push[v] = MIN(lem->push[u], lem->capacity[u][v] - lem->flow[u][v]);
				lem->mark[v] = 1;
				lem->pred[v] = u;
				qi_push(&q, v);
			}
			v++;
		}
	}
	qi_del(&q);
	ft_printf("finish calc bfs\n");
	return (lem->mark[lem->t]);
}
