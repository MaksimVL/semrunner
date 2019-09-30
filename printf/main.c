/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odrinkwa <odrinkwa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 22:42:55 by semenbeguno       #+#    #+#             */
/*   Updated: 2019/09/29 14:03:57 by semenbegunov     ###   ########.fr       */
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
#include "double.h"

void 	test_static(void)
{
	static char *static_c;

	printf("p=%p\n", static_c);
}

int     main(void)
{
	long double n;
	int prec;
//	n = 10.99;
//	prec = 21;

	n=11322222112.00000919111;
	n = n * n;
	n = n * n;
	n = n * n;
	prec= 20;
	char test_ld[1500];

	test_ld[0] = '\0';

	prf_dblcalc(n, prec, test_ld);


	printf("%.*Lf\n", prec, n);
	printf("%s\n", test_ld);

	t_bigdec bd;

	initialize_bignum(&(bd.fractpart));
	bd.fractpart.number[0] = 4567;
	bd.fractpart.number[1] = 123;
	bd.fractpart.sign = 1;
	bd.fractpart.size = 2;
	bd.sizefract = 7;
	roundbd(&bd, 2);

	printf("i in fract = %d\n", getiinfract(bd, 0));

/*

	//ft_printf("%Lf\n", n);

	ft_printf("\x1b[31mfuck\n\x1b[0m");

	printf("%11.-3s %11s\n", "test1", "test2");

	printf("%11c %11s\n", 't', "test2");
	int test = 100;
	printf("%## 08x\n", test);
	ft_printf("%d\n", test);*/
	/*
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

	printf("sizeof(int) = %lu\n", sizeof(int));
	printf("sizeof(long int) = %lu\n", sizeof(long int));
	printf("sizeof(long long int) = %lu\n", sizeof(long long int));

	printf("sizeof(short) = %lu\n", sizeof(short));


	printf("%x\n", 1515);
//ft_printf("s = %p %lo %lx %lb\n", s, s, s, s);
	printf("s = %p %lo %lx\n", s, s, s);

	int aaa = 49;
	double bbb = 10.5;
	char ccc = 't';

	printf("\n---------\n");

	printf("%d %f %c\n", aaa, bbb, ccc);
	ft_printf("%llx %c\n", aaa, ccc);

	aaa = -5;
	printf("%d\n", aaa % 2);

	ft_printf("%d test\n", 345);
	long double test_big;

	test_big = 5000234230032400;

	printf("%Le\n", test_big);

	ft_printf("%lld\n", (long long int)(-10038));

	printf("\n------------------\n");

	lli = 1000232323104;
	printf("   printf %d\n", (int)lli);
	ft_printf("ft_printf %d\n", (int)lli);

	short sh;

	sh = -1123200;
	printf("   printf %hhx\n", sh);
	ft_printf("ft_printf %hhx\n", sh);

	long double test_ld;
	union u_double	test_ud;
	test_ld = 100500;

	test_ud.ld = test_ld;

	printf("%Lf\n", test_ud.ld);
	printf("%x %x %lx\n", test_ud.s_parts.s, test_ud.s_parts.e, test_ud.s_parts.m);
	ft_printf("%x %x %lx\n", test_ud.s_parts.s, test_ud.s_parts.e, test_ud.s_parts.m);
	ft_printf("%b %b %lb\n", test_ud.s_parts.s, test_ud.s_parts.e, test_ud.s_parts.m);
	 */
}
