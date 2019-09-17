/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwolf <hwolf@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 15:12:19 by hwolf             #+#    #+#             */
/*   Updated: 2019/09/17 12:55:14 by hwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_replace(const char *str, int c)
{
	char *ptr;

	ptr = (char*)str;
	while (*ptr != c)
	{
		if (!*ptr)
			return (ptr);
		++ptr;
	}
	*ptr = 0;
	return (ptr + 1);
}

static int		get_new_line(char **line, t_list **ptr)
{
	char *tmp;

	if (*(char*)((*ptr)->content))
	{
		tmp = ft_replace((*ptr)->content, '\n');
		*line = ft_strdup((*ptr)->content);
		tmp = ft_strdup(tmp);
		free((*ptr)->content);
		(*ptr)->content = tmp;
		return (1);
	}
	free((*ptr));
	(*ptr) = NULL;
	*line = NULL;
	return (0);
}

int		get_next_line(const int fd, char **line)
{
	char			buf[BUFF_SIZE + 1];
	int				ret;
	static	t_list	*ptr[MAX_FD];
	char			*tmp;

	if (fd < 0 || line == NULL || read(fd, buf, 0) < 0)
		return (-1);
	if (!ptr[fd])
		ptr[fd] = ft_lstnew("", 1);
	while ((ret = read(fd, buf, BUFF_SIZE)))
	{
		buf[ret] = 0;
		tmp = ft_strjoin(ptr[fd]->content, buf);
		free(ptr[fd]->content);
		ptr[fd]->content = tmp;
		if (ft_strchr(ptr[fd]->content, '\n'))
			break ;
	}
	return (get_new_line(line, &ptr[fd]));
}
