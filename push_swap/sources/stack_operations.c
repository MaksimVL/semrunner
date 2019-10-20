#include "libft.h"
#include "dlist.h"
#include "push_swap.h"

#define SA 11
#define SB 12
#define SS 112
#define PA 21
#define PB 22
#define RA 31
#define RB 32
#define RR 312
#define RRA 41
#define RRB 42
#define RRR 412


void			write_operation(char *str)
{
	static int count;
	count++;
	ft_printf("%s - %d\n", str, count);
}
void			sa(t_stack *a, t_stack *b)
{
	if (b == NULL && b != NULL)
		return ;
	stack_swap(a);
	write_operation("sa");
}

void			sb(t_stack *a, t_stack *b)
{
	if (a == NULL && a != NULL)
		return ;
	stack_swap(b);
		write_operation("sb");
}

void			ss(t_stack *a, t_stack *b)
{
	stack_swap(a);
	stack_swap(b);
		write_operation("ss");
}

void			pa(t_stack *a, t_stack *b)
{
	stack_push_ab(a, b);
		write_operation("pa");
}

void			pb(t_stack *a, t_stack *b)
{
	stack_push_ab(b, a);
		write_operation("pb");
}

void			ra(t_stack *a, t_stack *b)
{
	if (b == NULL && b != NULL)
		return ;
	stack_rotate(a);
		write_operation("ra");
}

void			rb(t_stack *a, t_stack *b)
{
	if (a == NULL && a != NULL)
		return ;
	stack_rotate(b);
		write_operation("rb");
}

void			rr(t_stack *a, t_stack *b)
{
	stack_rotate(a);
	stack_rotate(b);
		write_operation("rr");
}

void			rra(t_stack *a, t_stack *b)
{
	if (b == NULL && b != NULL)
		return ;
	stack_rrotate(a);
		write_operation("rra");
}

void			rrb(t_stack *a, t_stack *b)
{
	if (a == NULL && a != NULL)
		return ;
	stack_rrotate(b);
		write_operation("rrb");
}

void			rrr(t_stack *a, t_stack *b)
{
	stack_rrotate(a);
	stack_rrotate(b);
		write_operation("rrr");
}
