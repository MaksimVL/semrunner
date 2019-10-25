#include <fcntl.h>
#include "libft.h"
#include "push_swap.h"

int				read_stack_from_file(char *filename, t_stack *a,
						char ***str_numbers)
{
	int		fd;
	int		res;
	char	*line;

	line = NULL;
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (0);
	while ((res = get_next_line(fd, &line)) == 1)
	{
		if (load_stack(a, line, str_numbers) == 0)
			return (0);
		ft_memdel((void**)&line);
	}
	close(fd);
	ft_memdel((void**)&line);
	if (res == -1)
		return (0);
	return (1);
}

int				read_prog_from_file(char *filename, t_dlist **prog)
{
	int		fd;
	int		res;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (0);
	res = load_program(prog, fd);
	close(fd);
	if (res == 0)
		return (0);
	return (1);
}
