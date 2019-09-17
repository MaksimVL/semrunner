/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odrinkwa <odrinkwa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 21:51:44 by odrinkwa          #+#    #+#             */
/*   Updated: 2019/09/17 22:21:37 by odrinkwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "slv_tetr.h"

int main()
{
	t_list *fig_str;
	t_list *fig_str_et;
	t_fig  figs[26];

	int fd;
	int size;

	fd = open("test.txt", O_RDONLY);

	fig_str = read_figs_str(fd);
	fig_str_et = read_figs_str(open("map_etalon.txt",O_RDONLY));
	ft_lstiter(fig_str,&lst_print);
	size = read_figs(figs, fig_str);

	ft_putstr("figure count: ");
	ft_putnbr(size);
	ft_putchar('\n');

	ft_putstr("corrt data: ");
	ft_putnbr(check_figs_list(fig_str, fig_str_et));
	ft_putchar('\n');

	solve_tetrimino(figs, size);
	return (0);
}