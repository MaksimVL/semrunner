/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odrinkwa <odrinkwa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 22:34:48 by hwolf             #+#    #+#             */
/*   Updated: 2019/09/18 23:06:14 by odrinkwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ptr;
	int		len;

	if (s1 && s2)
	{
		len = ft_strlen(s2) + ft_strlen(s1);
		if (!(ptr = (char*)malloc((1 + len) * sizeof(*s1))))
			return (NULL);
		ft_strcpy(ptr, s1);
		ft_strcat(ptr, s2);
		return (ptr);
	}
	return (NULL);
}
