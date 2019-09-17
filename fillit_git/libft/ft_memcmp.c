/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwolf <hwolf@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 14:28:55 by hwolf             #+#    #+#             */
/*   Updated: 2019/09/05 19:22:57 by hwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *ptr1, const void *ptr2, size_t n)
{
	unsigned char *tptr1;
	unsigned char *tptr2;

	tptr1 = (unsigned char*)ptr1;
	tptr2 = (unsigned char*)ptr2;
	while (n--)
		if (*(unsigned char*)tptr1 - *(unsigned char*)tptr2)
			return (*(unsigned char*)tptr1 - *(unsigned char*)tptr2);
		else
		{
			++tptr1;
			++tptr2;
		}
	return (0);
}
