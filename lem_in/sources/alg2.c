#include "libft.h"
#include "lemin.h"

/*
** алгоритм bf.  s - это конечная точка (s = t)
*/


// void			max_flow_ff(t_lemin *lem)
// {
// 	int u;
// 	int v;
// 	int add;
// 	int flow;

// 	flow = 0;
// 	while (bfs(lem)) // находим путь до конечной точки t.
// 	{
// 		add = lem->push[lem->t]; // в переменную add записываем значение потока в t
// 		v = lem->t; // v - конечая точка
// 		u = lem->pred[v]; // u - предпоследняя точка
// 		while (v != lem->s) // прокручиваем весь путь назад, до начальной точки.
// 							// корректируем для каждого ребра поток:
// 							// u->v добавляем add, v->u - вычитаем add
// 		{
// 			lem->flow[u][v] += add;
// 			lem->flow[v][u] -= add;
// 			v = u;
// 			u = lem->pred[v];
// 		}
// 		flow += add; // в переменную flow добавляем значение потока.
// 	}
// 	lem->max_flow = flow; // и соответственно конечное значение потока - в max_flow
// }

// void			min_cost_f(t_lemin *lem)
// {
// 	int u;
// 	int v;
// 	int flow;
// 	int add;
// 	int neg_cycle;

// 	flow = 0;
// 	add = INF;
// 	max_flow_ff(lem);	// вычисляем максимальное значение потока, и в матрице flow формируем
// 						// данные - по каким ребрам какой поток идет.
// 	neg_cycle = bf(lem, lem->t);
// 	while (neg_cycle != INF)
// 	{
// 		v = neg_cycle;
// 		u = lem->pred[v];
// 		while (1)
// 		{
// 			add = MIN(add, lem->capacity[u][v] - lem->flow[u][v]);
// 			v = u;
// 			u = lem->pred[v];
// 			if (v == neg_cycle)
// 				break ;
// 		}
// 		v = neg_cycle;
// 		u = lem->pred[v];
// 		while (1)
// 		{
// 			lem->flow[u][v] += add;
// 			lem->flow[v][u] -= add;
// 			v = u;
// 			u = lem->pred[v];
// 			if (v == neg_cycle)
// 				break ;
// 		}
// 		neg_cycle = bf(lem, lem->t);
// 	}
// 	u = 0;
// 	while (u < lem->size_matrix)
// 	{
// 		v = 0;
// 		while (v < lem->size_matrix)
// 		{
// 			if (lem->flow[u][v] > 0)
// 				lem->min_cost += lem->flow[u][v] * lem->cost[u][v];
// 			v++;
// 		}
// 		u++;
// 	}
// }

