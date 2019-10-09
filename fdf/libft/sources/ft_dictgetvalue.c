/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dictgetoraddvalue.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odrinkwa <odrinkwa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 18:18:43 by odrinkwa          #+#    #+#             */
/*   Updated: 2019/10/09 18:14:31 by odrinkwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_dict	*ft_dictgetvalue(t_dict *dict, int key)
{
	t_dict	*counter;

	counter = dict;
	while (counter)
	{
		if ((counter)->key == key)
			return (counter);
		else
			counter = (counter)->next;
	}
	return (NULL);
}
