#include <unistd.h>

void ft_putnbr(int nb)
{
	char c;
	if(nb > 9)
		ft_putnbr(nb / 10);
	c = nb % 10 + '0';
	write(1, &c, 1);
}

int ft_atoi(char *str)
{
	int i;
	int sign;
	int nb;

	i = 0;
	sign = 1;
	nb = 0;

		while(str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
			i++;
		if(str[i] == '+' || str[i] == '-')
		{
			if(str[i] == '-')
			{
				sign = -sign;
			}
			i++;
		}
		while(str[i] >= '0' && str[i] <= '9')
		{
			nb = nb * 10 + (str[i] - '0');
			i++;
		}
		return(sign * nb);

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
			write(1, " x ", 3);
			ft_putnbr(nb);
			write(1, " = ", 3);
			ft_putnbr(i * nb);
			write(1, "\n", 1);
			i++;
		}
	}
	write(1, "\n", 1);
}