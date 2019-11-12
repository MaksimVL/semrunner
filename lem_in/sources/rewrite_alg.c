#include "libft.h"
#include "lemin.h"

void		set_flow(t_lemin *lem)
{
	int u;
	int v;
	int add;
	int flow;

	flow = 0;
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
	lem->max_flow += flow;
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



int			count_flow_base(int *ways_len, int count_ways, int max_len)
{
	int		res;
	int		i;

	res = 0;
	i = -1;
	while (++i < count_ways)
		res += max_len + 1 - ways_len[i];
	return (res);
}

int		compare_ways(t_lemin *l)
{
	int		max_len;
	int		max_len_prev;
	int		flow_base;
	int		flow_base_prev;
	int		step_i;

	max_len = ft_max_intarray(l->way_length, l->count_ways);
	flow_base = count_flow_base(l->way_length, l->count_ways, max_len);
	max_len_prev = ft_max_intarray(l->prev_way_length, l->prev_count_ways);
	flow_base_prev = count_flow_base(l->prev_way_length, l->prev_count_ways, max_len_prev);
	ft_printf("flow_base = %d, flow_base_prev = %d\n", flow_base, flow_base_prev);
	step_i = max_len;
	while (1)
	{
		if ((flow_base_prev + l->prev_count_ways * (step_i - max_len_prev)) >= l->number_of_ants)
			if (l->way_length[l->count_ways - 1] > l->prev_way_length[l->prev_count_ways - 1])
				return (-1); // по предыдущему пути достигли максимума муравьев
		if ((flow_base + l->count_ways * (step_i - max_len)) >= l->number_of_ants)
			return (1); // по новому пути достигли максимума муравьев
		step_i++;
	}
	return (-1);
}

void		solve(t_lemin *l)
{
	while (bfs(l))
	{
		ft_printf("start setflow...\n");
		set_flow(l);
		ft_printf("finish setflow\n");
		// ft_printf("flow before remove neg cycle:\n");
		// ft_print_intmatrix(l->flow, l->size_matrix, l->size_matrix);
		ft_printf("start remove cycle...\n");
		//remove_neg_cycle_with_bf(l);
		// ft_printf("flow after remove neg cycle:\n");
		// ft_print_intmatrix(l->flow, l->size_matrix, l->size_matrix);

		ft_printf("finish remove cycle\n");

		ft_printf("start calc ways...\n");
		calculate_ways(l);
		ft_printf("finish calc ways\n");
		ft_printf("way:\n");
		vector_int_print(l->way_length, l->count_ways);
		ft_printf("way prev:\n");
		vector_int_print(l->prev_way_length, l->prev_count_ways);
		ft_printf("start compare...\n");
		if (l->prev_count_ways == 0)
		{
			if (l->number_of_ants == 1)
				return ;
		 	else
		 	 	swap_ways(l);
		}
		else
			if (compare_ways(l) == 1)
					swap_ways(l);
		ft_printf("finish compare\n");
	}
	swap_ways(l);
}
