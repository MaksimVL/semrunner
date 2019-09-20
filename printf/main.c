/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odrinkwa <odrinkwa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 22:42:55 by semenbeguno       #+#    #+#             */
/*   Updated: 2019/09/20 23:42:05 by odrinkwa         ###   ########.fr       */
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

void 	test_static(void)
{
	static char *static_c;

	printf("p=%p\n", static_c);
}

int     main(void)
{
	float aa;
	double bb;

	aa = 10.0 / 3.0;
	bb = 10.0 / 3.0;
	printf("float aa=%.50f, double bb=%50f, 10.0/3.0=%.50f\n", aa, bb, 10.0 / 3.0);
	printf("%btest\n", 10);
}
