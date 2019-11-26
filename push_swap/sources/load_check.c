/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odrinkwa <odrinkwa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/26 14:36:29 by odrinkwa          #+#    #+#             */
/*   Updated: 2019/10/26 14:37:04 by odrinkwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

int				load_stack(t_stack *a, char *line_stack, char ***str_numbers)
{
	int j;

	if (!((*str_numbers) = ft_strsplit(line_stack, ' ')))
		return (0);
	j = 0;
	while ((*str_numbers)[j] != 0)
	{
		if (ft_isint((*str_numbers)[j]) == 0)
			return (0);
		if (!(stack_push(a, ft_atoi((*str_numbers)[j]))))
			return (0);
		j++;
	}
	ft_del_strsplit(str_numbers);
	return (1);
}

int				read_arguments(t_stack *a, t_dlist **prog,
							char *arg_str, char ***str_numbers)
{
	if (ft_strlen(arg_str) > 2 && (arg_str[0] == '-' && arg_str[1] == 'f'))
	{
		if (read_stack_from_file(&(arg_str[2]), a, str_numbers) == 0)
			return (0);
	}
	else if (a->flag_checker == 1 && ft_strlen(arg_str) > 2 &&
				(arg_str[0] == '-' && arg_str[1] == 'p'))
	{
		if (read_prog_from_file(&(arg_str[2]), prog) == 0)
			return (0);
	}
	else if (ft_strequ(arg_str, "-v"))
		a->flag = 1;
	else if (ft_strequ(arg_str, "-vm"))
		a->flag = 2;
	else if (load_stack(a, arg_str, str_numbers) == 0)
		return (0);
	//print_stacks(a, a);
	return (1);
}
