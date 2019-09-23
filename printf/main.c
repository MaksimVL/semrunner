/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odrinkwa <odrinkwa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 22:42:55 by semenbeguno       #+#    #+#             */
/*   Updated: 2019/09/23 22:30:11 by odrinkwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <stdlib.h>
#include "libft.h"
#include "ft_printf.h"

void 	test_static(void)
{
	static char *static_c;

	printf("p=%p\n", static_c);
}


int		len_num_box(unsigned long long num, int shift)
{
	int 	count;

	count = 0;
	while(num > 0)
	{
		num = (num >> shift);
		count++;
	}
	return (count);
}

int		ft_itoa_box(unsigned long long num, char box, int fd)
{
	char *base_chars;
	int shift;
	int mask;
	int start_point;

	base_chars = (box == 'x') ? "0123456789abcdef" : "0123456789ABCDEF";
	if (box == 'b')
	{
		mask = 1;
		shift = 1;
	}
	else if (box == 'o')
	{
		mask = 7;
		shift = 3;
	}
	else
	{
		mask = 15;
		shift = 4;
	}
	if (!(start_point = len_num_box(num, shift)))
		return (0);

	while(start_point-- > 0)
	{
		ft_putchar_fd(base_chars[(num >> (start_point * shift)) & mask], fd);
	}
}


int     main(void)
{
	float aa;
	double bb;
	char *s;
	unsigned long long int ulli;
	long long int lli;
	unsigned long long int ulli_test;

	s = (char*)malloc(sizeof(char));
	printf("pointer s = %p\n", s);
	ulli = (unsigned long long int)s;
	printf("ulli = %llx\n", ulli);

	ulli_test = ulli;

	int size_ulli;

	size_ulli = sizeof(s) * 8;
	printf("size_ulli = %d\n", size_ulli);

	unsigned long long int mask;

	mask = 0xf;
	int i = 0;
	while(ulli_test > 0)
	{
		ulli_test = ulli_test >> 4;
		i += 4;
	}

	int count_nums = i;
	printf("i = %d\n", i);

	ulli_test = ulli;
	printf("ulli_test:");

	while (i > 0)
	{
		i-=4;
		printf("%llx", ulli_test >> i & 0xF);
	}

	printf("\nulli_test_bin:");
	i = count_nums;
	int j;
	while(i > 0)
	{
		i -= 4;
		j = 4;
		while(j > 0)
		{
			printf("%d", ulli_test >> (i + j-1) & 1);
			j--;
		}
	}

	printf("\n------------------\n");
	printf("%04x\n", 0x3af);

	printf("sizeof(float) = %lu\n", sizeof(float));
	printf("sizeof(double) = %lu\n", sizeof(double));
	printf("sizeof(long double) = %lu\n", sizeof(long double));

	printf("sizeof(int) = %lu\n", sizeof(unsigned long long int));

	ulli = 18446744073709551615;
	ft_itoa_box(ulli, 'X', 1);
	printf("\n");
	ft_itoa_box((unsigned long long)s, 'x', 1);
	printf("\n");
	ft_itoa_box((unsigned long long)s, 'b', 1);
}
