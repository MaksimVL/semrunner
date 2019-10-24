#include "libft.h"

int				ft_isint(char *str)
{
	int i;
	int count_numbers;

	if (str == NULL || str[0] == '\0')
		return (0);
	else if (ft_isdigit(str[0]))
		count_numbers = 1;
	else if (str[0] == '-' || str[0] == '+')
		count_numbers = 0;
	else
		return (0);
	i = 1;
	while (str[i] != '\0')
	{
		if (ft_isdigit(str[i]) == 0)
			return (0);
		count_numbers++;
		i++;
	}
	return ((count_numbers == 0) ? 0 : 1);
}
