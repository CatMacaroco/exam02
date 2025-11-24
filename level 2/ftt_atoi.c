#include <stdio.h>

int ft_atoi(char *str)
{
	int i;
	int sign;
	int nb;

	nb = 0;
	sign = 1;
	i = 0;
	while(str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if(str[i] == '-' || str[i] == '+')
	{
		if(str[i] == '-')
			sign = -sign;
		i++;
	}
	while(str[i] >= '0' && str[i] <= '9')
	{
		nb = nb * 10 + (str[i] - '0');
		i++;
	}
	return(sign * nb);
}

int main(void)
{
	char str[] = "   -68534hhgfgh9";
	printf("%d", ft_atoi(str));
}
