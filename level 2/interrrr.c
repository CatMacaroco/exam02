#include <unistd.h>

int main(int ac, char *av[])
{
	int i;
	int j;

	i = 0;
	int lookup[256] = {};
	if(ac == 3)
	{
		while(av[1][i])
		{
			j = 0;
			while(av[2][j])
			{
				if(av[1][i] == av[2][j] && !lookup[(int)av[2][j]])
				{
					write(1, &av[1][i], 1);
					lookup[(int)av[2][j]] = 1;
				}
				j++;
			}
			i++;
		}
	}
	write(1, "\n", 1);
}

// "abc"
// "dabdcc"