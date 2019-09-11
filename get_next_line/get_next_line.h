
#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include "./libft/libft.h"

# define BUFF_SIZE 16

typedef	struct		s_charbuff
{
	char			*data;
	int				size;
}					t_charbuff;

int					get_next_line(const int fd, char **line);

#endif
