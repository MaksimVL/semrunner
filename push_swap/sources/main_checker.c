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

int				print_usage_checker(void)
{
	ft_printf("usage: checker [stack elements | -ffilename | -v -vm]\n");
	ft_printf("  stack elements:  integer numbers\n");
	ft_printf("    -f[filename]:  name of file with stack elements\n");
	ft_printf("              -v:  debug mode\n");
	ft_printf("             -vm:  terminal multiplication mode\n");
	ft_printf("than enter program for sorting into stdin. ");
	ft_printf("Press ctrl + D after finish.\n");
	return (0);
}

int				main(int argc, char **argv)
{
	t_stack		a;
	t_stack		b;
	t_dlist		*prog;
	char		**str_numbers;
	int			i;

	if (argc < 2)
		return (print_usage_checker());
	str_numbers = NULL;
	prog = NULL;
	stack_initialize(&a);
	stack_initialize(&b);
	a.flag_checker = 1;
	i = 1;
	while (i < argc)
	{
		if (read_arguments(&a, &prog, argv[i], &str_numbers) == 0)
			return (error_clear_vars(&a, &b, &str_numbers, &prog));
		i++;
	}
	if (check(&a) == 0)
		return (error_clear_vars(&a, &b, &str_numbers, &prog));
	if (load_program(&prog, 0) == 0)
		return (error_clear_vars(&a, &b, &str_numbers, &prog));
	use_program_to_stack(&a, &b, prog);
	if (check_sort_stack(&a) == 1)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	return (normal_clear_vars(&a, &b, &str_numbers, &prog));
}
