#include "libft.h"
#include "dlist.h"
#include "push_swap.h"

void			find_max_stack(t_stack *b)
{
	int		pos;
	t_dlist	*curr_lst;

	if (b->len == 0)
	{
		b->pos_max = -1;
		return ;
	}
	curr_lst = b->top;
	pos = 0;
	b->max_stack = int_content(curr_lst);
	b->pos_max = 0;
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

void			find_min_stack(t_stack *b)
{
	int		pos;
	t_dlist	*curr_lst;

	if (b->len == 0)
	{
		b->pos_min = -1;
		return ;
	}
	curr_lst = b->top;
	pos = 0;
	b->min_stack = int_content(curr_lst);
	b->pos_min = 0;
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
	b->low_value = int_content(b->top);
	while (curr->next != NULL)
	{
		pos++;
		if (int_content(curr) >= value && value >= int_content(curr->next))
			{
				b->pos_low_value = pos;
				b->low_value = int_content(curr->next);
				return ;
			}
		curr = curr->next;
	}

}

void			rotate_ab_to_top_value(t_stack *stack, int pos_value, char n_stack)
{
	if (pos_value  < (int)(stack->len / 2))
		while (pos_value-- > 0)
			n_stack == 'a' ? ra(stack, NULL) : rb(NULL, stack);
	else
		while (pos_value++ < stack->len)
			n_stack == 'a' ? rra(stack, NULL) : rrb(NULL, stack);
}

void			ra_to_top_value(t_stack *a, int pos_value)
{
	rotate_ab_to_top_value(a, pos_value, 'a');
}

void			rb_to_top_value(t_stack *b, int pos_value)
{
	rotate_ab_to_top_value(b, pos_value, 'b');
}




void			rotate_b_desc_for_insert_value(t_stack *b, int value)
{
	if (b->len == 0 || b->len == 1)
		return ;
	find_max_stack(b);
	find_min_stack(b);
	if (value > b->max_stack || value < b->min_stack)
		rb_to_top_value(b, b->pos_max);
	else
	{
		find_between_desc_values(b, value);
		rb_to_top_value(b, b->pos_low_value);
	}
}

void			pa_all(t_stack *a, t_stack *b)
{
	while (b->len > 0)
		pa(a, b);
}
