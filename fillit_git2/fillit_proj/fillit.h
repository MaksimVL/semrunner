/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwolf <hwolf@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 11:54:25 by hwolf             #+#    #+#             */
/*   Updated: 2019/09/18 22:21:42 by hwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include "libft.h"

typedef struct	s_fig{
	char		label;
	int			is_set;
	int			row[4];
	int			col[4];
}				t_fig;

void			get_fig(char label, char *line, t_fig *dist);
int				analis(t_fig fig);
int				read_figs(const int fd, t_fig *fig);
int				check_sym(char *str);

#endif
