/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odrinkwa <odrinkwa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 18:48:15 by odrinkwa          #+#    #+#             */
/*   Updated: 2019/10/26 19:02:50 by odrinkwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "libft.h"
#include "lemin.h"

# define MAX_N 50

# define INF 1e9

void			lemin_init_arrays(t_lemin *lemin)
{
	int i;
	int from;
	int to;
	t_dlist		*curr;

	lemin->adj = (int**)ft_memalloc(sizeof(int*) * lemin->count_rooms);
	lemin->cost = (int**)ft_memalloc(sizeof(int*) * lemin->count_rooms);
	lemin->capacity = (int**)ft_memalloc(sizeof(int*) * lemin->count_rooms);
	i = 0;
	while (i < lemin->count_rooms)
	{
		(lemin->adj)[i] = (int*)ft_memalloc(sizeof(int) * lemin->count_rooms);
		(lemin->cost)[i] = (int*)ft_memalloc(sizeof(int) * lemin->count_rooms);
		(lemin->capacity)[i] = (int*)ft_memalloc(sizeof(int) * lemin->count_rooms);
		i++;
	}
}

void			vector_int_assign(int *vector, int len, int value)
{
	int i;

	i = 0;
	while (i < len)
	{
		vector[i] = value;
		i++;
	}
}

void			shortest_path(t_lemin *lemin, int *d, int *p)
{
	int *inq;
	int u;
	int i;
	int v;
	t_queue q;

	queue_init(&q);
	vector_int_assign(d, lemin->count_rooms, INF);
	vector_int_assign(p, lemin->count_rooms, -1);
	d[lemin->s] = 0;
	inq = (int*)ft_memalloc(sizeof(int) * lemin->count_rooms);
	vector_int_assign(inq, lemin->count_rooms, 0);
	qi_push(&q, lemin->s);
	while (!qi_empty(&q))
	{
		u = qi_pop(&q);
		inq[u] = 0;
		i = 0;
		while (i < lemin->count_rooms)
		{
			if (lemin->adj[u][i] == 1)
			{
				v = i;
				if (lemin->capacity[u][v] > 0 && d[v] > d[u] + lemin->cost[u][v])
				{
					d[v] = d[u] + lemin->cost[u][v];
					p[v] = u;
					if (!inq[v])
					{
						inq[v] = 1;
						qi_push(&q, v);
					}
				}
			}
			i++;
		}
	}
	ft_memdel((void**)&inq);
	qi_del(&q);
}

int				min_cost_flow(t_lemin *lemin)
{
	int flow;
	int cost;
	int *d;
	int *p;
	int f;
	int cur;

	flow = 0;
	cost = 0;
	d = (int*)ft_memalloc(sizeof(int) * lemin->count_rooms);
	p = (int*)ft_memalloc(sizeof(int) * lemin->count_rooms);
	while (flow < lemin->number_of_ants)
	{
		shortest_path(lemin, d, p);
		if (d[lemin->t] == INF)
			break;
		f = lemin->number_of_ants - flow;
		cur = lemin->t;
		while (cur != lemin->s)
		{
			f = MIN(f, lemin->capacity[p[cur]][cur]);
			cur = p[cur];
		}
		flow += f;
		cost += f * d[lemin->t];
		cur = lemin->t;
		while (cur != lemin->s)
		{
			lemin->capacity[p[cur]][cur] -= f;
			lemin->capacity[cur][p[cur]] += f;
			cur = p[cur];
		}
	}
	if (flow < lemin->number_of_ants)
		return (-1);
	return (cost);
}

void			lemin_assign_matrix(t_lemin *lemin)
{
	int i;
	t_edge e;

	i = 0;
	while (i < lemin->count_edges)
	{
		e = lemin->edges[i];
		lemin->adj[e.from][e.to] = 1;
		lemin->adj[e.to][e.from] = 1;
		lemin->cost[e.from][e.to] = e.cost;
		lemin->cost[e.to][e.from] = -e.cost;
		lemin->capacity[e.from][e.to] = e.capacity;
		i++;
	}
}

int				main(int argc, char **argv)
{
	t_lemin		lemin;
	int res;

	lemin_init(&lemin);

	load_data(&lemin); //TODO проверка на чтение, полная очистка если ошибка
	lemin.number_of_ants = 3;
	set_rooms_number(&lemin);
	lemin.count_edges = ft_dlst_len(lemin.room_ways);
	edges_assign(&lemin);
	lemin_init_arrays(&lemin);
	print_all_rooms_property(lemin.list_rooms);
	print_all_links(lemin.room_ways);
	print_all_edges(&lemin);

	lemin_assign_matrix(&lemin);

	res =  min_cost_flow(&lemin);

	ft_printf("min_cost_flow=%d\n", res);




	lemin_destroy(&lemin); // TODO хуйня какая то, надо разобраться с очисткой листов. ну да похуй, это можно позже сделать
}
