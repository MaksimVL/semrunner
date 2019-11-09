#include "libft.h"
#include "lemin.h"

void				lemin_init_ways(t_lemin *l)
{
	int i;
	int max_flow;

	max_flow = 0;
	i = -1;
	while (++i < l->size_matrix)
		if (l->capacity[l->s][i] == 1)
			max_flow++;
	l->way_length = (int*)ft_memalloc(sizeof(int) * max_flow);
	l->prev_way_length = (int*)ft_memalloc(sizeof(int) * max_flow);
	l->ways = (int**)ft_memalloc(sizeof(int*) * max_flow);
	l->prev_ways = (int**)ft_memalloc(sizeof(int*) * max_flow);
	l->ants_on_ways = (int**)ft_memalloc(sizeof(int*) * max_flow);
	i = -1;
	while (++i < max_flow)
	{
		(l->ways)[i] = (int*)ft_memalloc(sizeof(int) * l->count_rooms);
		(l->prev_ways)[i] = (int*)ft_memalloc(sizeof(int) * l->count_rooms);
		vector_int_assign(l->ways[i], l->count_rooms, -1);
		vector_int_assign(l->prev_ways[i], l->count_rooms, -1);
		(l->ants_on_ways)[i] = (int*)ft_memalloc(sizeof(int) * l->count_rooms);
	}
}

int				bfs_ways(t_lemin *lem)
{
	t_queue q;
	int u;
	int v;

	queue_init(&q);
	lemin_init_vectors(lem);
	lem->mark[lem->s] = 1; 						// первая посещенная вершина - s
	lem->pred[lem->s] = lem->s;					// предыдущая для первой вершины - s
	lem->push[lem->s] = INF;					// поток в вершину s = INF
	qi_push(&q, lem->s);						// помещаем в очередь q вершину s

	while (!lem->mark[lem->t] && !qi_empty(&q))
	{
		u = qi_pop(&q); 						// достаем из очереди вершину, помещаем в u
		v = 0;
		while (v < lem->size_matrix)			// цикл по всем вершинам переменной v
		{
			if (!(lem->mark[v]) && lem->flow1[u][v] > 0)
			{
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

void				calculate_ways(t_lemin *l)
{
	int		i;
	int		j;
	int		v;
	int		u;

	// оставляем в flow только те вершины, по которым идет поток
	i = -1;
	while (++i < l->size_matrix)
	{
		j = -1;
		while (++j < l->size_matrix)
		{
			if (l->flow[i][j] == 1)
				l->flow1[i][j] = 1;
		}
	}
	l->count_ways = l->max_flow;
	// ищем все пути
	i = -1;
	while (++i < l->max_flow)
	{
		//queue_init(&(l->ways[i]));
		bfs_ways(l);
		v = l->t; // v - конечая точка
		u = l->pred[v]; // u - предпоследняя точка
		j = 0;
		while (v != l->s) // прокручиваем весь путь назад, до начальной точки, все складываем в очередь пути.
		{
			l->ways[i][j] = v / 2;
			j++;
			if (u / 2 == v / 2)
			{
				l->flow1[u][v] = 0; // обнуляем соответствующее ребро
				v = u;
				u = l->pred[v];
			}
			l->flow1[u][v] = 0; // обнуляем соответствующее ребро
			v = u;
			u = l->pred[v];
		}
		l->ways[i][j] = l->start_room;
		l->way_length[i] = j;
	}
}

