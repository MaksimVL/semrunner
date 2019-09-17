/* ************************************************************************** */
/*	                                                                        */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwolf <hwolf@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 11:55:51 by hwolf             #+#    #+#             */
/*   Updated: 2019/09/17 14:51:06 by hwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"
#include <stdio.h>

char *code_fig(char *src, int map_size)
{
	char *fig;
	int i;
	char tmp;

	fig = ft_strnew(5);
	*fig = *src++;
	i = 1;
	while(*src)
	{
		tmp  = *src++ - '0';
		tmp += (*src++ - '0') * (map_size + 1);
		fig[i++] = tmp;
	}
	return (fig);
}

void  put_fig(char *map, char *fig)
{
	char label;

	label = *fig++;
	*map = label;
	while (*fig)
		*(map + *fig++) = label;

}
int put_posibility(char *map, char *fig)
{
	fig++;
	while (*fig)
		if (*(map + *(fig++)) != '.')
			return (0);
	return (1);
}

void rm_label(char *map, char ch)
{
	while (*map)
	{
		if (*map == ch)
			*map = '.';
		map++;
	}
}

