#ifndef TERMINAL_DRAW_H
# define TERMINAL_DRAW_H

# include "libft.h"

# define HOME() ft_printf("\033[H")
# define CLRSCR() ft_printf("\033[2J")
# define SETCOLOR(color) ft_printf("\033[%dm", color)
# define GOTOXY(x,y) ft_printf("\033[%d;%dH", y, x)
# define GOTOINLINE(x) ft_printf("\033[%d`", x)
# define RESET_COLOR() ft_printf("\033[0m")

# define F_RED 31
# define F_GREEN 32
# define F_CYAN 36

#endif
