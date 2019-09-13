/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odrinkwa <odrinkwa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 15:07:12 by odrinkwa          #+#    #+#             */
/*   Updated: 2019/09/13 18:58:06 by odrinkwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <ctype.h>
#include "libft.h"

void	fill_str(char *str, int len, char start_char)
{
	for (int i = 0; i < len; i++)
	{
		*str = start_char + i;
		str++;
	}
	*str = '\0';
}

void	del(void *list, size_t n)
{
	return ;
}


int        ft_atoi1(const char *str)
{
	int                i;
	int                sign;
	char            *str1;
	long long int    nbr;
	i = 0;
	nbr = 0;
	sign = 1;
	str1 = (char*)str;
	while (str1[i] == 32 || (str1[i] > 8 && str1[i] <= 13))
		i++;
	if (str1[i] == '-' || str1[i] == '+')
	if (str1[i++] == '-')
	sign = -1;
	while (str1[i] >= 48 && str1[i] <= 57)
	{
		nbr = nbr * 10 + str1[i] - 48;
		if (nbr < 0)
			return ((sign < 0) ? 0 : -1);
		if (nbr != nbr + (*str - '0') - (*str - '0'))
		return ((sign < 0) ? 0 : -1);
		i++;
	}
	return (sign * nbr);
}

int main()
{
	char s[11];
	char s1[11];
	char *aa;
	fill_str(s, 10, 'a');
	fill_str(s1, 10, 'k');

	printf("%s\n", s);
	ft_memset(s, 35, 0);
	ft_memset(s, 35, 2);
	printf("%s\n", s);

	ft_bzero(s, 3);
	printf("%s\n", s);
	ft_memcpy(s, s1, 6);
	printf("res memcpy: %s\n", s);

	fill_str(s, 10, 'a');
	aa = ft_memccpy(s, s1, 'n', 7);
	printf("%s\n", s);
	printf("%s\n", aa);

	printf("%d\n", ft_strlen(s));

    fill_str(s, 10, 'a');
    fill_str(s1, 10, 'k');
    ft_strcpy(s, s1);
    printf("%s\n", s);
    int c = 512;
    printf("%d\n", (char)c);

	const char *largestring = "Foo Bar Baz";
	const char *smallstring = "Fort";
	char *ptr;

	printf("memcmp %d\n", memcmp(largestring, smallstring, 3));
	printf("ft_memcmp %d\n", ft_memcmp(largestring, smallstring, 3));

	ptr = ft_strstr(largestring, smallstring);
	printf("%s\n", ptr);

	const char *num_atoi = "";
	printf("   atoi: %d\n", atoi(num_atoi));
	printf("ft_atoi: %d\n", ft_atoi(num_atoi));
	c = 97;
	printf("c=%d %c, toupper=%d %c\n", c, c, ft_toupper(c), ft_toupper(c));

	int i;

	i = -1;
	while (i < 530)
	{
		if (!!ft_isalnum(i) != !!isalnum(i))
			printf("fuck! %d\n", i);
		i++;
	}
	i = 0;


	printf("check ft_strcmp\n");
	char *str1 = "test1";
	char *str2 = "test1";
	printf("%d\n", ft_strcmp(str1, str2));

	int test_if;
	test_if = 0;
	if (test_if++)
		printf("fuck\n");

	printf("%d", test_if);

	fill_str(s, 10, 'a');
	fill_str(s1, 10, 'k');
	ft_strcpy(s, s1);
	printf("res of ft_strcpy s=%s\n", s);

	fill_str(s, 5, 'a');
	s[5] = '\0';
	s1[3] = '\0';


	char *src = "the cake is a lie !\0I'm hidden lol\r\n";
	char buff[0xF0];

	char *ret = ft_memmove(buff, src, 100);
	printf("ret = %s", ret);

	if (ret == ((void *)0))
	{
		printf("fail\n");
	}
	else
		printf("success\n");


	char *aaa = NULL;
	char *bbb = NULL;
	printf("\nNULL == NULL ? : %d\n", (aaa == bbb));


	char *s111 = "   \t  \n\n \t\t  \n\n\nHello \t  Please\n Trim me !\n   \n \n \t\t\n  ";
	char *ret1 = ft_strtrim(s111);
	printf("ret=\"%s\"\n", ret1);
	printf("ft_strnequ = %d\n", ft_strnequ("abcde", "abdfe", 2));
	printf("ft_strnequ = %d\n", ft_strnequ("abcde", "abdde", 5));

	char		*str_test = "Hello les genw";
	printf("strnstr = %d\n", strnstr(str_test, "Hello", 3));
	printf("ft_strnstr = %d\n", ft_strnstr(str_test, "Hello", 3));

	char	strstr[] = "abcd";
	t_list	*list_tmp;
	t_list	*list;

	list = ft_lstnew(&strstr[0], sizeof(char));
	list_tmp = ft_lstnew(&strstr[1], sizeof(char));
	ft_lstadd(&list, list_tmp);
	printf("%c\n", *(char*)(list->content));
	printf("%c\n", *(char*)(list->next->content));
	list_tmp = ft_lstnew(&strstr[2], sizeof(char));
	ft_lstaddback(list, list_tmp);
	printf("%c\n", *(char*)(list->next->next->content));
	printf("len list = %d\n", ft_lstlen(list));
	printf("2nd el: %c\n", *(char*)((ft_lsti(list, 1))->content));
	ft_lstdeli(&list, 1, del);
	printf("0 el: %c\n", *(char*)((ft_lsti(list, 0))->content));
	printf("1 el: %c\n", *(char*)((ft_lsti(list, 1))->content));
	ft_lstdeli(&list, 1, del);
	printf("len list = %d\n", ft_lstlen(list));
	ft_lstdel(&list, del);

	char 	*str_testsplit = "aaa bbb cccc";
	char 	**tabstr;
	tabstr = ft_strsplit(str_testsplit, ' ');
	ft_printstrsplit(tabstr);

	char test_strtrim[] = "Hello  ";
	printf("res strtrim: \"%s\"\n", ft_strtrim(test_strtrim));


	char test_atoi[] = "777777777777777888888888885265222222";
	printf("diff = %d atoi = %d, ft_atoi = %d\n", atoi(test_atoi) - ft_atoi1(test_atoi), atoi(test_atoi), ft_atoi1((test_atoi)