#include <stdio.h>


typedef struct s_fig{
	char label;
	int is_set;
	int row[3];
	int col[3];
}	t_fig;


void	set_fig(t_fig *fig, char c, int row[3], int col[3])
{
	int i;

	fig->label = c;
	fig->is_set = 0;

	i = -1;
	while (++i < 3)
	{
		fig->row[i] = row[i];
		fig->col[i] = col[i];
	}
}

void	printmap(char map[4][4], int n)
{
	int i;
	int j;

	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
			printf("%c ", map[i][j]);
		printf("\n");
	}
}

int 	find_empty(char map, int size, int *row, int *col)
{
	int i;
	int j;

	i = -1;
	while (++i < size)
	{
		j = -1;
		while (++j < size)
			;
	}
	return 0;
}

int	check_figure(char map[4][4], int size_map, int row, int col, t_fig *fig)
{
	int i;

	i = 0;
	while (i < 3)
	{
		if (row + fig->row[i] >= size_map || row + fig->row[i] < 0)
			return (0);
		if (col + fig->col[i] >= size_map || col + fig->col[i] < 0)
			return (0);
		if (map[row + fig->row[i]][col + fig->col[i]] != '.')
			return (0);
		i++;
	}
	return (1);
}

void put_figure(char map[4][4], int size_map, int row, int col, t_fig *fig)
{
	int i;

	map[row][col] = fig->label;
	i = 0;
	while (i < 3)
	{
		map[row + fig->row[i]][col + fig->col[i]] = fig->label;
		i++;
	}
	fig->is_set = 1;
}

void remove_figure(char map[4][4], int size_map, int row, int col, t_fig *fig)
{
	int i;

	map[row][col] = '.';
	i = 0;
	while (i < 3)
	{
		map[row + fig->row[i]][col + fig->col[i]] = '.';
		i++;
	}
	fig->is_set = 0;
}

int solve_recursion(char map[4][4], int size_map, t_fig figs[3], int count_figures)
{
	int not_set_fig;
	int row;
	int col;
	int i_figs;

	i_figs = 0;
	while (figs[i_figs].is_set == 1 && i_figs < count_figures)
		i_figs++;
	//если все фигуры установлены:
	if (i_figs == count_figures)
		return (1);
	row = 0;
	while (row < size_map)
	{
		col = 0;
		while (col < size_map)
		{
			if (map[row][col] == '.')
			{
				if (check_figure(map, size_map, row, col, &figs[i_figs]))
				{
					put_figure(map, size_map, row, col, &figs[i_figs]);
					if (solve_recursion(map, size_map, figs, count_figures) == 1)
						return (1);
					else
						remove_figure(map, size_map, row, col, &figs[i_figs]);
				}
			}
			col++;
		}
		row++;
	}
	return (0);

	not_set_fig = 0;
	while(figs[not_set_fig].is_set == 1 && not_set_fig < count_figures)
		not_set_fig++;



}

int		solve_tetrimino(t_fig figs[3], int count_figures)
{
	char 	map[4][4];
	int i;
	int j;
	int size_map = 4;

	for (i = 0; i < size_map; i++)
		for (j = 0; j < size_map; j++)
			map[i][j] = '.';

	printmap((char*)map, size_map);
	//TODO сделать вычисление минимального размера карты, и последовательное увеличение карты
	solve_recursion(map, size_map, figs, count_figures);
	printf("\n");
	printmap((char*)map, size_map);
return 0;

}


int main()
{
	t_fig	figs[26];
	int		count_figures = 3;

	int rowA[3] = {1, 1, 1};    //    #
	int colA[3] = {-1, 0, 1};   //   ###
	set_fig(&figs[0], 'A', rowA, colA);

	int rowB[3] = {0, 1, 2};    //    ##
	int colB[3] = {1, 0, 0};    //    #
								//	  #
	set_fig(&figs[1], 'B', rowB, colB);

	int rowC[3] = {0, 0, 0};    // ####
	int colC[3] = {1, 2, 3};    //
	set_fig(&figs[2], 'C', rowC, colC);

	solve_tetrimino(figs, count_figures);
	printf("is_set = %d\n", figs[0].is_set);
	return 0;
}