#include "libft.h"
#include "lemin.h"
#include "mlx.h"
#include "fdf.h"

int		keyhook_move_ants(int keycode, t_lemin_mlx *lm)
{
	if (keycode == 43 && lm->lem->current_step > 0)
		lm->lem->current_step--;
	else if (keycode == 44)
		lm->lem->current_step = 0;
	else if (keycode == 47 && lm->lem->current_step < lm->lem->max_step)
		lm->lem->current_step += 1;
	else if (keycode == 46)
		lm->nonstop = (lm->nonstop + 1) % 2;
	else if (keycode == 30 && lm->speed > 2)
		lm->speed /= 2;
	else if (keycode == 33 && lm->speed < 16)
		lm->speed *= 2;
	else
		return (0);
	return (1);
}

int		keycode_change_size_room(int keycode, t_lemin_mlx *lm)
{
	if (keycode == 42 && lm->size_ant_im < 40)
		lm->size_ant_im += 10;
	else if (keycode == 39 && lm->size_ant_im > 10)
		lm->size_ant_im -= 10;
	else
		return (0);
	return (1);
}

int		keycode_names_room(int keycode, t_lemin_mlx *lm)
{
	if (keycode == 35)
		lm->show_room_numbers = (lm->show_room_numbers + 1) % 2;
	else if (keycode == 31)
		lm->show_not_use_edges = (lm->show_not_use_edges + 1) % 2;
	else
		return (0);
	return (1);
}

int		lemin_keyhook(int keycode, void *lm)
{
	ft_printf("%d\n", keycode);
	if (keycode == 12 || keycode == 53)
		finish_all((t_lemin_mlx*)lm, -10);

	if (check_keyhooks_fdf(keycode) ||
		keycode == 39 || keycode == 42 || keycode == 35 || keycode == -1 || keycode == 31)
		{
			draw_anthill((t_lemin_mlx*)lm, 0);
			keyhooks(keycode, ((t_lemin_mlx*)lm)->m);
			keycode_names_room(keycode, ((t_lemin_mlx*)lm));
			if (keycode_change_size_room(keycode, ((t_lemin_mlx*)lm)))
				load_ant_im(lm);
			make_map_points(((t_lemin_mlx*)lm)->m);
			draw_anthill((t_lemin_mlx*)lm, 1);
			put_all_anthill(lm);
			ft_printf("draw_anthill\n");
		}
	if (keyhook_move_ants(keycode, ((t_lemin_mlx*)lm)))
		set_ants_to_rooms_on_step(lm);
	if (keycode == -1)
		set_ants_to_start((t_lemin_mlx*)lm);
	return (1);
}
