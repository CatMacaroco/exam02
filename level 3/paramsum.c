#include <unistd.h>

void ft_putnbr(int nb)
{
	char c;
	if(nb > 9)
		ft_putnbr(nb / 10);
	c = nb % 10 + '0';
	write(1, &c, 1);
}

int main(int ac, char *av[])
{
	int n;

	n = 0;
	(void)av;

	if(ac == 1)
		write(1, "0\n", 2);
	else if(ac > 1 && ac <= 10)
	{
		n = ac - 1 + '0';
		write(1, &n , 1);
		write(1, "\n", 1);
	}
	else
	{
		ft_putnbr(ac - 1);
		write(1, "\n", 1);
	}
}