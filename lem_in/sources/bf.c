#include "libft.h"
#include "lemin.h"

int				edge_cost(t_lemin *lem, int u, int v)
{
	if (lem->capacity[u][v] - lem->flow[u][v] > 0)
		return lem->cost[u][v];
	else
		return (INF);
}

int				check_cycles(t_lemin *lem)
{
	int u;
	int v;

	u = 0;
	v = 0;
	while (u < lem->size_matrix)
	{
		while (v < lem->size_matrix)
		{
			if (lem->dist[v] > lem->dist[u] + edge_cost(lem, u, v))
				return (u);
			v++;
		}
		u++;
	}
	return (INF);
}

int				bf(t_lemin *lem, int s)
{
	t_queue		q;
	int			u;
	int			v;
	int			series;


	lemin_init_vectors(lem);
	queue_init(&q);
	lem->pred[s] = s; // это строка означает: pred[t] = t
	lem->dist[s] = 0; // dist[t] = 0
	qi_push(&q, s); // добавляем в очередь вершину t
	qi_push(&q, INF); // добавляем в очередь INF (заглушку?)
	series = 0;
	while (!qi_empty(&q)) // цикл пока в очереди что то есть
	{
		// если в начале очереди INF, то выходим, возвращая результат check_cycles
		while (qi_front(&q) == INF) // цикл пока в очереди первым элементом есть заглушка.
		{
		 	qi_pop(&q); // удаляем первый элемент
		  // увеличиваем series на 1
		 	if (++series > lem->size_matrix)	// если  series превысило количество вершин (комнат)
		 										// то прекращаем выполнение, возвращая check_cycles(lem)
		 		{
		 			qi_del(&q);
		 			return (check_cycles(lem));
		 		}
		 	else
		 		qi_push(&q, INF); // иначе - добавляем в начало очереди INF
		 }


		u = qi_pop(&q);
		v = 0;
		while (v < lem->size_matrix)
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
