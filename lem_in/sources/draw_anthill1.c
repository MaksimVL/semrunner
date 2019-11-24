/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_anthill1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odrinkwa <odrinkwa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/24 15:52:53 by odrinkwa          #+#    #+#             */
/*   Updated: 2019/11/24 16:22:53 by odrinkwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "lemin_mlx.h"
#include "mlx.h"

void		draw_ways(t_lemin_mlx *lm, int not_black)
{
	int i;
	int n1;
	int n2;

	i = -1;
	while (++i < lm->lem->count_edges)
	{
		n1 = lm->lem->edges[i].from;
		n2 = lm->lem->edges[i].to;
		if (lm->lem->edges[i].flow == 1)
			put_thickline(lm->m, get_point_to_draw(lm->m, n1),
						get_point_to_draw(lm->m, n2), not_black);
		else
		{
			if (lm->show_not_use_edges == 1)
				putline(lm->m, get_point_to_draw(lm->m, n1),
						get_point_to_draw(lm->m, n2), not_black);
		}
	}
}
