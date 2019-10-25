#include "libft.h"
#include "push_swap.h"

void		do_operations(t_stack *a, t_stack *b, char *instr)
{
	if (ft_strequ(instr, "sa"))
		sa(a, b);
	else if (ft_strequ(instr, "sb"))
		sb(a, b);
	else if (ft_strequ(instr, "sb"))
		sb(a, b);
	else if (ft_strequ(instr, "ss"))
		ss(a, b);
	else if (ft_strequ(instr, "pa"))
		pa(a, b);
	else if (ft_strequ(instr, "pb"))
		pb(a, b);
	else if (ft_strequ(instr, "ra"))
		ra(a, b);
	else if (ft_strequ(instr, "rb"))
		rb(a, b);
	else if (ft_strequ(instr, "rr"))
		rr(a, b);
	else if (ft_strequ(instr, "rra"))
		rra(a, b);
	else if (ft_strequ(instr, "rrb"))
		rrb(a, b);
	else if (ft_strequ(instr, "rrr"))
		rrr(a, b);
}

void			use_program_to_stack(t_stack *a, t_stack *b, t_dlist *prog)
{
	char		*instr;
	t_dlist		*curr;

	if (prog == NULL)
		return ;
	instr = (char*)(prog->content);
	curr = prog;
	while (curr != NULL)
	{
		do_operations(a, b, instr);
		curr = curr->next;
		instr = (curr == NULL) ? NULL : curr->content;
	}
}
