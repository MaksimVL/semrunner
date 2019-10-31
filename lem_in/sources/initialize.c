#include "libft.h"
#include "lemin.h"

void			destroy_room(void *room, size_t size)
{
	if (size == 0 && size != 0)
		;
	ft_memdel((void**)&(((t_room*)room)->name));
}

void			destroy_way(void *room_ways, size_t size)
{
	if (size == 0 && size != 0)
		;
	ft_memdel((void**)&((t_room_ways*)room_ways)->start_room);
	ft_memdel((void**)&((t_room_ways*)room_ways)->end_room);
}

void			lemin_destroy(t_lemin *lemin)
{
	if (lemin->list_rooms != NULL)
		ft_dlstdel(&(lemin->list_rooms), destroy_room);
	if (lemin->room_ways != NULL)
		ft_dlstdel(&(lemin->room_ways), destroy_way);
}

void			lemin_init(t_lemin *lemin)
{
	lemin->c = NULL;
	lemin->list_rooms = NULL;
	lemin->room_ways = NULL;
	lemin->count_rooms = 0;
}
