/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwolf <hwolf@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 12:48:22 by hwolf             #+#    #+#             */
/*   Updated: 2019/09/17 20:35:14 by hwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

#include <stdio.h>

void lst_print(t_list *ptr)
{

	printf("%c %3d%2d  %4d%2d  %4d%2d\n",((char*)ptr->content)[0],((char*)ptr->content)[1],((char*)ptr->content)[2],((char*)ptr->content)[3],((char*)ptr->content)[4],((char*)ptr->content)[5],((char*)ptr->content)[6]);
}

t_list *read_figs_str(const int fd)
{
	char *line;
	char *str;
	int i;
	t_list *fig;
	int gnl;
	int count;
	count = 4;
	str = ft_strnew(21);
	fig = NULL;
	i = 0;
	while ((gnl = get_next_line(fd, &line)))
	{
	if (gnl == -1 || (ft_strlen(line) != 4 && ft_strlen(line) != 0 )|| (count != 4))
			{
				ft_lst_del(&fig);
				free(str);
				str = NULL;
				return (NULL);
			}
		str = ft_strcat(str,line);
		i++;
		if (i % 5 == 4)
		{
			fig = ft_lstappend(fig, ft_lstnew(get_fig('A' + i / 5,str,count),8));
			//lst_print(&fig);
			*str = 0;
		}
	}
	free(str);
	str = NULL;
	return (fig);
}


int check_fig_list(t_list *src, t_list *etalon)
{

	while(etalon)
	{
		if (!ft_memcmp(src->content+1, etalon->content + 1, 7))
			return (1);
		etalon = etalon->next;
	}
	return (0);
}

int check_figs_list(t_list *src, t_list *etalon)
{
	while(src)
	{
		if (!check_fig_list(src, etalon))
			return (0);
		src = src->next;
	}
	return (1);
}

int read_figs(t_fig *dist, t_list *fig_str)
{
	int i;

	i = 0;
	while (fig_str)
	{
		dist[i].label = *(char*)fig_str->content;
		dist[i].is_set = 0;
		dist[i].row[0] = (int)(((char*)fig_str->content)[2]);
		dist[i].col[0] =(int)(((char*)fig_str->content)[1]);
		dist[i].row[1] = (int)(((char*)fig_str->content)[4]);
		dist[i].col[1] =(int)(((char*)fig_str->content)[3]);
		dist[i].row[2] = (int)(((char*)fig_str->content)[6]);
		dist[i].col[2] =(int)(((char*)fig_str->content)[5]);
		i++;
		fig_str = fig_str->next;
	}
	return (i);
}

void print_tab(t_fig *tab, int count)
{
	while (count--)
	{
		printf("%c %3d %3d%2d  %4d%2d  %4d%2d\n",tab[count].label, tab[count].is_set, tab[count].row[0], tab[count].col[0], tab[count].row[1], tab[count].col[1], tab[count].row[2], tab[count].col[2]);
	}

}

char *get_fig(int label, char *line, int count)
{
	char *str;
	int tmp;
	int i;
	int j;
	int point;

	j = 1;
	i = 0;
	tmp = 0;
	str = ft_strnew(8);
	*str = label;
	count = 0;
	while (line[i])
	{
		if (line[i] ==  '#')
		{
			count ++;
			if(tmp)
			{
				str[j++] = i % 4 - tmp % 4;
				str[j++] = i / 4 - tmp / 4;
			}
			else
				tmp = i;
		}
		i++;
	}
	return (str);

}
