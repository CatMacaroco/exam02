#include <stdio.h>

int	    is_power_of_2(unsigned int n)
{
	if(n == 0)
		return (0);
	while (n % 2 == 0)
		n = n / 2;
	return(n == 1);
}

int main(void)
{
	unsigned int n = 4;
	printf("%d", is_power_of_2(n));
}