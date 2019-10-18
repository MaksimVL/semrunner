#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <math.h>

typedef struct	s_stack
{
	int			len;
	t_dlist		*top;
	t_dlist		*bottom;
	int			max_stack;
	int			pos_max;
	int			min_stack;
	int			pos_min;
	int			low_value;
	int			pos_low_value;
}				t_stack;

int				int_content(t_dlist *list);

void			stack_initialize(t_stack *stack);
void			*stack_push(t_stack *stack, int a);
void			stack_del(t_stack *stack);
void			stack_print(t_stack *stack);
void			stack_swap(t_stack *stack);
void			stack_push_ab(t_stack *a, t_stack *b);
void			stack_rotate(t_stack *stack);
void			stack_rrotate(t_stack *stack);

int				peek_top(t_stack stack);
int				peek_bottom(t_stack stack);
int				peek_second(t_stack stack);


void			sa(t_stack *a, t_stack *b);
void			sb(t_stack *a, t_stack *b);
void			ss(t_stack *a, t_stack *b);
void			pa(t_stack *a, t_stack *b);
void			pb(t_stack *a, t_stack *b);
void			ra(t_stack *a, t_stack *b);
void			rb(t_stack *a, t_stack *b);
void			rb(t_stack *a, t_stack *b);
void			rra(t_stack *a, t_stack *b);
void			rrb(t_stack *a, t_stack *b);
void			rrb(t_stack *a, t_stack *b);

#endif
