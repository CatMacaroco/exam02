#include <unistd.h>

void ft_putnbr(int nb)
{
	char i;

	if (nb == -2147483648)
	{
		write (1, "-2147483648", 11);
		return ;
	}
	if (nb < 0)
	{
		write(1, "-", 1);
		nb = -nb;
	}
	if (nb >= 10)
		ft_putnbr(nb / 10);
	i = (nb % 10) + '0';
	write (1, &i, 1);
}

int main(void)
{
	int i;

	i = 0;
	while (i <= 100)
	{
		if (i % 3 == 0 && i % 5 == 0)
			write (1, "Fizzbuzz\n", 9);
		else if (i % 3 == 0)
			write (1, "fizz\n", 5);
		else if (i % 5 == 0)
			write (1, "buzz\n", 5);
		else
		{
			ft_putnbr(i);
			write(1, "\n", 1);
		}
		i++;
	}

}