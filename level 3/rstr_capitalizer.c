#include <unistd.h>

int ft_isspace(char c)
{
	if(c == 32 || c == 9)
		return (1);
	return(0);
}

int ft_is_letter(char c)
{
	if((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return(1);
	return(0);
}

void reverse_capitalizer(char *str)
{
	int i;
	int j;

	i = 0;
	while(str[i])
	{
		if(ft_is_letter(str[i]))
		{
			j = i + 1;
			while(str[j] && !ft_isspace(str[j]))
				j++;
		
			if(!str[j] || ft_isspace(str[j]))
			{
				if(str[i] >= 'a' && str[i] <= 'z')
					str[i] -= 32;
			}
			else if(str[i] >= 'A' && str[i] <= 'Z')
			{
				str[i] += 32;
			}
		}
		write(1, &str[i], 1);
		i++;
	}
}

int main(int ac, char **av)
{
	int i;

	i = 1;

	if(ac == 1)
	{
		write(1, "\n", 1);
		return(0);
	}
	while(i < ac)
	{
		reverse_capitalizer(av[i]);
		write(1, "\n", 1);
		i++;
	}
	return(0);
}
