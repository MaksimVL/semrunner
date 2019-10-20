/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odrinkwa <odrinkwa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 18:48:15 by odrinkwa          #+#    #+#             */
/*   Updated: 2019/10/20 21:12:58 by odrinkwa         ###   ########.fr       */
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


	// пробуем алгоритм: делаем сортировку от большего к меньшему в стеке b

	// если стек пустой или 1 элемент - то ничего не делаем
	// если стек из двух элементов - то если не упорядочен - переставляем эти элементы.
	// если стек больше двух элементов и не упорядочен:
	// перекидываем из стека а в стек б элементы, упорядочивая их по убыванию.

	// реализуем для начала алгоритм для стека >= 3 элемента.

//	print_stacks(&a, &b);

	//sorting stack
	if (a.len < 2)
		;
	else if (a.len == 2)
	{
		if (peek_top(a) > peek_bottom(a))
			sa(&a, &b);
	}
	else
	{
		while (a.len > 0)
		{
			if (b.len == 0)
			{
				pb(&a, &b);
				continue;
			}
			if (b.len == 1)
			{
				pb(&a, &b);
				if (peek_top(b) < peek_bottom(b))
					sb(&a, &b);
				continue;
			}
			rotate_b_desc_for_insert_value(&b, peek_top(a));
			pb(&a, &b);
		}
		find_max_stack(&b);
		rb_to_top_value(&b, b.pos_max);
		pa_all(&a, &b);
	}
//	ft_printf("sorted stack:\n");
//	print_stacks(&a, &b);
	stack_del(&a);
	stack_del(&b);
}
