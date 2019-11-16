/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odrinkwa <odrinkwa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/16 16:29:54 by odrinkwa          #+#    #+#             */
/*   Updated: 2019/11/16 19:58:53 by odrinkwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEMIN_H
# define LEMIN_H

# include "libft.h"
# include "fdf.h"

# define INF 1e9

typedef struct			s_room
{
	char				*name;
	int					number;
	int					x;
	int					y;
	int					z;
	int					start_end_flag;
}						t_room;

typedef struct			s_room_ways
{
	char				*start_room;
	char				*end_room;
}						t_room_ways;

typedef struct			s_edge
{
	int					from;
	int					to;
	int					capacity;
	int					cost;
}						t_edge;

typedef struct			s_gedge
{
	int					to;
	int					cap;
	int					flow;
	int					flow1;
}						t_gedge;

typedef struct			s_start_end
{
	int					start;
	int					end;
}						t_start_end;

typedef struct			s_lemin
{
	t_dlist				*list_rooms;
	t_dlist				*room_ways;
	int					count_rooms;
	int					start_room;
	int					end_room;
	int					number_of_ants;
	int					count_edges;
	t_edge				*edges;
	t_room				**rooms;

	int					**ants_on_ways;
	int					max_ways;

	int					**ways;
	int					*way_length;
	int					count_ways;
	int					count_steps;

	int					**prev_ways;
	int					*prev_way_length;
	int					prev_count_ways;
	int					prev_count_steps;

	int					*ants_left_on_ways;

	int					size_matrix;

	t_dlist				**g;
	int					*push;
	int					*mark;
	int					*pred;
	int					max_flow;
	int					s;
	int					t;
}						t_lemin;

typedef struct			s_lemin_mlx
{
	t_mlx				*m;
	t_lemin				*lem;
}						t_lemin_mlx;

/*
** initialize
*/

void				lemin_init(t_lemin *lemin);

/*
** destroy
*/

void				lemin_destroy(t_lemin *lemin);
void				finish_prog(t_lemin *l, int res, int fd, char **line);

/*
** load data from file
*/

void				load_data(t_lemin *lemin, char *filename);
t_room				set_room_property(char **strings, int next_flag);
int					find_duplicates_rooms(t_dlist *list_rooms,
											t_room room_temp);

/*
** prepare data
*/

void				prepare_data(t_lemin *lemin);
void				lemin_fill_graph(t_lemin *lem);
void				lemin_init_ways(t_lemin *l);

/*
** solve
*/

void				solve(t_lemin *l);
int					bfs(t_lemin *lem);
int					bfs_ways(t_lemin *lem);
void				calculate_ways(t_lemin *l);

/*
** going ants
*/

void				going_ants(t_lemin *l);
int					count_bandwidth(int flow_len, int step);

/*
** print properties
*/

void				print_room_property(t_dlist *lst);
void				print_all_rooms_property(t_dlist *lst);
void				print_links(t_dlist *lst);
void				print_all_links(t_dlist *lst);
void				print_all_edges(t_lemin *lemin);

void				vector_int_assign(int *vector, int len, int value);
void				vector_int_print(int *vector, int len);

/*
** algorithm
*/

void				lemin_init_vectors(t_lemin *lem);
void				lemin_init_vectors_bfs(t_lemin *lem);
int					edge_cost(t_lemin *lem, int u, int v);
int					check_cycles(t_lemin *lem);
int					bf(t_lemin *lem, int s);
int					count_flow_base(int *ways_len, int count_ways, int max_len);


/*
** calculate ways
*/

void				lemin_init_ways(t_lemin *l);
void				calculate_ways(t_lemin *l);

/*
** aux functions
*/

void				print_intmatrix(int **matrix, int num_of_lines, int num_of_cols);
void				vector_int_print(int *vector, int len);
void				vector_int_assign(int *vector, int len, int value);

/*
** visualization
** file visual.c
*/

void				load_anthill(t_mlx *m, t_lemin *lem);
void				calc_parameter_maps(t_mlx *m);
void				put_names_rooms(t_mlx *m, t_lemin *l, int color);
void				draw_anthill(t_lemin_mlx *lm, int not_black);
int					lemin_keyhook(int keycode, void *lm);

#endif

