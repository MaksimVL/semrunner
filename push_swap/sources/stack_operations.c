#include "libft.h"
#include "dlist.h"
#include "push_swap.h"

void	print_stars(int count)
{
	while(count-- > 0)
		ft_printf("*");
}

int				get_size_stack_elem(t_stack *a, t_dlist *curr_el)
{
	int		i;

	i = 0;
	while (i < a->len_all)
	{
		if (a->array_int[i] == int_content(curr_el))
			return ((i + 1) / a->coef_star_size);
		i++;
	}
	return (0);
}

void			pretty_print_stack(t_stack *a, t_stack *b)
{
	int i;
	int width;
	t_dlist *curr_a;
	t_dlist *curr_b;

	HOME()
	CLRSCR()
	curr_a = (a != NULL) ? a->top : NULL;
	curr_b = (b != NULL) ? b->top : NULL;
	i = 1;
	width = a->len_all + 15;
	while (curr_a != NULL || curr_b != NULL)
	{
		SETCOLOR(F_RED)
		if (curr_a != NULL)
		{
			ft_printf("% *d ", a->max_len_elem + 2, int_content(curr_a));
			print_stars(get_size_stack_elem(a, curr_a));
			curr_a = curr_a->next;
		}
		GOTOXY(width, i)
		SETCOLOR(F_GREEN)
		if (curr_b != NULL)
		{
			ft_printf("% *d ", a->max_len_elem + 2, int_content(curr_b));
			print_stars(get_size_stack_elem(a, curr_b));
			curr_b = curr_b->next;
		}
		ft_printf("\n");
		i++;
	}
	RESET_COLOR()
}

void			write_operation(char *str, t_stack *a, t_stack *b)
{
	a->count_operations++;
	pretty_print_stack(a, b);
	usleep(100000);
}
void			sa(t_stack *a, t_stack *b)
{
	if (b == NULL && b != NULL)
		return ;
	stack_swap(a);
	write_operation("sa", a, b);
}

void			sb(t_stack *a, t_stack *b)
{
	if (a == NULL && a != NULL)
		return ;
	stack_swap(b);
		write_operation("sb", a, b);
}

void			ss(t_stack *a, t_stack *b)
{
	stack_swap(a);
	stack_swap(b);
		write_operation("ss", a, b);
}

void			pa(t_stack *a, t_stack *b)
{
	stack_push_ab(a, b);
		write_operation("pa", a, b);
}

void			pb(t_stack *a, t_stack *b)
{
	stack_push_ab(b, a);
		write_operation("pb", a, b);
}

void			ra(t_stack *a, t_stack *b)
{
	if (b == NULL && b != NULL)
		return ;
	stack_rotate(a);
		write_operation("ra", a, b);
}

void			rb(t_stack *a, t_stack *b)
{
	if (a == NULL && a != NULL)
		return ;
	stack_rotate(b);
		write_operation("rb", a, b);
}

void			rr(t_stack *a, t_stack *b)
{
	stack_rotate(a);
	stack_rotate(b);
		write_operation("rr", a, b);
}

void			rra(t_stack *a, t_stack *b)
{
	if (b == NULL && b != NULL)
		return ;
	stack_rrotate(a);
		write_operation("rra", a, b);
}

void			rrb(t_stack *a, t_stack *b)
{
	if (a == NULL && a != NULL)
		return ;
	stack_rrotate(b);
		write_operation("rrb", a, b);
}

void			rrr(t_stack *a, t_stack *b)
{
	stack_rrotate(a);
	stack_rrotate(b);
		write_operation("rrr", a, b);
}
