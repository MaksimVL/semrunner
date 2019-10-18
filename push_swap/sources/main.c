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
		return (0);
	}
	curr_lst = b->top;
	pos = 0;
	b->max_stack = int_content(curr_lst);
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

int				find_min_stack(t_stack *b)
{
	int		pos;
	t_dlist	*curr_lst;

	if (b->len == 0)
	{
		b->pos_min = -1;
		return (0);
	}
	curr_lst = b->top;
	pos = 0;
	b->min_stack = int_content(curr_lst);
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
	b->low_value = b->top;
	while (curr->next != NULL)
	{
		pos++;
		if (int_content(curr) >= value && value >= int_content(curr->next))
			{
				b->pos_low_value = pos;
				b->low_value = int_content(curr->next);
				return ;
			}
	}

}

void			rotate_to_top_value(t_stack *b, int pos_value)
{
	if (pos_value  < (int)(b->len / 2))
		while (pos_value-- > 0)
			rb(NULL, b);
	else
		while (pos_value++ < b->len)
			rrb(NULL, b);
}

void			rotate_b(t_stack *b, int value)
{
	if (b->len == 0 || b->len == 1)
		return ;
	find_max_stack(b);
	find_min_stack(b);
	if (value > b->max_stack || value < b->min_stack)
		rotate_to_top_value(b, b->pos_max);
	else
	{
		find_between_values(b, value);
		rotate_to_top_value(b, b->pos_low_value);
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

	while (a.len > 0)
	{
		if (b.len == 0)
		{
			pb(&a, &b);
			continue;
		}
		if (b.len == 1)
			pb(&a, &b);
			if (peek_top(b) < peek_bottom(b))
				sb(&a, &b);
			continue;
		rotate_b(&b, peek_top(a));
		pb(&a, &b);

	}


	stack_del(&a);
	stack_del(&b);


}
