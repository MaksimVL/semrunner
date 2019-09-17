/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwolf <hwolf@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 12:56:40 by hwolf             #+#    #+#             */
/*   Updated: 2019/09/05 20:18:29 by hwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char *dst_ptr;
	unsigned char *src_ptr;

	dst_ptr = (unsigned char*)dst;
	src_ptr = (unsigned char*)src;
	if ((dst_ptr == src_ptr) || !n)
		return (dst);
	while (n--)
		*(dst_ptr++) = *(src_ptr++);
	return (dst);
}
