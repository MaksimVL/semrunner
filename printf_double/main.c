#include <stdio.h>
#include "libft.h"
#include "double.h"

int main(void)
{

	long double n;
	n = -999.999;



	char str[10000];
	str[0] = '\0';

	int prec = 2;
	printf("%.*Lf\n", prec, n);

	prf_dblcalc(n, prec, str);
	printf("%s\n", str);

	str[0] = 0;

	t_bignum bn;

	initialize_bignum(&bn,100);
	bn.sign = 1;
	bn.size = 3;
	bn.number[0] = 4321;
	bn.number[1] = 65;
	bn.number[2] = 100;
	bn.number[3] = 0;
	bn.exp = 17;
	put_bn_output(bn, str, 10);

	printf("%s", str);
}
