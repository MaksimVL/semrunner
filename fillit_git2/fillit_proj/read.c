/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odrinkwa <odrinkwa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 12:48:22 by hwolf             #+#    #+#             */
/*   Updated: 2019/09/19 00:43:44 by odrinkwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		get_fig_s(char *str, int i, t_fig *fig, int size)
{
	if (!check_sym(str))
		return (1);
	get_fig('A' + i / 5, str, &(fig[size]));
	if (!analis(fig[size]))
		return (1);
	*str = 0;
	return (0);
}

int		exit_f(int ret, char **line, char **str)
{
	ft_memdel((void**)str);
	if (line)
		ft_memdel((void**)line);
	return (ret);
}

int		initialize_vars(int *i, int *size, char **line, char **str)
{
	*i = 0;
	*size = 0;
	*line = NULL;
	*str = ft_strnew(21);
	if (*str == NULL)
		return (0);
	return (1);
}

int		read_figs(const int fd, t_fig *fig)
{
	char	*line;
	char	*str;
	int		i;
	int		size;

	if (initialize_vars(&i, &size, &line, &str) == 0)
		return (0);
	while (get_next_line(fd, &line) == 1)
	{
		if (!((ft_strlen(line) == 4 && i % 5 != 4)\
		|| (i % 5 == 4 && ft_strlen(line) == 0)) || size > 25)
			return (exit_f(0, &line, &str));
		str = ft_strcat(str, line);
		if (i % 5 == 3)
		{
			if (get_fig_s(str, i, fig, size))
				return (exit_f(0, &line, &str));
			size++;
		}
		i++;
		ft_memdel((void**)&line);
	}
	if (i % 5 != 4)
		return (exit_f(0, &line, &str));
	return (exit_f(size, &line, &str));
}
