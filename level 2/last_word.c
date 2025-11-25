#include <unistd.h>

int main(int ac, char *av[])
{
	int i;
	int len;
	
	i = 0;
	len = 0;
	if(ac == 2)
	{
		while(av[1][len])
		{
			len++;
		}
		i = len - 1;
		while(i >= 0 && (av[1][i] == 32 || av[1][i] == 9))
		{
			i--;
		}
		while(i >= 0 && av[1][i] != 32 && av[1][i] != 9)
		{
			i--;
		}
		i++;
		while(av[1][i] != '\0' && av[1][i] != 32 && av[1][i] != 9)
		{
			write(1, &av[1][i], 1);
			i++;
		}	
	}
	write(1, "\n", 1);
}