#include "libft.h"
#include "lemin.h"

void			lemin_assign_vectors_bfs(t_lemin *lem)
{
	vector_int_assign(lem->mark, lem->size_matrix, 0);
	vector_int_assign(lem->push, lem->size_matrix, 0);
	vector_int_assign(lem->pred, lem->size_matrix, 0);
	lem->mark[lem->s] = 1;
	lem->pred[lem->s] = lem->s;
	lem->push[lem->s] = INF;
}

int				bfs(t_lemin *lem)
{
	t_queue		q;
	int			u;
	t_dlist		*curr;
	t_gedge		*edg;

	queue_init(&q);
	lemin_assign_vectors_bfs(lem);
	qi_push(&q, lem->s);
	while (!lem->mark[lem->t] && !qi_empty(&q))
	{
		u = qi_pop(&q);
		curr = lem->g[u];
		while (curr != NULL)
		{
			edg = curr->content;
			if (!lem->mark[edg->to] && edg->capacity - edg->flow > 0)
			{
				lem->push[edg->to] = MIN(lem->push[u], edg->capacity - edg->flow);
				lem->mark[edg->to] = 1;
				lem->pred[edg->to] = u;
				qi_push(&q, edg->to);
			}
			curr = curr->next;
		}
	}
	qi_del(&q);
	return (lem->mark[lem->t]);
}

int				bfs_ways(t_lemin *lem)
{
	t_queue		q;
	int			u;
	t_dlist		*curr;
	t_gedge		*edg;

	queue_init(&q);
	lemin_assign_vectors_bfs(lem);
	qi_push(&q, lem->s);
	while (!lem->mark[lem->t] && !qi_empty(&q))
	{
		u = qi_pop(&q);
		curr = lem->g[u];
		while (curr != NULL)
		{
			edg = curr->content;
			if (!(lem->mark[edg->to]) && edg->flow1 > 0)
			{
				lem->mark[edg->to] = 1;
				lem->pred[edg->to] = u;
				qi_push(&q, edg->to);
			}
			curr = curr->next;
		}
	}
	qi_del(&q);
	return (lem->mark[lem->t]);
}
