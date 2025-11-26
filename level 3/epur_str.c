#include <unistd.h>

int main(int ac, char *av[])
{
	int i;
	int space;

	space = 0;
	i = 0;
	if(ac == 2)
	{
		while(av[1][i] == ' ' || (av[1][i] >= 9 && av[1][i] <= 13))
		{
			i++;
		}
		while(av[1][i])
		{
			if(av[1][i] == ' ' || (av[1][i] >= 9 && av[1][i] <= 13))
				space = 1;
			else
			{
				if (space)
				{
					write(1, " ", 1);
				}
				space = 0;
				write(1, &av[1][i], 1);
			}
			i++;
		}
	}
	write(1, "\n", 1);
}
	

	