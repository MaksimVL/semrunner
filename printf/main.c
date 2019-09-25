/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odrinkwa <odrinkwa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 22:42:55 by semenbeguno       #+#    #+#             */
/*   Updated: 2019/09/25 17:14:55 by semenbegunov     ###   ########.fr       */
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

#define SIZE_BN 100
#define BASE_BN 10000

typedef struct		s_bignum
{
	long long int	number[100];
	int 			sign;
	int 			size;
}					t_bignum;

void initialize_bignum(t_bignum *n)
{
	int i;

	i = 0;
	while (i < SIZE_BN)
	{
		n->number[i] = 0;
		i++;
	}
	n->sign = 0;
	n->size = 0;
}

void ft_itoa_bignum(t_bignum *bn, long long n)
{
	int i;

	initialize_bignum(bn);
	if (n == 0)
		return ;
	bn->sign = (n < 0) ? -1 : 1;

	i = 0;
	if (n < 0)
	{
		bn->number[i++] = -(n % BASE_BN);
		n = -(n / BASE_BN);
	}
	while (n != 0)
	{
		bn->number[i++] = (int)(n % BASE_BN);
		n = n / BASE_BN;
	}
	bn->size = i;
}

void ft_print_bignum(t_bignum bn)
{
	int i;

	if (bn.sign == -1)
		ft_putchar('-');
	i = bn.size;
	while(i-- > 0)
	{
		ft_printf("%lld", bn.number[i]);
	}
}

void fixzero_bignum(t_bignum *bn)
{
	int i;

	i = 0;
	while (i < SIZE_BN)
	{
		if (bn->number[i] != 0)
			return ;
		i++;
	}
	bn->size = 0;
	bn->sign = 0;
}

void fixsize_bignum(t_bignum *bn)
{
	int i;

	i = SIZE_BN - 1;
	while (i >= 0)
	{
		if (bn->number[i] != 0)
			break ;
		i--;
	}
	bn->size = i + 1;
}

void fixup_bignum(t_bignum *bn)
{
	int i;

	i = 0;
	while(i < SIZE_BN - 1)
	{
		bn->number[i + 1] += bn->number[i] / BASE_BN;
		bn->number[i] = bn->number[i] % BASE_BN;
		i++;
	}
	fixzero_bignum(bn);
}

void ft_sumabs_bignum(t_bignum *res, t_bignum bn1, t_bignum bn2)
{
	int i;

	i = 0;
	initialize_bignum(res);
	while(i < SIZE_BN)
	{
		res->number[i] = bn1.number[i] + bn2.number[i];
		fixup_bignum(res);
		i++;
	}
	fixsize_bignum(res);
	if (res->size > 0)
		res->sign = 1;
}

void ft_mult_bignum(t_bignum *res, t_bignum bn1, t_bignum bn2)
{
	int i;
	int j;

	initialize_bignum(res);
	i = 0;

	while (i < SIZE_BN)
	{
		j = 0;
		while (j < SIZE_BN - i)
		{
			res->number[i + j] += bn1.number[i] * bn2.number[j];
			j++;
		}
		i++;
	}
	res->sign = bn1.sign * bn2.sign;
	fixup_bignum(res);
	fixsize_bignum(res);
}

void ft_assign_bignum(t_bignum *res, t_bignum bn)
{
	int i;

	i = 0;
	while (i < SIZE_BN)
	{
		res->number[i] = bn.number[i];
		i++;
	}
	res->sign = bn.sign;
	res->size = bn.size;
}

void ft_power_bignum(t_bignum *res, t_bignum bn, unsigned int n)
{
	unsigned int i;
	t_bignum tmp_bn;

	ft_assign_bignum(&tmp_bn, bn);
	i = 1;
	while (i < n)
	{
		ft_mult_bignum(res, tmp_bn, bn);
		ft_assign_bignum(&tmp_bn, *res);
		i++;
	}

}

int     main(void)
{
	long long n = 45678787879;
	t_bignum bn1;
	t_bignum bn2;
	t_bignum res;

	ft_itoa_bignum(&bn1, n);
	ft_power_bignum(&res, bn1, 30);

	ft_print_bignum(res);


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
