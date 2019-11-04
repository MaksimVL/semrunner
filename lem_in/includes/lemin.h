#ifndef LEMIN_H
# define LEMIN_H

# include "libft.h"
#include "fdf.h"

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

typedef struct			s_lemin
{
	t_dlist				*list_rooms;
	t_dlist				*room_ways;
	int					count_rooms; // N - кол-во вершин
	int					number_of_ants; // K
	int					count_edges; // M - кол-во ребер
	t_edge				*edges;
	t_room				**rooms;

	int					**adj;
	int					**cost; //P - матр стоимости (расстояний)
	int					**capacity; // C - матр пропускных способностей
	int					**flow; // F - матр текущего потока в графе
	int					*push; // поток в верш. из нач. точки
	int					*mark; //отметки вершин где побывали
	int					*pred; // предок вершины (откуда пришли)
	int					*dist; // расст до верш. из нач. точки
	int					max_flow;
	int					min_cost;
	int					s; // нач. точка
	int					t; // конечная точка
}						t_lemin;

typedef struct	s_lemin_mlx
{
	t_mlx		*m;
	t_lemin		*lem;
}				t_lemin_mlx;

/*
** initialize
*/

void				lemin_init(t_lemin *lemin);
void				destroy_room(void *room, size_t size);
void				destroy_way(void *room_ways, size_t size);
void				lemin_destroy(t_lemin *lemin);

/*
** load data
*/

int					load_data(t_lemin *lemin);
void				set_rooms_number(t_lemin *lemin);
int					room_number(t_lemin *lemin, char *room_name);
void				edges_assign(t_lemin *lemin);
void				lemin_init_arrays(t_lemin *lemin);
void				lemin_fill_matrix(t_lemin *lem);
void				lemin_fill_rooms(t_lemin *lem);

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
** second try algorithm
*/

void				min_cost_f(t_lemin *lem);
void				lemin_print_res(t_lemin *lem);

/*
** aux functions
*/

void				print_intmatrix(int **matrix, int num_of_lines, int num_of_cols);

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

