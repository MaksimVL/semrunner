#include "libft.h"
#include "push_swap.h"

static int		add_command_in_prog(t_dlist **prog, char *line)
{
	t_dlist		*new;

	if (!(new = ft_dlstnew(line, ft_strlen(line) + 1)))
		return (0);
	ft_dlst_addback(prog, new);
	return (1);
}

int				load_program(t_dlist **prog, int fd)
{
	int		res;
	char	*line;

	line = NULL;
	while ((res = get_next_line(fd, &line)) == 1)
	{
		if (!(ft_strequ(line, "sa") || ft_strequ(line, "sb") ||
			ft_strequ(line, "ss") || ft_strequ(line, "pa") ||
			ft_strequ(line, "pb") || ft_strequ(line, "ra") ||
			ft_strequ(line, "rb") || ft_strequ(line, "rr") ||
			ft_strequ(line, "rra") || ft_strequ(line, "rrb") ||
			ft_strequ(line, "rrr")) || (!(add_command_in_prog(prog, line))))
			{
					res = -1;
					break ;
			}
		ft_memdel((void**)&line);
	}
	ft_memdel((void**)&line);
	if (res == -1)
		return (0);
	return (1);
}
