/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odrinkwa <odrinkwa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 18:48:15 by odrinkwa          #+#    #+#             */
/*   Updated: 2019/10/17 00:34:10 by odrinkwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "libft.h"
#include "dlist.h"
#include "push_swap.h"

#include <float.h>

typedef struct	s_stack
{
	int			len;
	t_dlist		*data;
	t_dlist		*last_el;
}				t_stack;


void	del_int(void *content, size_t size)
{
	ft_memdel((void**)&content);
}

void			stack_initialize(t_stack *stack)
{
	stack->len = 0;
	stack->data = NULL;
	stack->last_el = NULL;
}

void			*stack_add(t_stack *stack, int a)
{
	t_dlist		*temp;

	temp = ft_dlstnew(&a, sizeof(a));
	if (temp == NULL)
		return (NULL);
	if (stack->data == NULL)
	{
		stack->len = 1;
		stack->data = temp;
		stack->last_el = temp;
	}
	else
	{
		ft_dlst_addback(&(stack->last_el), temp);
		stack->last_el = temp;
		stack->len += 1;
	}
	return stack;
}

void			stack_del(t_stack *stack)
{
	ft_dlstdel(&(stack->data), del_int);
	stack->len = 0;
	stack->last_el = NULL;
}

void			stack_print(t_stack *stack)
{
	t_dlist		*tmp;

	tmp = NULL;
	if (stack->data == NULL)
		return ;
	tmp = stack->data;
	while (tmp)
	{
		ft_printf("%d\n", *(int*)(tmp->content));
		tmp = tmp->next;
	}
}

void			stack_swap(t_stack *stack)
{
	t_dlist	*curr;
	t_dlist *prev;
	t_dlist *prevprev;

	if (stack->len == 0 || stack->len == 1)
		return ;
	curr = stack->last_el;
	prev = stack->last_el->prev;
	prevprev = prev->prev;
	curr->prev = prevprev;
	curr->next = prev;
	prev->prev = curr;
	prev->next = NULL;
	if (prevprev != NULL)
		prevprev->next = curr;
	stack->last_el = prev;
}

void			stack_push(t_stack *a, t_stack *b)
{
	t_dlist *prev_b;
	t_dlist *curr_b;

	if (b->len == 0)
		return ;
	prev_b = b->last_el->prev;
	curr_b = b->last_el;
	prev_b->next = NULL;
	b->last_el = prev_b;
	a->last_el->next = curr_b;
	curr_b->prev = a->last_el;
	a->last_el = curr_b;
	b->len--;
	a->len++;
}

void			stack_rotate(t_stack *stack)
{
	t_dlist *first_el;
	t_dlist *last_el;
	t_dlist	*second_el;
	t_dlist *lastprev;

	if (stack->len <= 1)
		return ;
	first_el = stack->data;
	second_el = first_el->next;
	last_el = stack->last_el;
	lastprev = last_el->prev;
	first_el->next = NULL;
	first_el->prev = lastprev;
	second_el->prev = last_el;
	last_el->next = second_el;
	last_el->prev = NULL;
	lastprev->next = first_el;
	stack->data = last_el;
	stack->last_el = first_el;
}


void			sa(t_stack *a, t_stack *b)
{
	if (b == NULL && b != NULL)
		return ;
	stack_swap(a);
	ft_printf("sa\n");
}

void			sb(t_stack *a, t_stack *b)
{
	if (a == NULL && a != NULL)
		return ;
	stack_swap(b);
	ft_printf("sb\n");
}

void			ss(t_stack *a, t_stack *b)
{
	stack_swap(a);
	stack_swap(b);
	ft_printf("ss\n");
}

void			pa(t_stack *a, t_stack *b)
{
	stack_push(a, b);
	ft_printf("pa\n");
}

void			pb(t_stack *a, t_stack *b)
{
	stack_push(b, a);
	ft_printf("pb\n");
}

void			dlist_print(t_dlist lst)
{
	ft_printf("%d", *(int*)(lst.content));
}
int				dlist_int(t_dlist lst)
{
	return (*(int*)lst.content);
}

int				main(int argc, char **argv)
{
	int			fd;
	t_stack		stack_a;
	t_stack		stack_b;
	int			i_tmp;
	char		*line;
	int			res;

	t_dlist	*lst;
	t_dlist	*tmplist;
	t_dlist	*lst_counter;

	int		a = 1;
	int		b = 2;
	int		c = 3;
	int		d = 4;
	int		e = 5;

	lst = NULL;
	ft_printf("test\n");
	tmplist = ft_dlstnew((void*)&a, sizeof(a));
	ft_dlst_addback(&lst, tmplist);

	ft_printf("%d\n", *(int*)(lst->content));
	tmplist = ft_dlstnew((void*)&b, sizeof(b));
	ft_dlst_addback(&lst, tmplist);

	tmplist = ft_dlstnew((void*)&c, sizeof(c));
	ft_dlst_addback(&lst, tmplist);

	lst_counter = lst;
	while (lst_counter)
	{
		ft_printf("%d\n", *(int*)(lst_counter->content));
		lst_counter = lst_counter->next;
	}

	ft_dlstdel(&lst, &del_int);

	line = NULL;
	stack_initialize(&stack_a);

/*	if (argc != 2)
		exit(0);*/
	ft_printf("test\n");

//	fd = open(argv[1], O_RDONLY);
	fd = open("stack1", O_RDONLY);
	while ((res = get_next_line(fd, &line)) == 1)
	{
		a = ft_atoi(line);
		stack_add(&stack_a, a);
		ft_memdel((void**)&line);
	}
	close(fd);
	ft_memdel((void**)&line);
	ft_printf("stack_a:\n");
	stack_print(&stack_a);
	sa(&stack_a, &stack_b);
	ft_printf("sa, stack_a:\n");
	stack_print(&stack_a);

	stack_rotate(&stack_a);
	ft_printf("ra, stack_a:\n");
	stack_print(&stack_a);


	stack_del(&stack_a);
	if (res == -1)
		return (-1);
}
