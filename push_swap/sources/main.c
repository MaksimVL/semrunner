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
	t_dlist		*top;
	t_dlist		*bottom;
}				t_stack;


void	del_int(void *content, size_t size)
{
	ft_memdel((void**)&content);
}

void			stack_initialize(t_stack *stack)
{
	stack->len = 0;
	stack->top = NULL;
	stack->bottom = NULL;
}

void			*stack_add(t_stack *stack, int a)
{
	t_dlist		*temp;

	temp = ft_dlstnew(&a, sizeof(a));
	if (temp == NULL)
		return (NULL);
	if (stack->top == NULL)
	{
		stack->len = 1;
		stack->top = temp;
		stack->bottom = temp;
	}
	else
	{
		ft_dlst_addback(&(stack->bottom), temp);
		stack->bottom = temp;
		stack->len += 1;
	}
	return stack;
}

void			stack_del(t_stack *stack)
{
	if (stack->len != 0)
	ft_dlstdel(&(stack->top), del_int);
	stack->len = 0;
	stack->bottom = NULL;
}

void			stack_print(t_stack *stack)
{
	t_dlist		*tmp;
	int			count_elements;

	ft_printf("--- start info stack ---\n");
	tmp = NULL;
	if (stack->top == NULL)
	{
		ft_printf("len = %d, top = %p, bottom = %p\n", stack->len, stack->top, stack->bottom);
		ft_printf("---  end info stack  ---\n");
		return ;
	}
	count_elements = 0;
	tmp = stack->top;
	ft_printf("len = %d, top = %d, bottom = %d\n", stack->len,
												*(int*)(stack->top->content),
												*(int*)(stack->bottom->content));
	while (tmp)
	{
		ft_printf("%d\n", *(int*)(tmp->content));
		tmp = tmp->next;
		count_elements++;
		if (count_elements > stack->len)
		{
			ft_printf("!! something wrong !!");
			break;
		}
	}
	ft_printf("---  end info stack  ---\n");
}

void			stack_swap(t_stack *stack)
{
	t_dlist	*top;
	t_dlist *next;
	t_dlist *nnext;

	if (stack->len == 0 || stack->len == 1)
		return ;
	top = stack->top;
	next = stack->top->next;
	nnext = next->next;
	next->prev = NULL;
	next->next = top;
	top->prev = next;
	top->next = nnext;
	if (nnext != NULL)
		nnext->prev = top;
	stack->top = next;
	if (stack->len == 2)
		stack->bottom = top;
}

void			stack_push(t_stack *a, t_stack *b)
{
	t_dlist *topa;
	t_dlist *topb;
	t_dlist *nextb;

	if (b->len == 0)
		return ;
	topa = a->top;
	topb = b->top;
	nextb = topb->next;
	topb->next = topa;
	if (a->len != 0)
		topa->prev = topb;
	else
		a->bottom = topb;
	a->len++;
	a->top = topb;
	if (b->len == 1)
	{
		b->top = NULL;
		b->bottom = NULL;
	}
	else
	{
		nextb->prev = NULL;
		b->top = nextb;
	}
	b->len--;
}

void			stack_rotate(t_stack *stack)
{
	t_dlist *top;
	t_dlist *bottom;
	t_dlist	*next;

	if (stack->len <= 1)
		return ;
	top = stack->top;
	bottom = stack->bottom;
	if (stack->len == 2)
	{
		top->next = NULL;
		bottom->prev = NULL;
		top->prev = bottom;
		bottom->next = top;
		stack->top = bottom;
		stack->bottom = top;
	}
	else
	{
		next = top->next;
		next->prev = NULL;
		bottom->next = top;
		top->prev = bottom;
		top->next = NULL;
		stack->top = next;
		stack->bottom = top;
	}
}

