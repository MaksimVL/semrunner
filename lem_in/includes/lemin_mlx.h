/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin_mlx.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odrinkwa <odrinkwa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/24 16:05:25 by odrinkwa          #+#    #+#             */
/*   Updated: 2019/11/24 23:17:37 by odrinkwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEMIN_MLX_H
# define LEMIN_MLX_H

# include "libft.h"
# include "lemin.h"
# include "fdf.h"

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
	int					show_ways;
}						t_lemin_mlx;

/*
** visualization
*/

void					tlemin_mlx_initialize(t_lemin_mlx *lm);
void					load_anthill_to_map_points(t_mlx *m, t_lemin *lem);
void					set_ants_to_start(t_lemin_mlx *lm);

void					calc_parameter_maps(t_mlx *m);

void					set_num_rooms_to_ant_moves(t_lemin *l);
void					create_ant_draw_move(t_lemin_mlx *lm);
void					set_flow_anthill(t_lemin *l);

void					start_load_ant_im(t_lemin_mlx *lm);
void					load_ant_im(t_lemin_mlx *lm);

void					put_names_rooms(t_mlx *m, t_lemin *l,
										t_lemin_mlx *lm, int color);
void					draw_anthill(t_lemin_mlx *lm, int not_black);
void					draw_ways (t_lemin_mlx *lm, int not_black);
int						lemin_keyhook(int keycode, void *lm);

void					set_ants_to_rooms_on_step(t_lemin_mlx *lm);
int						loop_ants_move(t_lemin_mlx *lm);

void					draw_ants(t_lemin_mlx *lm);
void					draw_ant(t_lemin_mlx *lm, int i, t_point p);

void					put_ant(t_lemin_mlx *lm, int x, int y);
void					put_all_anthill(void *lm);

void					finish_all(t_lemin_mlx *lm, int res);

#endif
