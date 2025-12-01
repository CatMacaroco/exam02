#include <stdio.h>

int char_to_value(char c)
{
	if(c >= '0' && c <= '9')
		return(c - '0');
	else if(c >= 'a' && c <= 'f')
		return(c - 'a' + 10);
	else if(c >= 'A' && c <= 'F')
		return(c - 'A' + 10);
	return(-1);
}

int	ft_atoi_base(const char *str, int str_base)
{
	int i;
	int digit;
	int sign;
	int result;

	sign = 1;
	result = 0;
	i = 0;
	
	if(str[i] == '-')
	{
		sign = -sign;
		i++;			
	}
	while(str[i])
	{
		digit = char_to_value(str[i]);
		if(digit == -1 || digit >= str_base)
			break;
		result = result * str_base + digit;
		i++;
	}
	return(result * sign);
}

int main(void)
{
	const char str[] = "-1019459ab";
	printf("%d", ft_atoi_base(str, 16));
	return(0);
}