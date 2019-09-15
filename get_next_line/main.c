/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odrinkwa <odrinkwa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 22:42:55 by semenbeguno       #+#    #+#             */
/*   Updated: 2019/09/15 18:00:35 by odrinkwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <stdlib.h>
#include "./libft/includes/libft.h"
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

int				main(void)
{
	char 	*line;
	int		out;
	int		p[2];
	char 	*str;
	int		len = 50;

	str = (char *)malloc(1000 * 1000);
	*str = '\0';
	while (len--)
		strcat(str, "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Curabitur in leo dignissim, gravida leo id, imperdiet urna. Aliquam magna nunc, maximus quis eleifend et, scelerisque non dolor. Suspendisse augue augue, tempus");
	out = dup(1);
	pipe(p);
	dup2(p[1], 1);

	if (str)
		write(1, str, strlen(str));
	close(p[1]);
	dup2(out, 1);
	get_next_line(p[0], &line);
	printf("%s\n", line);
	printf("%s\n", str);
	printf("%zu\n", ft_strlen(str));
	printf("%zu\n", ft_strlen(line));
	printf("%d\n", strcmp(line, str));
	printf("%d\n", strcmp(line, str) == 0);

	//	char		*line;
//	int			fd;
//	int			ret;
//	int			count_lines;
//	char		*filename;
//	int			errors;
//
//	filename = "gnl1_2.txt";
//	fd = open(filename, O_RDONLY);
//	if (fd > 2)
//	{
//		line = NULL;
//		while ((ret =  get_next_line(fd, &line)) > 0)
//			printf("%s\n", line);
//	}
//	return (0);
}