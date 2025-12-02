#include <unistd.h>

int is_space(char c)
{
	if(c == ' '|| c == 9)
		return (1);
	return (0);
}

int main(int ac, char *av[])
{
	int i;
	int first_word;
	i = 0;
	first_word = 1;

	if(ac == 2)
	{
		while(is_space(av[1][i]))
			i++;
		while(av[1][i] && !is_space(av[1][i]))
			i++;
		while(av[1][i])
		{
			while(is_space(av[1][i]))
			{
				write(1, &av[1][i], 1);
				i++;
			}
			while(av[1][i] && !is_space(av[1][i]))
			{
				write(1, &av[1][i], 1);
				i++;
			}		
		}
		i = 0;
		while(is_space(av[1][i]))
			i++;
		if(av[1][i])
			write(1, " ", 1);
		while(av[1][i] && !is_space(av[1][i]))
			{
				write(1, &av[1][i], 1);
				i++;
			}		
	}
	write(1, "\n", 1);
}