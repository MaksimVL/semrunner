#include "libft.h"

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
	int					**c;
	t_dlist				*list_rooms;
	t_dlist				*room_ways;
	int					count_rooms; // N
	int					number_of_ants; // K
	int					count_edges;
	t_edge				*edges;

	int					**adj;
	int					**cost;
	int					**capacity;
	int					s;
	int					t;
}						t_lemin;

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

/*
** print properties
*/

void				print_room_property(t_dlist *lst);
void				print_all_rooms_property(t_dlist *lst);
void				print_links(t_dlist *lst);
void				print_all_links(t_dlist *lst);
void				print_all_edges(t_lemin *lemin);
