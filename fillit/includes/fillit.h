/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odrinkwa <odrinkwa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 11:54:25 by hwolf             #+#    #+#             */
/*   Updated: 2019/09/18 19:28:40 by odrinkwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef FILLIT_H
# define FILLIT_H
#include "libft.h"

typedef struct s_fig{
	char label;
	int is_set;
	int row[3];
	int col[3];
}	t_fig;

t_list		*read_figs_str(const int fd);
char		*get_fig(int label, char *line, int count);
void		lst_print(t_list *ptr);
int			read_figs(t_fig *dist, t_list *fig_str);
int			check_figs_list(t_list *src, t_list *etalon);
int			check_fig_list(t_list *src, t_list *etalon);

#endif
