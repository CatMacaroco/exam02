#include <unistd.h>

void is_space(char c)
{
	if(c == ' ' || (c >= 9 && c <= 13))
		return (1);
	return (0);
}

void is_letter(char c)
{
	if((c <= 'a' && c >= 'z') || (c <= 'A' && c >= 'Z'))
		return (1);
	return (0);
}

void capitalizer(char *str)
{
	int i;
	int j;

	i = 0;
	while(str[i])
	{
		if(str[i] >= 'A' && str[i] <= 'Z')
		{
			str[i] += 32;
		}
		j = i - 1;
		if(is_space(str[j]))
		{
			str[i] -= 32;
		}
		
		

	}
}

int main(int ac, char **av)
{
	int i;
	int j;

	i = 0;
	if(ac <= 1)
	{
		write(1, "\n", 1);
		return(0);
	}
	if(ac > 1)
	{
		capitalizer(av);
		write(1, "\n", 1);
	}
	return(0);
}