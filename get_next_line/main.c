/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: semenbegunov <semenbegunov@student.42.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 22:42:55 by semenbegunov      #+#    #+#             */
/*   Updated: 2019/09/14 10:44:33 by semenbegunov     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <stdlib.h>
#include "./libft/libft.h"
#include "get_next_line.h"

void 	test_static(void)
{
	static char *static_c;

	printf("p=%p\n", static_c);
}


int			file_open(int *fd, char *file_name)
{
	*fd = open(file_name, O_RDWR);
	if (*fd < 0)
	{
		return (0);
	}
	return (1);
}

int			main(int argc, char **argv)
{
	int		fd1, fd2;
	int		i;
	char 	*filename1 = "testfile";
	char	*filename2 = "testfile2";
	char 	*line;

	file_open(&fd1, filename1);
	file_open(&fd2, filename2);

	get_next_line(fd1, &line);
	printf("%s\n", line);
	free(line);

	get_next_line(fd2, &line);
	printf("%s\n", line);
	free(line);

	get_next_line(fd1, &line);
	printf("%s\n", line);
	free(line);

	get_next_line(fd2, &line);
	printf("%s\n", line);
	free(line);

	//testing t_list

	printf("---- test list ----\n");
	t_list	*list;
	char	*s1;
	char	**s2;

	s1 = (char*)malloc(sizeof(char)*3);
	s1[0] = 'a'; s1[1] = 'b'; s1[2] = '\0';
	list = ft_lstnew(s1, 3);
	s2 = (char**)(&(list->content));

	printf("%s\n", *s2);
	printf("%s\n", list->content);

	*s2 = (char*)malloc(sizeof(char) * 3);;
	(*s2)[0] = 'c'; (*s2)[1] = 'd'; (*s2)[2] = '\0';
	printf("s2 = %s\n", *s2);
	printf("list->cont = %s\n", list->content);
}