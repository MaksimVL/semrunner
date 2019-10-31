#include "libft.h"
#include "lemin.h"

int				edge_cost(t_lemin *lem, int u, int v)
{
	if (lem->capacity[u][v] - lem->flow[u][v] > 0)
		return lem->cost[u][v];
	else
		return INF;
}

int				check_cycles(t_lemin *lem)
{
	int u;
	int v;

	u = 0;
	v = 0;
	while (u < lem->count_rooms)
	{
		while (v < lem->count_rooms)
		{
			if (lem->dist[v] > lem->dist[u] + edge_cost(lem, u, v))
				return (u);
			v++;
		}
		u++;
	}
	return (INF);
}

void			lemin_init_vectors(t_lemin *lem)
{
	vector_int_assign(lem->mark, lem->count_rooms, 0);
	vector_int_assign(lem->push, lem->count_rooms, 0);
	vector_int_assign(lem->pred, lem->count_rooms, 0);
	vector_int_assign(lem->dist, lem->count_rooms, INF);
}

int				bfs(t_lemin *lem)
{
	t_queue q;
	int u;
	int v;

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
		while (v < lem->count_rooms)
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
	return (lem->mark[lem->t]);
}

int				bf(t_lemin *lem, int s)
{
	t_queue q;
	int u;
	int v;
	int series;


	lemin_init_vectors(lem);
	queue_init(&q);
	lem->pred[s] = s;
	lem->dist[s] = 0;
	qi_push(&q, s);
	qi_push(&q, INF);
	series = 0;
	while (!qi_empty(&q))
	{
		while (qi_front(&q) == INF)
		{
			qi_pop(&q);
			if (++series > lem->count_rooms)
				{
					qi_del(&q);
					return (check_cycles(lem));
				}
			else
				qi_push(&q, INF);
		}
		u = qi_pop(&q);
		v = 0;
		while (v < lem->count_rooms)
		{
			if (lem->dist[v] > lem->dist[u] + edge_cost(lem, u, v))
			{
				lem->dist[v] = lem->dist[u] + edge_cost(lem, u, v);
				lem->pred[v] = u;
				qi_push(&q, v);
			}
			v++;
		}
	}
	qi_del(&q);
	return (INF);
}

void			max_flow_ff(t_lemin *lem)
{
	int u;
	int v;
	int add;
	int flow;

	flow = 0;
	while (bfs(lem))
	{
		add = lem->push[lem->t];
		v = lem->t;
		u = lem->pred[v];
		while (v != lem->s)
		{
			lem->flow[u][v] += add;
			lem->flow[v][u] -= add;
			v = u;
			u = lem->pred[v];
		}
		flow += add;
	}
	lem->max_flow = flow;
}

void			min_cost_f(t_lemin *lem)
{
	int u;
	int v;
	int flow;
	int add;
	int neg_cycle;

	flow = 0;
	max_flow_ff(lem);
	neg_cycle = bf(lem, lem->t);
	while (neg_cycle != INF)
	{
		v = neg_cycle;
		u = lem->pred[v];
		do
		{
			add = MIN(add, lem->capacity[u][v] - lem->flow[u][v]);
			v = u;
			u = lem->pred[v];
		} while (v != neg_cycle);
		v = neg_cycle;
		u = lem->pred[v];
		do
		{
			lem->flow[u][v] += add;
			lem->flow[v][u] -= add;
			v = u;
			u = lem->pred[v];
		} while  (v!= neg_cycle);
		neg_cycle = bf(lem, lem->t);
	}
	u = 0;
	while (u < lem->count_rooms)
	{
		v = 0;
		while (v < lem->count_rooms)
		{
			if (lem->flow[u][v] > 0)
				lem->min_cost += lem->flow[u][v] * lem->cost[u][v];
			v++;
		}
		u++;
	}
}

void			lemin_print_res(t_lemin *lem)
{
	ft_printf("max flow=%d\n", lem->max_flow);
	ft_printf("min cost=%d\n", lem->min_cost);
}
