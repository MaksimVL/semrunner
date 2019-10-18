#include "libft.h"
#include "dlist.h"
#include "push_swap.h"

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
	stack_push_ab(a, b);
	ft_printf("pa\n");
}

void			pb(t_stack *a, t_stack *b)
{
	stack_push_ab(b, a);
	ft_printf("pb\n");
}

void			ra(t_stack *a, t_stack *b)
{
	if (b == NULL && b != NULL)
		return ;
	stack_rotate(a);
	ft_printf("ra\n");
}

void			rb(t_stack *a, t_stack *b)
{
	if (a == NULL && a != NULL)
		return ;
	stack_rotate(b);
	ft_printf("rb\n");
}

void			rr(t_stack *a, t_stack *b)
{
	stack_rotate(a);
	stack_rotate(b);
	ft_printf("rr\n");
}

void			rra(t_stack *a, t_stack *b)
{
	if (b == NULL && b != NULL)
		return ;
	stack_rrotate(a);
	ft_printf("rra\n");
}

void			rrb(t_stack *a, t_stack *b)
{
	if (a == NULL && a != NULL)
		return ;
	stack_rrotate(b);
	ft_printf("rrb\n");
}

void			rrr(t_stack *a, t_stack *b)
{
	stack_rrotate(a);
	stack_rrotate(b);
	ft_printf("rrr\n");
}
