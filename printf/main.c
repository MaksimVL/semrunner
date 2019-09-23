/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odrinkwa <odrinkwa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 22:42:55 by semenbeguno       #+#    #+#             */
/*   Updated: 2019/09/23 10:18:20 by semenbegunov     ###   ########.fr       */
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

int     main(void)
{
	float aa;
	double bb;
	char *s;
	unsigned long long int ulli;
	long long int lli;

	s = (char*)malloc(sizeof(char));
	ulli = (long long int)s;

	aa = 10.0 / 3.0;
	bb = 10.0 / 3.0;
	printf("%p\n", s);
	printf("0x%llx\n", ulli);

	lli = 100;
	ulli = lli;
	printf("100: %lld, %llu\n", lli, ulli);

	lli = -9223372036854775808;
	ulli = -lli;
	printf("-9223372036854775808: %lld, %llu\n", lli, ulli);

	double dd;
	int		itmp;
	int 	fract;

	dd = 13.0201;

	dd -= (int)dd;
	double dd1;

	for (long long int i = 1; i < 15; i++)
	{
		dd = dd * 10;

	}

	dd += 0.5;
	printf("dd = %d\n", (long long int)dd);



	printf("aaaa %f bbbb\n", dd);

	int i1 = 1, i2 = 2, i3 = 3;

	printf("%2$d %1$d %3$d", i1, i2, i3);
}
