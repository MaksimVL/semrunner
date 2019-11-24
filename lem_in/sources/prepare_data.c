/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prepare_data.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odrinkwa <odrinkwa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/16 17:55:16 by odrinkwa          #+#    #+#             */
/*   Updated: 2019/11/24 23:08:11 by odrinkwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "lemin.h"
#include <time.h>

int				room_number(t_lemin *lemin, char *room_name)
{
	t_dlist		*curr;

	curr = lemin->list_rooms;
	while (curr != NULL)
	{
		if (ft_strequ(((t_room*)(curr->content))->name, room_name))
			return (((t_room*)(curr->content))->number);
		curr = curr->next;
	}
	errno = 200;
	return (-1);
}

static void		edges_assign(t_lemin *lemin)
{
	t_dlist		*curr;
	int			i;

	if (!(lemin->edges = (t_edge*)ft_memalloc(sizeof(t_edge) *
							lemin->count_edges)))
		finish_prog(lemin, -1, -1, NULL);
	i = 0;
	curr = lemin->room_ways;
	while (i < lemin->count_edges)
	{
		lemin->edges[i].from = room_number(lemin,
								((t_room_ways*)(curr->content))->start_room);
		lemin->edges[i].to = room_number(lemin,
								((t_room_ways*)(curr->content))->end_room);
		lemin->edges[i].capacity = 1;
		lemin->edges[i].cost = 1;
		i++;
		curr = curr->next;
		if (errno != 0)
			finish_prog(lemin, -1, -1, NULL);
	}
}

static void		lemin_init_arrays(t_lemin *lemin)
{
	if (!(lemin->push = (int*)malloc(sizeof(int) * lemin->count_rooms * 2)))
		finish_prog(lemin, -1, -1, NULL);
	if (!(lemin->mark = (int*)malloc(sizeof(int) * lemin->count_rooms * 2)))
		finish_prog(lemin, -1, -1, NULL);
	if (!(lemin->pred = (int*)malloc(sizeof(int) * lemin->count_rooms * 2)))
		finish_prog(lemin, -1, -1, NULL);
	lemin->max_flow = 0;
}

static void		lemin_fill_rooms(t_lemin *lem)
{
	int		i;
	t_dlist *curr;

	if (!(lem->rooms = (t_room**)ft_memalloc(sizeof(t_room*) *
						lem->count_rooms)))
		finish_prog(lem, -1, -1, NULL);
	curr = lem->list_rooms;
	i = 0;
	while (i < lem->count_rooms)
	{
		(lem->rooms)[i] = (t_room*)(curr->content);
		i++;
		curr = curr->next;
	}
}

void			prepare_data(t_lemin *lemin)
{
	clock_t start, end;

	start = clock();
	errno = 0;
	edges_assign(lemin);
	end = clock();
	ft_printf("%w# edg assign %lf\n", 2, ((double)end - (double)start) / (double)(CLOCKS_PER_SEC));

	start = clock();
	lemin_init_arrays(lemin);
	end = clock();
	ft_printf("%w# lem_init_arr %lf\n", 2, ((double)end - (double)start) / (double)(CLOCKS_PER_SEC));

	start = clock();
	lemin_fill_rooms(lemin);
	end = clock();
	ft_printf("%w# fill_rooms %lf\n", 2, ((double)end - (double)start) / (double)(CLOCKS_PER_SEC));

	start = clock();
	lemin_fill_graph(lemin);
	end = clock();
	ft_printf("%w# fill_graph %lf\n", 2, ((double)end - (double)start) / (double)(CLOCKS_PER_SEC));

	start = clock();
	lemin_init_ways(lemin);
	end = clock();
	ft_printf("%w# init_ways %lf\n", 2, ((double)end - (double)start) / (double)(CLOCKS_PER_SEC));
}