void			stack_rrotate(t_stack *stack)
{
	t_dlist *top;
	t_dlist *bottom;
	t_dlist	*prev;

	if (stack->len <= 1)
		return ;
	top = stack->top;
	bottom = stack->bottom;
	if (stack->len == 2)
	{
		top->next = NULL;
		bottom->prev = NULL;
		top->prev = bottom;
		bottom->next = top;
		stack->top = bottom;
		stack->bottom = top;
	}
	else
	{
		prev = bottom->prev;
		bottom->prev = NULL;
		bottom->next = top;
		top->prev = bottom;
		prev->next = NULL;
		stack->top = bottom;
		stack->bottom = prev;
	}
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

void			ra(t_stack *a, t_stack *b)
{
	if (b == NULL && b != NULL)
		return ;
	stack_rotate(a);
	ft_printf("ra\n");
}

void			rra(t_stack *a, t_stack *b)
{
	if (b == NULL && b != NULL)
		return ;
	stack_rrotate(a);
	ft_printf("ra\n");
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

	line = NULL;
	stack_initialize(&stack_a);
	stack_initialize(&stack_b);

/*	if (argc != 2)
		exit(0);*/
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

	if (res == -1)
		return (-1); // TODO учесть здесь очистку стека

	ft_printf("load from file stack_a:\n");
	stack_print(&stack_a);

	ft_printf("do sa, stack_a:\n");
	sa(&stack_a, &stack_b);
	stack_print(&stack_a);

	ft_printf("do sa again, stack_a:\n");
	sa(&stack_a, &stack_b);
	stack_print(&stack_a);

	ft_printf("do pb\n");
	pb(&stack_a, &stack_b);
	ft_printf("stack_a:\n");
	stack_print(&stack_a);
	ft_printf("stack_b:\n");
	stack_print(&stack_b);

	ft_printf("do pb again\n");
	pb(&stack_a, &stack_b);
	ft_printf("stack_a:\n");
	stack_print(&stack_a);
	ft_printf("stack_b:\n");
	stack_print(&stack_b);

	ft_printf("do pb again\n");
	pb(&stack_a, &stack_b);
	ft_printf("stack_a:\n");
	stack_print(&stack_a);
	ft_printf("stack_b:\n");
	stack_print(&stack_b);

	ft_printf("do pb again\n");
	pb(&stack_a, &stack_b);
	ft_printf("stack_a:\n");
	stack_print(&stack_a);
	ft_printf("stack_b:\n");
	stack_print(&stack_b);

	ft_printf("do pb again\n");
	pb(&stack_a, &stack_b);
	ft_printf("stack_a:\n");
	stack_print(&stack_a);
	ft_printf("stack_b:\n");
	stack_print(&stack_b);

	ft_printf("do pa\n");
	pa(&stack_a, &stack_b);
	ft_printf("stack_a:\n");
	stack_print(&stack_a);
	ft_printf("stack_b:\n");
	stack_print(&stack_b);
	ft_printf("do pa again\n");
	pa(&stack_a, &stack_b);
	ft_printf("stack_a:\n");
	stack_print(&stack_a);
	ft_printf("stack_b:\n");
	stack_print(&stack_b);

	ft_printf("do sb, stack_b:\n");
	sb(&stack_a, &stack_b);
	stack_print(&stack_b);

	ft_printf("do pa again\n");
	pa(&stack_a, &stack_b);
	ft_printf("stack_a:\n");
	stack_print(&stack_a);
	ft_printf("stack_b:\n");
	stack_print(&stack_b);

	ft_printf("do sb, stack_b:\n");
	sb(&stack_a, &stack_b);
	stack_print(&stack_b);

	ft_printf("do ra, stack_a:\n");
	ra(&stack_a, &stack_b);
	stack_print(&stack_a);

	ft_printf("do ra, stack_a:\n");
	ra(&stack_a, &stack_b);
	stack_print(&stack_a);

	ft_printf("do ra, stack_a:\n");
	ra(&stack_a, &stack_b);
	stack_print(&stack_a);

	ft_printf("do pb\n");
	pb(&stack_a, &stack_b);
	ft_printf("stack_a:\n");
	stack_print(&stack_a);
	ft_printf("stack_b:\n");
	stack_print(&stack_b);

	ft_printf("do ra, stack_a:\n");
	ra(&stack_a, &stack_b);
	stack_print(&stack_a);

	ft_printf("do pa\n");
	pa(&stack_a, &stack_b);
	ft_printf("stack_a:\n");
	stack_print(&stack_a);
	ft_printf("stack_b:\n");
	stack_print(&stack_b);

	ft_printf("do rra, stack_a:\n");
	rra(&stack_a, &stack_b);
	stack_print(&stack_a);

	ft_printf("do pa\n");
	pa(&stack_a, &stack_b);
	ft_printf("stack_a:\n");
	stack_print(&stack_a);
	ft_printf("stack_b:\n");
	stack_print(&stack_b);

	ft_printf("do rra, stack_a:\n");
	rra(&stack_a, &stack_b);
	stack_print(&stack_a);

	stack_del(&stack_a);
	stack_del(&stack_b);

}
