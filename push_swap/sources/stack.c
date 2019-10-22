#include "libft.h"
#include "dlist.h"
#include "push_swap.h"

void	del_int(void *content, size_t size)
{
	ft_memdel((void**)&content);
}

int				int_content(t_dlist *list)
{
	return *(int*)(list->content);
}

int				peek_top(t_stack stack)
{
	return (*(int*)(stack.top->content));
}

int				peek_bottom(t_stack stack)
{
	return (*(int*)(stack.bottom->content));
}

int				peek_second(t_stack stack)
{
	return (*(int*)(stack.top->next->content));
}

void			stack_initialize(t_stack *stack)
{
	stack->len = 0;
	stack->top = NULL;
	stack->bottom = NULL;
	stack->pos_min = -1;
	stack->pos_max = -1;
	stack->array_int = NULL;
	stack->coef_star_size = 1;
	stack->max_len_elem = 0;
	stack->count_operations = 0;
}

void			*stack_push(t_stack *stack, int a)
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
	stack->pos_max = -1;
	stack->pos_min = -1;
	return stack;
}

void			stack_del(t_stack *stack)
{
	if (stack->len != 0)
		ft_dlstdel(&(stack->top), del_int);
	if (stack->array_int != NULL)
		ft_memdel((void**)&(stack->array_int));
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

void			stack_push_ab(t_stack *a, t_stack *b)
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
	a->pos_max = -1;
	a->pos_min = -1;
	b->pos_max = -1;
	b->pos_min = -1;
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
