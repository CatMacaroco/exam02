#include <unistd.h>
#include <stdlib.h>

void ft_puthex(unsigned int n)
{
	char digit;

	if(n >= 16)
		ft_puthex(n / 16);
	if((n % 16) < 10)
		digit = (n % 16) + '0';
	else
		digit = (n % 16) - 10 + 'a';
	write(1 , &digit, 1);
}

int main(int ac, char *av[])
{
	if(ac == 2)
	{
		ft_puthex(atoi(av[1]));
	}
	write(1, "\n", 1);
}