/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwolf <hwolf@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 11:54:25 by hwolf             #+#    #+#             */
/*   Updated: 2019/09/17 20:38:27 by hwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
#include "../lib/libft/libft.h"

typedef struct s_fig{
	char label;
	int is_set;
	int row[3];
	int col[3];
}	t_fig;

char *code_fig(char *src, int map_size);
void put_fig(char *map, char *fig);
int put_posibility(char *map, char *fig);
void rm_label(char *map, char ch);
t_list	*read_figs_str(const int fd);
char *get_fig(int label, char *line, int count);
void lst_print(t_list *ptr);
int read_figs(t_fig *dist, t_list *fig_str);
void print_tab(t_fig *tab, int count);
int check_figs_list(t_list *src, t_list *etalon);
int check_fig_list(t_list *src, t_list *etalon);

#endif
