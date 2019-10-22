/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odrinkwa <odrinkwa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 18:48:15 by odrinkwa          #+#    #+#             */
/*   Updated: 2019/10/22 23:50:29 by odrinkwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "libft.h"
#include "dlist.h"
#include "push_swap.h"

#include <float.h>

void			dlist_print(t_dlist lst)
{
	ft_printf("%d", *(int*)(lst.content));
}

int				dlist_int(t_dlist lst)
{
	return (*(int*)lst.content);
}



void			print_stacks(t_stack *a, t_stack *b)
{
		ft_printf("-------------- start print stacks ----------\n");
		ft_printf("'''stack a:\n");
		stack_print(a);
		ft_printf("'''stack b:\n");
		stack_print(b);
		ft_printf("--------------  end print stacks  ----------\n");
}


void			free_strsplit(char **strings)
{
	int		i;

	if (strings == NULL)
		return ;
	i = 0;
	while (strings[i] != 0)
	{
		ft_memdel((void**)&(strings[i]));
		i++;
	}
	ft_memdel((void**)&(strings[i]));
	ft_memdel((void**)strings);
}

int				ft_isint(char *str)
{
	int i;
	int count_numbers;

	if (str == NULL || str[0] == '\0')
		return (0);
	else if (ft_isdigit(str[0]))
		count_numbers = 1;
	else if (str[0] == '-' || str[0] == '+')
		count_numbers = 0;
	else
		return (0);
	i = 1;
	while (str[i] != '\0')
	{
		if (ft_isdigit(str[i]) == 0)
			return (0);
		count_numbers++;
		i++;
	}
	return ((count_numbers == 0) ? 0 : 1);
}

int				find_repeat_elements(t_stack *stack)
{
	t_dlist		*curr;
	t_dlist		*i_lst;
	int			curr_value;

	if (stack->len == 0)
		return (1);
	curr = stack->top;
	curr_value = int_content(curr);
	while (curr != NULL)
	{
		i_lst = curr->next;
		while (i_lst != NULL)
		{
			if (curr_value == int_content(i_lst))
				return (1);
			i_lst = i_lst->next;
		}
		curr = curr->next;
	}
	return (0);
}

int				check_sorted_stack(t_stack *stack)
{
	t_dlist	*curr;

	curr = stack->top;
	while (curr != NULL)
	{
		if (curr->next == NULL)
			return (1);
		if (int_content(curr) > int_content(curr->next))
			return (0);
		curr = curr->next;
	}
	return (1);
}

void			sort_a_three_elements(t_stack *a, t_stack *b)
{
	find_max_stack(a);
	ra_to_bottom_value(a, b, a->pos_max);
	if (peek_top(*a) > peek_second(*a))
				sa(a, b);
}

void			left_a_three_elements(t_stack *a, t_stack *b)
{
	while (a->len > 3)
	pb(a, b);
}




void			sort_le_five_elements(t_stack *a, t_stack *b)
{
	while (a->len > 3)
		pb(a, b);
	sort_a_three_elements(a, b);
	while (b->len > 0)
	{
		rotate_a_asc_for_insert_value(a, b, peek_top(*b));
		pa(a, b);
	}
	find_max_stack(a);
	ra_to_bottom_value(a, b, a->pos_max);
}

typedef struct		s_min
{
	int min;
	int type_rotation;
	int pos_a;
	int pos_b;
}					t_min;
t_min		find_minimum_operations_stack(int pos_b, int rrb_pos_b, int pos_a, int rra_pos_a)
{
	int min;
	int type_rotation;
	t_min res;

// type rotation: rr - 1; rrr - 2; rb, rra - 3; ra, rrb - 4

	type_rotation = 1;
	min = MAX(pos_b, pos_a);

	if (MAX(rrb_pos_b, rra_pos_a) < min)
	{
		min = MAX(rrb_pos_b, rra_pos_a);
		type_rotation = 2;
	}

	if (pos_b + rra_pos_a < min)
	{
		min = pos_b + rra_pos_a;
		type_rotation = 3;
	}
	if (pos_a + rrb_pos_b < min)
	{
		min = pos_a + rrb_pos_b;
		type_rotation = 4;
	}
	res.min = min;
	res.type_rotation = type_rotation;
	return (res);
}

typedef struct	s_longest_asc
{
	int			pos;
	int			count;
}				t_longest_asc;

t_longest_asc	search_longest_asc(t_stack *a)
{
	t_dlist		*curr;
	t_dlist		*curr_curr;
	t_dlist		*next;
	t_longest_asc	curr_asc;
	t_longest_asc	max;

	curr = a->top;
	curr_asc.pos = 0;
	max.pos = -1;
	max.count = -1;
	while (curr != NULL)
	{
		curr_asc.count = 1;
		curr_curr = curr;
		while (curr_curr != NULL && curr_curr->next != NULL && int_content(curr_curr) < int_content(curr_curr->next))
		{
			curr_curr = curr_curr->next;
			curr_asc.count++;
		}

		if (curr_asc.count > max.count)
		{
			max.count = curr_asc.count;
			max.pos = curr_asc.pos;
		}
		curr = curr->next;
		curr_asc.pos++;
	}
	return (max);
}

void			first_group_stacks(t_stack *a, t_stack *b)
{
	t_longest_asc	asc;
	int				len_a;

	len_a = a->len;
	asc = search_longest_asc(a);
	if (asc.count == len_a)
		return ;
	if (asc.count > 3)
	{
		while (asc.pos > 0)
		{
			pb(a, b);
			asc.pos--;
			len_a--;
		}
		if (asc.count == len_a)
			return ;
		while(asc.count > 0)
		{
			ra(a, b);
			asc.count--;
			len_a--;
		}
		while(len_a > 0)
		{
			pb(a, b);
			len_a--;
		}
	}
	else
	{
		left_a_three_elements(a, b);
		sort_a_three_elements(a, b);
	}

}

void			main_sort_algorithm(t_stack *a, t_stack *b)
{
	t_dlist		*curr_b;
	int			pos_b;
	t_min		min_operations;
	t_min		min_tmp;

	// left_a_three_elements(a, b);
	// sort_a_three_elements(a, b);

	first_group_stacks(a, b);
	while (b->len > 0)
	{
		curr_b = b->top;
		pos_b = 0;
		min_operations.pos_a = -1;
		while (curr_b != NULL)
		{
			find_between_asc_values_with_limits(a, int_content(curr_b));
			min_tmp = find_minimum_operations_stack(pos_b, b->len - pos_b, a->pos_low_value, a->len - a->pos_low_value);
			if (min_operations.pos_a == -1)
			{
				min_operations = min_tmp;
				min_operations.pos_a = a->pos_low_value;
				min_operations.pos_b = pos_b;
			}
			else if (min_tmp.min < min_operations.min)
			{
				min_operations = min_tmp;
				min_operations.pos_a = a->pos_low_value;
				min_operations.pos_b = pos_b;
			}
			curr_b = curr_b->next;
			pos_b++;
		}
		if (min_operations.type_rotation == 3 || min_operations.type_rotation == 4)
		{
			ra_to_top_value(a, b, min_operations.pos_a);
			rb_to_top_value(a, b, min_operations.pos_b);
		}
		else if (min_operations.type_rotation == 1)
		{
			while(min_operations.pos_a > 0 && min_operations.pos_b > 0)
			{
				rr(a, b);
				min_operations.pos_a--;
				min_operations.pos_b--;
			}
			ra_to_top_value(a, b, min_operations.pos_a);
			rb_to_top_value(a, b, min_operations.pos_b);
		}
		else
		{
			while(min_operations.pos_a < a->len && min_operations.pos_b < b->len)
			{
				rrr(a, b);
				min_operations.pos_a++;
				min_operations.pos_b++;
			}
			ra_to_top_value(a, b, min_operations.pos_a);
			rb_to_top_value(a, b, min_operations.pos_b);
		}


		pa(a, b);
	}
	find_max_stack(a);
	ra_to_bottom_value(a, b, a->pos_max);
}

void	stack_fill_and_sort_array_int(t_stack *a)
{
	t_dlist		*curr;
	int			i;
	int			j;
	int			tmp_int;

	i = 0;
	curr = a->top;
	while (curr != NULL)
	{
		a->array_int[i] = int_content(curr);
		i++;
		curr = curr->next;
	}
	i = 0;
	while (i < a->len_all - 1)
	{
		j = i + 1;
		while (j < a->len_all)
		{
			if (a->array_int[j] < a->array_int[i])
			{
				tmp_int = a->array_int[j];
				a->array_int[j] = a->array_int[i];
				a->array_int[i] = tmp_int;
			}

			j++;
		}
		i++;
	}
}

void	stack_set_max_len_el(t_stack *a)
{
	int		i;
	int		len_nbr;

	i = 0;
	while (i < a->len_all)
	{
		len_nbr = ft_nbrlen(a->array_int[i]);
		if (a->max_len_elem < len_nbr)
			a->max_len_elem = len_nbr;
		i++;
	}
}

int				main(int argc, char **argv)
{
	int			fd;
	t_stack		a;
	t_stack		b;
	int			i_tmp;
	char		*line;
	int			res;
	char		**str_numbers;

	t_dlist	*lst;
	t_dlist	*tmplist;
	t_dlist	*lst_counter;

	int i;
	int j;
	line = NULL;
	stack_initialize(&a);
	stack_initialize(&b);

	if (argc < 2)
		{
			ft_printf("error: no stack\n");
			stack_del(&a);
			stack_del(&b);
			return (-1);
		}
	i = 1;

	while (i < argc)
	{
		str_numbers = ft_strsplit(argv[i], ' '); // TODO проверка на NULL
		j = 0;
		while (str_numbers[j] != 0)
		{
			if (ft_isint(str_numbers[j]) == 0)
			{
				ft_printf("error: found not number elements\n");
				free_strsplit(str_numbers);
				stack_del(&a);
				return (-1); // TODO сделать соответствующую очистку памяти
			}

			stack_push(&a, ft_atoi(str_numbers[j]));
			j++;
		}
		free_strsplit(str_numbers);
		i++;
	}


	if (a.len == 0)
	{
		ft_printf("error: empty stack\n");
		return (-1); // TODO сделать проверку очистки данных
	}

	if (find_repeat_elements(&a) == 1)
	{
		ft_printf("error: found repeating elements\n");
		stack_del(&a);
		return (-1);  // сделать проверки на очистки данных и т.п.
	}

	a.len_all = a.len;
	a.array_int = (int*)ft_memalloc(sizeof(int) * a.len_all); //TODO проверка на выделение памяти, очистка если ошибка

	stack_fill_and_sort_array_int(&a);
	stack_set_max_len_el(&a);


	//sorting stack
	if (a.len < 2)
		;
	else if (a.len == 2)
	{
		if (peek_top(a) > peek_bottom(a))
			sa(&a, &b);
	}
	else if (a.len == 3)
		sort_a_three_elements(&a, &b);
	else
		main_sort_algorithm(&a, &b);

	pretty_print_stack(&a, &b);
	ft_printf("count of elements: %d, count of operations: %d\n", a.len_all, a.count_operations);
	// ft_printf("sorted stack:\n");
	// print_stacks(&a, &b);

	stack_del(&a);
	stack_del(&b);
}
