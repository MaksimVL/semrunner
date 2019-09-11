#include "get_next_line.h"

int 	crash_f(char **str, char **buff)
{
	if (*str)
		free(*str);
	*str = NULL;
	if (*buff)
		free(*buff);
	*buff = NULL;
	return (-1);
}

int		get_next_line(const int fd, char **line)
{
	static	t_charbuff	*str;
	char 				*buff;
	int					read_count;
	char 				*chr_n;

	if (str)

	if (!(buff = (char*)malloc(sizeof(char) * BUFF_SIZE)))
		return (crash_f(&str, &buff));
	while ((read_count = read(fd, buff, BUFF_SIZE)))
	{
		if ((chr_n = ft_strnstr(buff, "\n", read_count)))
			*line = (char*)ft_rememalloc(sizeof(char) * ft_min());


	}
	if (read_count < 0)
		return (crash_f(&str, &buff));



	return 0;
}