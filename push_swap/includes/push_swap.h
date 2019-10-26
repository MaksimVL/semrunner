/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odrinkwa <odrinkwa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 19:33:10 by odrinkwa          #+#    #+#             */
/*   Updated: 2019/10/26 14:42:55 by odrinkwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <math.h>
# include "terminal_draw.h"
# include "dlist.h"

typedef struct	s_stack
{
	int			len;
	t_dlist		*top;
	t_dlist		*bottom;
	int			max_stack;
	int			pos_max;
	int			min_stack;
	int			pos_min;
	int			low_value;
	int			pos_low_value;
	int			len_all;
	int			*array_int;
	int			coef_star_size;
	int			max_len_elem;
	int			count_operations;
	int			flag;
	int			flag_checker;
}				t_stack;

typedef struct	s_min
{
	int min;
	int type_rotation;
	int pos_a;
	int pos_b;
}				t_min;

typedef struct	s_longest_asc
{
	int			pos;
	int			count;
}				t_longest_asc;

int				int_content(t_dlist *list);

void			stack_initialize(t_stack *stack);
void			*stack_push(t_stack *stack, int a);
void			stack_del(t_stack *stack);
void			stack_print(t_stack *stack);
void			stack_swap(t_stack *stack);
void			stack_push_ab(t_stack *a, t_stack *b);
void			stack_rotate(t_stack *stack);
void			stack_rrotate(t_stack *stack);

int				peek_top(t_stack stack);
int				peek_bottom(t_stack stack);
int				peek_second(t_stack stack);

void			del_int(void *content, size_t size);

int				read_arguments(t_stack *a, t_dlist **prog, char *arg_str,
								char ***str_numbers);
int				read_stack_from_file(char *filename, t_stack *a,
						char ***str_numbers);
int				read_prog_from_file(char *filename, t_dlist **prog);
int				load_stack(t_stack *a, char *line_stack, char ***str_numbers);
int				check(t_stack *a);
void			sort(t_stack *a, t_stack *b);
int				check_sort_stack(t_stack *a);
void			use_program_to_stack(t_stack *a, t_stack *b, t_dlist *prog);

int				error_clear_vars(t_stack *a, t_stack *b,
						char ***str_numbers, t_dlist **prog);
int				normal_clear_vars(t_stack *a, t_stack *b,
						char ***str_numbers, t_dlist **prog);

int				load_program(t_dlist **prog, int fd);

void			find_max_stack(t_stack *b);
void			find_min_stack(t_stack *b);
void			find_between_desc_values(t_stack *b, int value);
void			find_between_asc_values(t_stack *a, int value);
void			find_between_asc_values_with_limits(t_stack *a, int value);
void			ra_to_top_value(t_stack *a, t_stack *b, int pos_value);
void			rb_to_top_value(t_stack *a, t_stack *b, int pos_value);
void			ra_to_bottom_value(t_stack *a, t_stack *b, int pos_value);
void			rb_to_bottom_value(t_stack *a, t_stack *b, int pos_value);
void			rotate_b_desc_for_insert_value(t_stack *a, t_stack *b,
								int value);
void			rotate_a_asc_for_insert_value(t_stack *a, t_stack *b,
								int value);
void			pa_all(t_stack *a, t_stack *b);

void			pretty_print_stack(t_stack *a, t_stack *b);
void			print_stacks(t_stack *a, t_stack *b);

void			stack_fill_and_sort_array_int(t_stack *a);
void			stack_set_max_len_el(t_stack *a);
void			sort_a_three_elements(t_stack *a, t_stack *b);
void			left_a_three_elements(t_stack *a, t_stack *b);
void			sort_le_five_elements(t_stack *a, t_stack *b);
void			main_sort_algorithm(t_stack *a, t_stack *b);
void			stack_sort(t_stack *a, t_stack *b);

void			first_group_stacks(t_stack *a, t_stack *b);
int				find_repeat_elements(t_stack *stack);

void			sa(t_stack *a, t_stack *b);
void			sb(t_stack *a, t_stack *b);
void			ss(t_stack *a, t_stack *b);
void			pa(t_stack *a, t_stack *b);
void			pb(t_stack *a, t_stack *b);
void			ra(t_stack *a, t_stack *b);
void			rb(t_stack *a, t_stack *b);
void			rr(t_stack *a, t_stack *b);
void			rra(t_stack *a, t_stack *b);
void			rrb(t_stack *a, t_stack *b);
void			rrr(t_stack *a, t_stack *b);
void			write_operation(char *str, t_stack *a, t_stack *b);

#endif
