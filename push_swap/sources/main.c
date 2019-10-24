/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odrinkwa <odrinkwa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 18:48:15 by odrinkwa          #+#    #+#             */
/*   Updated: 2019/10/25 00:46:16 by odrinkwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "libft.h"
#include "push_swap.h"

#include <float.h>

void			clear_vars(t_stack *a, t_stack *b, char *line,
						char **str_numbers)
{
	stack_del(a);
	stack_del(b);
	ft_memdel((void**)&line);
	ft_del_strsplit(str_numbers);

}
int				error_clear_vars(t_stack *a, t_stack *b, char *line,
						char **str_numbers)
{
	clear_vars(a, b, line, str_numbers);
	ft_printf("%wError\n", 2);
	return (-1);
}

int				normal_clear_vars(t_stack *a, t_stack *b, char *line,
						char **str_numbers)
{
	clear_vars(a, b, line, str_numbers);
	return (0);
}

int load_stack(t_stack *a, char *line_stack, char **str_numbers)
{
	int j;

	if (!(str_numbers = ft_strsplit(line_stack, ' ')))
		return (0);
	j = 0;
	while (str_numbers[j] != 0)
	{
		if (ft_isint(str_numbers[j]) == 0)
			return (0);
		if (!(stack_push(a, ft_atoi(str_numbers[j]))))
			return (0);
		j++;
	}
	ft_del_strsplit(str_numbers);
	return (1);
}


int				read_stack_from_file(char *filename, t_stack *a, char *line,
						char **str_numbers)
{
	int		fd;
	int		res;

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

int				main(int argc, char **argv)
{
	t_stack		a;
	t_stack		b;
	char		*line;
	char		**str_numbers;
	int			i;
	// int			j;

	if (argc < 2)
	{
		ft_printf("usage: push_swap [stack elements | -ffilename | -v -vm]\n");
		ft_printf("    -f[filename]:  name of file with stack elements\n");
		ft_printf("              -v:  debug mode\n");
		ft_printf("             -vm:  terminal multiplication mode\n");
		return (0);
	}
	line = NULL;
	str_numbers = NULL;
	stack_initialize(&a);
	stack_initialize(&b);
	if (argc < 2)
		return (error_clear_vars(&a, &b, line, str_numbers));
	i = 1;
	while (i < argc)
	{
		if (ft_strlen(argv[i]) > 2 && (argv[i][0] == '-' && argv[i][1] == 'f'))
		{
			if (read_stack_from_file(&(argv[i][2]), &a, line, str_numbers) == 0)
				return (error_clear_vars(&a, &b, line, str_numbers));
		}
		else if (ft_strequ(argv[i], "-v"))
			a.flag = 1;
		else if (ft_strequ(argv[i], "-vm"))
			a.flag = 2;
		else if (load_stack(&a, argv[i], str_numbers) == 0)
			return (error_clear_vars(&a, &b, line, str_numbers));
		ft_del_strsplit(str_numbers);
		i++;
	}
	if (a.len == 0 || find_repeat_elements(&a) == 1)
		return (error_clear_vars(&a, &b, line, str_numbers));
	a.len_all = a.len;
	if (!(a.array_int = (int*)ft_memalloc(sizeof(int) * a.len_all)))
		return (error_clear_vars(&a, &b, line, str_numbers));
	stack_fill_and_sort_array_int(&a);
	stack_set_max_len_el(&a);
	if (a.flag == 1)
	{
		a.count_operations--;
		write_operation("start condition", &a, &b);
	}
	stack_sort(&a, &b);
	if (a.flag != 0)
		ft_printf("result: count of elements: %d, count of operations: %d\n",
				a.len_all, a.count_operations);
	stack_del(&a);
	stack_del(&b);
	return (normal_clear_vars(&a, &b, line, str_numbers));
}
