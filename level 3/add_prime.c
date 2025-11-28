#include <unistd.h>

int ft_atoi(char *str)
{
	int i;
	int sign;
	int nb;

	nb = 0;
	sign = 1;
	i = 0;
	while(str[i])
	{
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
	}
	return(nb * sign);
}

void ft_putnbr(int nb)
{
	char c;
	if(nb > 9)
		ft_putnbr(nb / 10);
	c = nb % 10 + '0';
	write(1, &c, 1);
}

int is_prime(int nb)
{
	if(nb < 2)
		return(0);
	int i = 2;
	while(i <= (nb / 2))
	{
		if(nb % i == 0)
			return(0);
		i++;
	}
	return(1);
}

int main(int ac, char **av)
{
	int i;
	int n;
	int sum;
	
	i = 0;
	sum = 0;
	if(ac != 2 || ft_atoi(av[1]) <= 0)
	{	
		write(1, "0\n", 2);
		return(0);
	}
	n = ft_atoi(av[1]);
	while(n > 1)
	{
		if(is_prime(n))
			sum += n;
		n--;
	}
	ft_putnbr(sum);
	write(1, "\n", 1);
	return(0);
}