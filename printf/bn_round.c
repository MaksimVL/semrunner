#include "libft.h"
#include "double.h"

void			roundbd(t_bigdec *bd, int prec)
{
	t_bignum	one;
	t_bignum	ten;
	int pos;

	if (getiinfract(*bd, prec + 1) == -1)
		return ;
	if (getiinfract(*bd, prec + 1) >= 5)
	{
		ft_assign_bignum(&ten, 10);
		pos = bd->sizefract - prec + 1;
		if (pos <= 0)
			return ;
		ft_put_one_inpos_bignum(&one, pos);
		ft_isumabs_bignum(&(bd->fractpart), one);
	}
	if (getiinfract(*bd, 0) == 1)
	{
		ft_assign_bignum(&one, 1);
		ft_isumabs_bignum(&(bd->intpart), one);
		set_onetozero_infract(bd, 0);
	}
	fixsize_bignum(&(bd->fractpart));
	bd->prec = prec;
}

int 			getiinfract(t_bigdec bd, int i)
{
	int pos;
	int tmp;

	if (i < 0)
		return (-1);
	pos = bd.sizefract - i + 1;
	if (pos <= 0)
		return (-1);
	tmp = bd.fractpart.number[(pos - 1) / 4] / ft_pow_bn(10, (pos - 1) % 4);
	return (tmp % 10);
}

int 			set_onetozero_infract(t_bigdec *bd, int i)
{
	int pos;
	pos = bd->sizefract -i + 1;
	bd->fractpart.number[(pos - 1) / 4] -= ft_pow_bn(10, (pos - 1) % 4);
}

void			ft_put_one_inpos_bignum(t_bignum *bn, int pos)
{
	initialize_bignum(bn);
	bn->number[(pos - 1) / 4] = ft_pow_bn(10, (pos - 1) % 4);
	bn->size = (pos - 1) / 4 + 1;
}