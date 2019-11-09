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

int			max_int_array(int *arr, int size)
{
	int		i;
	int		res;

	if (size <= 0)
		return (0);
	res = arr[0];
	i = 0;
	while (++i < size)
		if (arr[i] > res)
			res = arr[i];
	return (res);
}

int			count_flow_base(int *ways_len, int count_ways, int max_len)
{
	int		res;
	int		i;

	res = 0;
	i = -1;
	while (++i < count_ways)
	{
		res += max_len + 1 - ways_len[i];
	}
	return (res);
}

int		compare_ways(t_lemin *l)
{
	int		max_len;
	int		max_len_prev;
	int		flow_base;
	int		flow_base_prev;
	int		step_i;

	max_len = max_int_array(l->way_length, l->count_ways);
	flow_base = count_flow_base(l->way_length, l->count_ways, max_len);
	if (l->number_of_ants < flow_base)
		return (-1); // значит, предыдущий путь лучше
	max_len_prev = max_int_array(l->prev_way_length, l->prev_count_ways);
	flow_base_prev = count_flow_base(l->prev_way_length, l->prev_count_ways, max_len_prev);
	step_i = max_len;
	while (1)
	{
		if ((flow_base_prev + l->prev_count_ways * (step_i - max_len_prev)) > l->number_of_ants)
			if (l->way_length[l->count_ways - 1] > l->prev_way_length[l->prev_count_ways - 1])
				return (-1); // по предыдущему пути достигли максимума муравьев - значит, пред. путь лучше.
		if ((flow_base + l->count_ways * (step_i - max_len)) > l->number_of_ants)
			return (1); // по новому пути достигли максимума муравьев
		step_i++;
	}
	return (-1);
}

void		solve(t_lemin *l)
{
	while (bfs(l))
	{
		swap_ways(l);
		set_flow(l);
		remove_neg_cycle_with_bf(l);
		calculate_ways(l);
		ft_printf("way:\n");
		vector_int_print(l->way_length, l->count_ways);
		ft_printf("way prev:\n");
		vector_int_print(l->prev_way_length, l->prev_count_ways);
		if (l->prev_count_ways == 0)
		{
			if (l->number_of_ants == 1)
				break ;
		// 	else
		// 	 	swap_ways(l);
		}
		else
			if (compare_ways(l) == -1)
				{
					swap_ways(l);
					break ;
				}
	}
	// bfs(l);			//находим кратчайший путь
	// set_flow(l);	//прокручиваем путь, устанавливаем поток
	// remove_neg_cycle_with_bf(l);
}
