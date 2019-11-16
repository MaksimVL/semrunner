/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prepare_data2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odrinkwa <odrinkwa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/16 18:26:40 by odrinkwa          #+#    #+#             */
/*   Updated: 2019/11/16 18:54:06 by odrinkwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "lemin.h"

static int		count_max_flow(t_lemin *l)
{
	int			max_flow;
	t_dlist		*curr;
	t_gedge		*edg;

	max_flow = 0;
	curr = l->g[l->s];
	while (curr != NULL)
	{
		edg = curr->content;
		if (edg->cap == 1)
			max_flow++;
		curr = curr->next;
	}
	return (max_flow);
}

static void		lemin_init_ways_lines(t_lemin *l, int max_flow)
{
	int i;

	i = -1;
	while (++i < max_flow)
	{
		if (!((l->ways)[i] = (int*)malloc(sizeof(int) * l->count_rooms)))
			finish_prog(l, -1, -1, NULL);
		if (!((l->prev_ways)[i] = (int*)malloc(sizeof(int) * l->count_rooms)))
			finish_prog(l, -1, -1, NULL);
		vector_int_assign(l->ways[i], l->count_rooms, -1);
		vector_int_assign(l->prev_ways[i], l->count_rooms, -1);
		if (!((l->ants_on_ways)[i] = (int*)ft_memalloc(sizeof(int) *
									l->count_rooms)))
			finish_prog(l, -1, -1, NULL);
	}
}

void			lemin_init_ways(t_lemin *l)
{
	int max_flow;

	max_flow = count_max_flow(l);
	l->max_ways = max_flow;
	if (!(l->way_length = (int*)ft_memalloc(sizeof(int) * max_flow)))
		finish_prog(l, -1, -1, NULL);
	if (!(l->prev_way_length = (int*)ft_memalloc(sizeof(int) * max_flow)))
		finish_prog(l, -1, -1, NULL);
	if (!(l->ways = (int**)ft_memalloc(sizeof(int*) * max_flow)))
		finish_prog(l, -1, -1, NULL);
	if (!(l->prev_ways = (int**)ft_memalloc(sizeof(int*) * max_flow)))
		finish_prog(l, -1, -1, NULL);
	if (!(l->ants_on_ways = (int**)ft_memalloc(sizeof(int*) * max_flow)))
		finish_prog(l, -1, -1, NULL);
	lemin_init_ways_lines(l, max_flow);
}
