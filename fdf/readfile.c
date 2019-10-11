#include "./mlx/mlx.h"
#include "./libft/includes/libft.h"
#include "./includes/fdf.h"

static char		*nextnum(char *str)
{
	while ((*str == '-' || ft_isdigit(*str)) && *str != '\0')
		str++;
	while (*str != '-' && ! (ft_isdigit(*str)) && *str != '\0')
		str++;
	return str;
}

static int		check_fdf_line(char *line)
{
	int		count_nums;
	char	*pos;

	pos = line;
	if (*line == ' ')
		return (-1);
	while(*line != '\0')
	{
		if (!((ft_isdigit(*line) || *line == ' ' || *line =='-')))
			return (-1);
		line++;
	}
	line = pos;
	count_nums = 0;
	while(*line != '\0')
	{
		line = nextnum(line);
		count_nums++;

	}
	return (count_nums);
}

int				check_file(t_mlx *m, int fd)
{
	char	*line;
	int		count_lines = 0;
	int		size_line = 0;
	int		tmp_check_line = 0;
	int		res;

	while((res = get_next_line(fd, &line)) == 1)
	{
		if ((tmp_check_line = check_fdf_line(line)) < 0)
				return (-1);
		else
			size_line = size_line > (tmp_check_line) ? size_line : tmp_check_line;
		count_lines++;
		ft_memdel((void**)&line);
	}
	if (res == -1)
		return (-1);
	m->map_x = size_line;
	m->map_y = count_lines;
	return (1);
}

int				put_map(t_mlx *m, int fd)
{
	char	*line;
	char	*pos;
	int		res;
	int		i;
	int		j;

	i = 0;
	while((res = get_next_line(fd, &line)) == 1)
	{
		j = 0;
		pos = line;
		while (j < m->map_x && *pos != '\0')
		{
			m->map[i * m->map_x + j] = ft_atoi(pos);
			pos = nextnum(pos);
			j++;
		}
		ft_memdel((void**)&line);
		i++;
	}
	if (res == -1)
		return (-1);
	return (1);

}
