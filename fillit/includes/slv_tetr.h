/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   slv_tetr.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odrinkwa <odrinkwa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 21:49:47 by odrinkwa          #+#    #+#             */
/*   Updated: 2019/09/17 22:10:12 by odrinkwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SLV_TETR_H
# define SLV_TETR_H

#include "libft.h"
#include "fillit.h"

typedef struct	s_map{
	char		*map;
	int			size_map;
}				t_map;

char			get_point(t_map *m, int row, int col);
void			put_point(t_map *m, int row, int col, char c);
int				check_figure(t_map *m, int row, int col, t_fig *fig);
void			put_figure(t_map *m, int row, int col, t_fig *fig);
void			remove_figure(t_map *m, int row, int col, t_fig *fig);
void			printmap(t_map *m);
int				solve_tetrimino(t_fig figs[], int count_figures);

#endif