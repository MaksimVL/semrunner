/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odrinkwa <odrinkwa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 20:47:29 by odrinkwa          #+#    #+#             */
/*   Updated: 2019/09/09 20:47:37 by odrinkwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_memrealloc(void **prt, size_t oldsize, size_t newsize)
{
	void	*ptr;

	if (!(ptr = (void*)malloc(size)))
		return (NULL);
	ft_memset(ptr, 0, size);
	return (ptr);
}
