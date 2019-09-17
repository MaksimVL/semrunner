/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwolf <hwolf@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 11:22:55 by hwolf             #+#    #+#             */
/*   Updated: 2019/09/07 19:10:03 by hwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *dst, int c, size_t n)
{
	unsigned char *ptr;

	ptr = (unsigned char*)dst;
	if (n > 0)
		while (n--)
			*(ptr++) = (unsigned char)c;
	return (dst);
}
