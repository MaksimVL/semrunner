/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odrinkwa <odrinkwa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 22:54:55 by odrinkwa          #+#    #+#             */
/*   Updated: 2019/09/13 23:42:27 by odrinkwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "get_next_line.h"

static int	crash_f(char **str, char **line, char **buff)
{
	ft_memdel((void**)str);
	ft_memdel((void**)line);
	ft_memdel((void**)buff);
	return (-1);
}

char 	*remake_str(char **str, char *new_point)
{
	char	*ptr;
	if (!(ptr = ft_strdup(new_point + 1)))
		return (NULL);
	ft_memdel((void**)str);
	*str = ptr;
	return (ptr);
}

t_list	*ft_getvaluefromdict(t_list **dict, int key)
{
	t_list	*new;
	t_list	*counter;

	counter = *dict;
	while (counter)
	{
		if ((counter)->content_size == (size_t)key)
			return (counter);
		else
			counter = (counter)->next;
	}
	new = ft_lstnew(NULL, (size_t)key);
	ft_lstadd(dict, new);
	return (*dict);
}


int		get_next_line(const int fd, char **line)
{
	static t_list		*files;
	char				*str;
	char 				*buff;
	int					read_count;
	char 				*chr_n;

	if (!(buff = (char*)malloc(sizeof(char) * BUFF_SIZE)))
		return (-1);
	*line = NULL;
	str = (char*)(ft_getvaluefromdict(&files, fd))->content;
	if (str != NULL)
	{
		if ((chr_n = ft_strnstr(str, "\n", ft_strlen(str))))
		{
			if (!(*line = ft_strnjoin(line, str, (size_t)(chr_n - str))))
				return (crash_f(&str, NULL, NULL));
			if (chr_n == &str[ft_strlen(str) - 1])
				ft_memdel((void**)&str);
			else
				if (!(str = remake_str(&str ,chr_n)))
					return (crash_f(NULL, line, NULL));
			return (1);
		}
		else
		{
			if (!(*line = ft_strnjoin(line, str, ft_strlen(str))))
				return (crash_f(NULL, line, NULL));
			ft_memdel((void**)&str);
		}
	}
	while ((read_count = read(fd, buff, BUFF_SIZE)))
	{
		if ((chr_n = ft_strnstr(buff, "\n", read_count)))
		{

			if (!(*line = ft_strnjoin(line, buff, (int)(chr_n - buff))))
				return (crash_f(&str, line, &buff));
			if (read_count > (size_t)(chr_n - buff))
			if (!(str = ft_strnjoin(&str, chr_n + 1, read_count - (size_t)(chr_n - str + 1))))
			return (1);
		}
		else
			if (!(*line = ft_strnjoin(line, buff, read_count)))
				return (crash_f(&str, line, &buff));
	}
	if (read_count < 0)
		return (crash_f(&str, line, &buff));
	ft_memdel((void**)&buff);
	return (0);
}
