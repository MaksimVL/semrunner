/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_push_swap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odrinkwa <odrinkwa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 18:48:15 by odrinkwa          #+#    #+#             */
/*   Updated: 2019/11/02 16:13:54 by odrinkwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "libft.h"
#include "push_swap.h"

int				print_usage(void)
{
	ft_printf("usage: push_swap [stack elements | -ffilename | -v -vm]\n");
	ft_printf("  stack elements:  integer numbers\n");
	ft_printf("    -f[filename]:  name of file with stack elements\n");
	ft_printf("              -v:  debug mode\n");
	ft_printf("             -vm:  terminal multiplication mode\n");
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
		return (print_usage());
	str_numbers = NULL;
	prog = NULL;
	stack_initialize(&a);
	stack_initialize(&b);
	a.flag_checker = 0;
	i = 1;
	while (i < argc)
	{
		if (read_arguments(&a, &prog, argv[i], &str_numbers) == 0)
			return (error_clear_vars(&a, &b, &str_numbers, &prog));
		i++;
	}
	//print_stacks(&a, &b);
	if (check(&a) == 0)
		return (error_clear_vars(&a, &b, &str_numbers, &prog));
	sort(&a, &b);
	return (normal_clear_vars(&a, &b, &str_numbers, &prog));
}
