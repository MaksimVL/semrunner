/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odrinkwa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/13 22:40:57 by odrinkwa          #+#    #+#             */
/*   Updated: 2019/10/12 17:07:06 by odrinkwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*str_dup;
	size_t	len_src;

	len_src = ft_strlen(s1);
	if (!(str_dup = (char*)malloc(sizeof(*s1) * (len_src + 1))))
		return (NULL);
	str_dup = ft_strcpy(str_dup, s1);
	return (str_dup);
}
