#include "libft.h"

int			ft_intlen(int a)
{
	char	*s;
	int		tmp;

	s = ft_itoa(a);
	tmp = ft_strlen(s);
	ft_memdel((void**)&s);
	return (tmp);
}


int			find_max_len_int(int **matrix, int num_of_lines, int num_of_cols)
{
	int		i;
	int		j;
	int		len_tmp;
	int		max_len;

	max_len = 0;
	i = 0;
	while (i < num_of_lines)
	{
		j = 0;
		while (j < num_of_cols)
		{
			len_tmp = ft_intlen(matrix[i][j]);
			max_len = max_len > len_tmp ? max_len : len_tmp;
			j++;
		}
		i++;
	}
	return (max_len);
}

void		print_intmatrix(int **matrix, int num_of_lines, int num_of_cols)
{
	int		i;
	int		j;
	int		max_len;

	max_len = find_max_len_int(matrix, num_of_lines, num_of_cols);
	i = 0;
	while (i < num_of_lines)
	{
		j = 0;
		while (j < num_of_cols)
		{
			ft_printf("%*d", max_len + 2, matrix[i][j]);
			j++;
		}
		ft_printf("\n");
		i++;
	}
}

void			vector_int_assign(int *vector, int len, int value)
{
	int i;

	i = 0;
	while (i < len)
	{
		vector[i] = value;
		i++;
	}
}

void			vector_int_print(int *vector, int len)
{
	int i;

	i = 0;
	while (i < len)
	{
		ft_printf("%d ", vector[i]);
		i++;
	}
	ft_printf("\n");
}
