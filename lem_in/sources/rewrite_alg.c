#include "libft.h"
#include "lemin.h"

void		set_flow(t_lemin *lem)
{
	int u;
	int v;
	int add;
	int flow;

	flow = 0;
	add = lem->push[lem->t]; // в переменную add записываем значение потока в t
	v = lem->t; // v - конечая точка
	u = lem->pred[v]; // u - предпоследняя точка
	while (v != lem->s) // прокручиваем весь путь назад, до начальной точки.
						// корректируем для каждого ребра поток:
						// u->v добавляем add, v->u - вычитаем add
	{
		lem->flow[u][v] += add;
		lem->flow[v][u] -= add;
		v = u;
		u = lem->pred[v];
	}
	flow += add; // в переменную flow добавляем значение потока.
	lem->max_flow += flow;
}

void		remove_neg_cycle_with_bf(t_lemin *lem)
{
	int u;
	int v;
	int flow;
	int add;
	int neg_cycle;

	flow = 0;
	add = INF;
	neg_cycle = bf(lem, lem->t);
	while (neg_cycle != INF)
	{
		v = neg_cycle;
		u = lem->pred[v];
		while (1)
		{
			add = MIN(add, lem->capacity[u][v] - lem->flow[u][v]);
			v = u;
			u = lem->pred[v];
			if (v == neg_cycle)
				break ;
		}
		v = neg_cycle;
		u = lem->pred[v];
		while (1)
		{
			lem->flow[u][v] += add;
			lem->flow[v][u] -= add;
			v = u;
			u = lem->pred[v];
			if (v == neg_cycle)
				break ;
		}
		neg_cycle = bf(lem, lem->t);
	}
	u = 0;
	while (u < lem->size_matrix)
	{
		v = 0;
		while (v < lem->size_matrix)
		{
			if (lem->flow[u][v] > 0)
				lem->min_cost += lem->flow[u][v] * lem->cost[u][v];
			v++;
		}
		u++;
	}
}

int			compare_ways(t_lemin *l)
{

}

void		swap_ways(t_lemin *l)
{
	int **tmp;
	int *tmp1;
	int tmp2;

	tmp = l->prev_ways;
	l->prev_ways = l->ways;
	l->ways = tmp;
	tmp1 = l->prev_way_length;
	l->prev_way_length = l->way_length;
	l->way_length = tmp1;
	tmp2 = l->prev_count_ways;
	l->prev_count_ways = l->count_ways;
	l->count_ways = tmp2;
}

void		solve(t_lemin *l)
{
	while (bfs(l))
	{
		set_flow(l);
		remove_neg_cycle_with_bf(l);
		if (l->prev_count_ways == 0)
		{
			if (l->number_of_ants == 1)
				break ;
			else
				swap_ways(l);
		}
		else
		{
			compare_ways(l);
		}

	}
	// bfs(l);			//находим кратчайший путь
	// set_flow(l);	//прокручиваем путь, устанавливаем поток
	// remove_neg_cycle_with_bf(l);

}
