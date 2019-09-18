/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwolf <hwolf@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 19:25:03 by hwolf             #+#    #+#             */
/*   Updated: 2019/09/05 19:21:12 by hwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strcmp(const char *s1, const char *s2)
{
	unsigned char *ptr1;
	unsigned char *ptr2;

	ptr1 = (unsigned char*)s1;
	ptr2 = (unsigned char*)s2;
	while (*ptr2 == *ptr1 && *ptr1 && *ptr2)
	{
		++ptr1;
		++ptr2;
	}
	return (*ptr1 - *ptr2);
}
