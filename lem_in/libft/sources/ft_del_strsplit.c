/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_del_strsplit.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odrinkwa <odrinkwa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/26 14:53:09 by odrinkwa          #+#    #+#             */
/*   Updated: 2019/11/16 17:34:04 by odrinkwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			ft_del_strsplit(char ***strings)
{
	int		i;

	if (strings == NULL || *strings == NULL)
		return ;
	i = 0;
	while ((*strings)[i] != 0)
	{
		ft_memdel((void**)&((*strings)[i]));
		i++;
	}
	ft_memdel((void**)&((*strings)[i]));
	free(*strings);
	*strings = NULL;
}
