#include "libft.h"
#include "lemin.h"

/*
edge_cost (u, v): возвращает значение оставшегося
потока через ребро u -> v. если значение 0 - то возвращаем INF
*/

int				edge_cost(t_lemin *lem, int u, int v)
{
	if (lem->capacity[u][v] - lem->flow[u][v] > 0)
		return lem->cost[u][v];
	else
		return (INF);
}

/*
check_cycles: перебираем все пары вершин. если dist[v] - расстояние от вершины v
до начальной точки s, больше, чем dist[u] (расст. от u до нач. точки) + значение
оставшегося потока между  u и v - то возвращаем вершину v.  иначе INF.
данное условие может быть выполнено только для смежных вершин u, v
(иначе edge_cost вернет INF)
.
нужно уточнить для чего эта функция. пока что предварительно:
получается, что если условие выполняется, то в вершину v можно попасть из вершины u, и путь будет короче?
*/

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

	queue_init(&q);
	lemin_init_vectors(lem);
	lem->mark[lem->s] = 1; 						// первая посещенная вершина - s
	lem->pred[lem->s] = lem->s;					// предыдущая для первой вершины - s
	lem->push[lem->s] = INF;					// поток в вершину s = INF
	qi_push(&q, lem->s);						// помещаем в очередь q вершину s

/*
	цикл:	пока mark[t] == 0 (пока не достигли конечной точки)  &&
			пока очередь q не пуста
*/
	while (!lem->mark[lem->t] && !qi_empty(&q))
	{
		u = qi_pop(&q); 						// достаем из очереди вершину, помещаем в u
		v = 0;
		while (v < lem->size_matrix)			// цикл по всем вершинам переменной v
		{
			// если mark[v] == 0 (верш. v не посещена) &&
			// capac[u][v] - flow[u][v] - оставшийся поток > 0, то есть можем пустить поток по ребру
			// если у нас в flow[u][v] - отрицательное значение, то есть поток уже есть в другую сторону,
			// то по алгоритму мы можем его направить обратно.
			if (!lem->mark[v] && (lem->capacity[u][v] - lem->flow[u][v] > 0))
			{
				//push[v] = min( push[u], capac[u][v] - flow[u][v]) - записываем какой поток можем пустить
				// по ребру [u][v].
				// mark[v] = 1 - отмечаем что верш. v посещена
				// pred[v] = u - отмечаем что в верш. v попали из u
				lem->push[v] = MIN(lem->push[u], lem->capacity[u][v] - lem->flow[u][v]);
				lem->mark[v] = 1;
				lem->pred[v] = u;
				// достаем следующую вершину из очереди
				qi_push(&q, v);
			}
			v++;
		}
	}
	qi_del(&q);
	// возвращаем значение mark[t]: == 0 - не дошли до конца, == 1 - дошли до конца
	return (lem->mark[lem->t]);
}

/*
** алгоритм bf.  s - это конечная точка (s = t)
*/

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
		if (qi_front(&q) == INF)
		{
			qi_del(&q);
			return (check_cycles(lem));
		}
		// while (qi_front(&q) == INF) // цикл пока в очереди первым элементом есть заглушка.
		// {
		// 	qi_pop(&q); // удаляем последнй элемент
		//  // увеличиваем series на 1
		// 	if (++series > lem->size_matrix)	// если  series превысило количество вершин (комнат)
		// 										// то прекращаем выполнение, возвращая check_cycles(lem)
		// 		{
		// 			qi_del(&q);
		// 			return (check_cycles(lem));
		// 		}
		// 	else
		// 		qi_push(&q, INF); // иначе - добавляем в начало очереди INF
		// }


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

void			max_flow_ff(t_lemin *lem)
{
	int u;
	int v;
	int add;
	int flow;

	flow = 0;
	while (bfs(lem)) // находим путь до конечной точки t.
	{
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
	}
	lem->max_flow = flow; // и соответственно конечное значение потока - в max_flow
}

void			min_cost_f(t_lemin *lem)
{
	int u;
	int v;
	int flow;
	int add;
	int neg_cycle;

	flow = 0;
	add = INF;
	max_flow_ff(lem);	// вычисляем максимальное значение потока, и в матрице flow формируем
						// данные - по каким ребрам какой поток идет.
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

void			lemin_print_res(t_lemin *lem)
{
	ft_printf("max flow=%d\n", lem->max_flow);
	ft_printf("min cost=%d\n", lem->min_cost);
}
