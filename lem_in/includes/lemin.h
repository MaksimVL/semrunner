/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odrinkwa <odrinkwa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/16 16:29:54 by odrinkwa          #+#    #+#             */
/*   Updated: 2019/11/17 00:52:23 by odrinkwa         ###   ########.fr       */
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
	int					flow;
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
	int					flow;
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

typedef struct			s_ant_move
{
	int					step;
	char				*to_name;
	int					to;
}						t_ant_move;

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

	t_dlist				**ants_moving;
	int					current_step;
	int					max_step;
}						t_lemin;

typedef struct			s_ant_draw_move
{
	int					start_room;
	int					end_room;
	t_point				start;
	t_point				curr;
	t_point				end;
}						t_ant_draw_move;
typedef struct			s_lemin_mlx
{
	t_mlx				*m;
	t_lemin				*lem;
	void				*ant_im;
	int					size_ant_im;
	t_ant_draw_move		*ants_move;
	t_point				curr_pos;
	int					count_steps;
	int					step_counter;
	int					nonstop;
	int					speed;
	int					show_room_numbers;
	int					show_not_use_edges;
	int					show_interm_rooms;
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

void				open_file_load_data(t_lemin *lemin, int argc, char **argv);
void				load_data(t_lemin *lemin, int fd, char flag_visu);
t_room				set_room_property(char **strings, int next_flag);
int					find_duplicates_rooms(t_dlist *list_rooms,
											t_room room_temp);

/*
** prepare data
*/

void				prepare_data(t_lemin *lemin);
void				lemin_fill_graph(t_lemin *lem);
void				lemin_init_ways(t_lemin *l);
int					room_number(t_lemin *lemin, char *room_name);

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
** print
*/

void				print_anthill(t_lemin *l);

/*
** visualization
*/

void				tlemin_mlx_initialize(t_lemin_mlx *lm);
void				load_anthill_to_map_points(t_mlx *m, t_lemin *lem);
void				set_ants_to_start(t_lemin_mlx *lm);

void				calc_parameter_maps(t_mlx *m);

void				set_num_rooms_to_ant_moves(t_lemin *l);
void				create_ant_draw_move(t_lemin_mlx *lm);
void				set_flow_anthill(t_lemin *l);

void				start_load_ant_im(t_lemin_mlx *lm);
void				load_ant_im(t_lemin_mlx *lm);

void				put_names_rooms(t_mlx *m, t_lemin *l, t_lemin_mlx *lm, int color);
void				draw_anthill(t_lemin_mlx *lm, int not_black);
int					lemin_keyhook(int keycode, void *lm);

void				set_ants_to_rooms_on_step(t_lemin_mlx *lm);
int					loop_ants_move(t_lemin_mlx *lm);

void				draw_ants(t_lemin_mlx *lm);
void				draw_ant(t_lemin_mlx *lm, int i, t_point p);



void				put_ant(t_lemin_mlx *lm, int x, int y);
//void				put_main_image(t_lemin_mlx *m);
void				put_all_anthill(void *lm);

void				finish_all(t_lemin_mlx *lm, int res);
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

//void				print_intmatrix(int **matrix, int num_of_lines, int num_of_cols);

/*
** visualization
** file visual.c
*/



#endif

