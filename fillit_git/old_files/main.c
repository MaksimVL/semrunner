/* ************************************************************************** */
/*				                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwolf <hwolf@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 11:56:56 by hwolf             #+#    #+#             */
/*   Updated: 2019/09/17 15:22:03 by hwolf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"
#include <stdio.h>


int main()
{
	t_list *fig_str;
	t_list *fig_str_et;
	t_fig  fig[26];

	char *map;
	int map_size;
	int place;
	int fd;
	int size;

	fd = open("test.txt", O_RDONLY);

	fig_str = read_figs_str(fd);
	fig_str_et = read_figs_str(open("map_etalon.txt",O_RDONLY));
	ft_lstiter(fig_str,&lst_print);
	size = read_figs(fig, fig_str);

	printf("figure count: %d\n",size);
	printf("corrt data: %d\n",check_figs_list(fig_str, fig_str_et));

/*	place = 14;
	map_size = 10;
	map = ft_strnew(120);
	map = ft_strcpy(map,"..........\n..........\n..........\n..........\n..........\n..........\n..........\n..........\n..........\n..........\n\n");


	if (put_posibility(map + place, fig))
		put_fig(map + place, fig);
	else
		printf("OOPS\n");
	if (put_posibility(map + place*4, fig2))
		put_fig(map + place*4, fig2);
	else
		printf("OOPS\n");
	printf("\n%s",map);

   */close(fd);

 /*  t_test test[1];

	test[0].value = "123";
   printf("\n\n%s",(char*)test[0].value);
   test_func(test);
   printf("\n\n%s",(char*)test[0].value);
	*/return (0);
}
