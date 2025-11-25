#include <stdio.h>

char    *ft_strrev(char *str)
{
	int i;
	int len;
	int temp;

	len = 0;
	i = 0;
	while(str[len] != '\0')
	{
		len++;
	}
	while(i < (len - 1))
	{
		temp = str[i];
		str[i] = str[len - 1];
		str[len - 1] = temp;
		i++;
		len--;
	}
	return(str);
}

int main(void)
{
	char str[] = "allo";
	printf("%s", ft_strrev(str));
}