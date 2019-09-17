/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwolf <hwolf@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 19:43:11 by hwolf             #+#    #+#             */
/*   Updated: 2019/09/06 17:24:17 by hwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char *ptr1;
	unsigned char *ptr2;

	if (n > 0)
	{
		ptr1 = (unsigned char*)s1;
		ptr2 = (unsigned char*)s2;
		while (*ptr1 == *ptr2 && --n && *ptr1 && *ptr2)
		{
			++ptr1;
			++ptr2;
		}
		return (*ptr1 - *ptr2);
	}
	return (0);
}
