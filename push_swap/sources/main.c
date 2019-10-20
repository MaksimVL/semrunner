/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odrinkwa <odrinkwa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 18:48:15 by odrinkwa          #+#    #+#             */
/*   Updated: 2019/10/18 22:36:25 by odrinkwa         ###   ########.fr       */
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

void			find_max_stack(t_stack *b)
{
	int		pos;
	t_dlist	*curr_lst;

	if (b->len == 0)
	{
		b->pos_max = -1;
		return ;
	}
	curr_lst = b->top;
	pos = 0;
	b->max_stack = int_content(curr_lst);
	b->pos_max = 0;
	while (curr_lst != NULL)
	{
		if (b->max_stack < int_content(curr_lst))
		{
			b->max_stack = int_content(curr_lst);
			b->pos_max = pos;
		}
		curr_lst = curr_lst->next;
		pos++;
	}
}

void			find_min_stack(t_stack *b)
{
	int		pos;
	t_dlist	*curr_lst;

	if (b->len == 0)
	{
		b->pos_min = -1;
		return ;
	}
	curr_lst = b->top;
	pos = 0;
	b->min_stack = int_content(curr_lst);
	b->pos_min = 0;
	while (curr_lst != NULL)
	{
		if (b->min_stack > int_content(curr_lst))
		{
			b->min_stack = int_content(curr_lst);
			b->pos_min = pos;
		}
		curr_lst = curr_lst->next;
		pos++;
	}
}

void			find_between_desc_values(t_stack *b, int value)
{
	int			pos;
	t_dlist		*curr;
	t_dlist		*next;

	curr = b->top;
	pos = 0;
	b->pos_low_value = 0;
	b->low_value = int_content(b->top);
	while (curr->next != NULL)
	{
		pos++;
		if (int_content(curr) >= value && value >= int_content(curr->next))
			{
				b->pos_low_value = pos;
				b->low_value = int_content(curr->next);
				return ;
			}
		curr = curr->next;
	}

}

void			rotate_ab_to_top_value(t_stack *stack, int pos_value, char n_stack)
{
	if (pos_value  < (int)(stack->len / 2))
		while (pos_value-- > 0)
			n_stack == 'a' ? ra(stack, NULL) : rb(NULL, stack);
	else
		while (pos_value++ < stack->len)
			n_stack == 'a' ? rra(stack, NULL) : rrb(NULL, stack);
}

void			ra_to_top_value(t_stack *a, int pos_value)
{
	rotate_ab_to_top_value(a, pos_value, 'a');
}

void			rb_to_top_value(t_stack *b, int pos_value)
{
	rotate_ab_to_top_value(b, pos_value, 'b');
}




void			rotate_b_desc_for_insert_value(t_stack *b, int value)
{
	if (b->len == 0 || b->len == 1)
		return ;
	find_max_stack(b);
	find_min_stack(b);
	if (value > b->max_stack || value < b->min_stack)
		rb_to_top_value(b, b->pos_max);
	else
	{
		find_between_desc_values(b, value);
		rb_to_top_value(b, b->pos_low_value);
	}
}

void			pa_all(t_stack *a, t_stack *b)
{
	while (b->len > 0)
		pa(a, b);
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

int				main(int argc, char **argv)
{
	int			fd;
	t_stack		a;
	t_stack		b;
	int			i_tmp;
	char		*line;
	int			res;

	t_dlist	*lst;
	t_dlist	*tmplist;
	t_dlist	*lst_counter;

	int i;
	line = NULL;
	stack_initialize(&a);
	stack_initialize(&b);

/*	if (argc != 2)
		exit(0);*/
//	fd = open(argv[1], O_RDONLY);
	fd = open("stack1", O_RDONLY);
	while ((res = get_next_line(fd, &line)) == 1)
	{
		i = ft_atoi(line);
		stack_push(&a, i);
		ft_memdel((void**)&line);
	}
	close(fd);
	ft_memdel((void**)&line);

	if (res == -1)
		return (-1); // TODO учесть здесь очистку стека

	// пробуем алгоритм: делаем сортировку от большего к меньшему в стеке b

	// если стек пустой или 1 элемент - то ничего не делаем
	// если стек из двух элементов - то если не упорядочен - переставляем эти элементы.
	// если стек больше двух элементов и не упорядочен:
	// перекидываем из стека а в стек б элементы, упорядочивая их по убыванию.

	// реализуем для начала алгоритм для стека >= 3 элемента.

	print_stacks(&a, &b);

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
	ft_printf("sorted stack:\n");
	print_stacks(&a, &b);
	stack_del(&a);
	stack_del(&b);
}
