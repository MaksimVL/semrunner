/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odrinkwa <odrinkwa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 22:42:55 by semenbeguno       #+#    #+#             */
/*   Updated: 2019/09/20 20:10:45 by odrinkwa         ###   ########.fr       */
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

void 	test_static(void)
{
	static char *static_c;

	printf("p=%p\n", static_c);
}

void    printdictcontent(t_dict *dict)
{
    t_dict *dicttest;
    dicttest = dict;
    printf("--- print dict content --- \n");
    while (dicttest)
    {
        printf("%d:%s, ", dicttest->key, dicttest->content);
        dicttest = dicttest->next;
    }
    printf("\n");
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

int     main(void)
{
    char    filename[] = "testtest.txt";
    char    filename2[] = "testtest2.txt";
    int     fd;
    int     fd2;
    int     change_fd;
    char    *line;

    fd = open(filename, O_RDONLY);
    fd2 = open(filename2, O_RDONLY);

    change_fd = fd;
    while (get_next_line(change_fd, &line) == 1)
    {
    	change_fd = change_fd == fd ? fd2 : fd;
        printf("%s\n", line);
        ft_memdel((void**)&line);
    }
    if (line)
        ft_memdel((void**)&line);
    close(fd);
    close(fd2);
}


//int				main(void)
//{
//    t_dict  *dict;
//    t_dict  *dicttest;
//
//    dict = ft_dictnew("test1", 6, 1);
//    ft_dictadd(&dict, ft_dictnew("test2", 6, 2));
//    ft_dictadd(&dict, ft_dictnew("test3", 6, 3));
//    ft_dictadd(&dict, ft_dictnew("test4", 6, 4));
//    ft_dictadd(&dict, ft_dictnew("test5", 6, 5));
//
//    dicttest = ft_dictgetoraddvalue(&dict, 1);
//    while (dicttest)
//    {
//        printf("%s\n", dicttest->content);
//        dicttest = dicttest->next;
//    }
//    printf("---\n");
//
//    dicttest = ft_dictgetoraddvalue(&dict, 2);
//    while (dicttest)
//    {
//        printf("%s\n", dicttest->content);
//        dicttest = dicttest->prev;
//    }
//
//    printf("--- testing del element ---------\n");
//
//    dicttest = ft_dictgetoraddvalue(&dict, 4);
//    ft_dictdelelement(&dict, &dicttest, NULL);
//
//    dicttest = ft_dictgetoraddvalue(&dict, 1);
//    while (dicttest)
//    {
//        printf("%s\n", dicttest->content);
//        dicttest = dicttest->next;
//    }
//    printf("---\n");
//
//    dicttest = ft_dictgetoraddvalue(&dict, 2);
//    while (dicttest)
//    {
//        printf("%s\n", dicttest->content);
//        dicttest = dicttest->prev;
//    }
//
//    dicttest = dict;
//    printf("--- test from start dict --- \n");
//    while (dicttest)
//    {
//        printf("%s\n", dicttest->content);
//        dicttest = dicttest->next;
//    }
//
//    printf("--- test dictgetvalue ---\n");
//    dicttest = ft_dictgetvalue(dict, 2);
//    printf("%s\n", dicttest->content);
//    dicttest = ft_dictgetvalue(dict, 10);
//    if (dicttest)
//        printf("%s\n", dicttest->content);
//
//    printdictcontent(dict);
//    printf(" --- test dictdelbykey ---\n");
//
//    ft_dictdelbykey(&dict, 5, NULL);
//    printdictcontent(dict);
//}