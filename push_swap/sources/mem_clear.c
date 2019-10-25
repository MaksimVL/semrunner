#include "libft.h"
#include "push_swap.h"

static void		del_str(void *content, size_t size)
{
	if (size == 0)
		;
	ft_memdel((void**)&content);
}

static void		clear_vars(t_stack *a, t_stack *b,
						char ***str_numbers, t_dlist **prog)
{
	stack_del(a);
	stack_del(b);
	ft_dlstdel(prog, del_str);
	ft_del_strsplit(str_numbers);
}

int				error_clear_vars(t_stack *a, t_stack *b,
						char ***str_numbers, t_dlist **prog)
{
	clear_vars(a, b, str_numbers, prog);
	ft_printf("%wError\n", 2);
	return (-1);
}

int				normal_clear_vars(t_stack *a, t_stack *b,
						char ***str_numbers, t_dlist **prog)
{
	clear_vars(a, b, str_numbers, prog);
	return (0);
}
