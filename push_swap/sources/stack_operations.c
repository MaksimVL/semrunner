#include "libft.h"
#include "dlist.h"
#include "push_swap.h"

void			write_operation(char *str, t_stack *a, t_stack *b)
{
	a->count_operations++;
	pretty_print_stack(a, b);
	usleep(200000);
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
