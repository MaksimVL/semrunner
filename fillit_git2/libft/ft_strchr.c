/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwolf <hwolf@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 18:15:48 by hwolf             #+#    #+#             */
/*   Updated: 2019/09/05 19:00:13 by hwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	char *ptr;

	ptr = (char*)str;
	while (*ptr != c)
	{
		if (!*ptr)
			return (NULL);
		++ptr;
	}
	return (ptr);
}
