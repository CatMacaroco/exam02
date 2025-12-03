#include <unistd.h>

int ft_atoi(char *str)
{
	int i;
	int nb;

	nb = 0;
	i = 0;
	if(str[i] >= '0' && str[i] <= '9')
	{
		nb = nb * 10 + (str[i] - '0');
		i++;
	}
	return(nb);
}

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
	int i;
	int nb;

	i = 1;
	if(ac == 2)
	{
		nb = ft_atoi(av[1]);

		while(i < 10)
		{
			ft_putnbr(i);
			write(1, " X ", 3);
			ft_putnbr(nb);
			write(1, " = ", 3);
			ft_putnbr(i * nb);
			write(1, "\n", 1);
			i++;
		}
	}
	else
		write(1, "\n", 1);
	return(0);
}