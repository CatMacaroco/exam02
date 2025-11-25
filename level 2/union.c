#include <unistd.h>

int main(int ac, char *av[])
{
	int i;
	int j;
	int lookup[128]= {};

	i = 0;
	j = 0;
	if(ac == 3)
	{
		while(av[1][i])
		{
			if(!lookup[(int)av[1][i]])
			{
				lookup[(int)av[1][i]] = 1;
				write(1, &av[1][i], 1);
			}
			i++;
		}
		while(av[2][j])
		{
			if(!lookup[(int)av[2][j]])
			{
				lookup[(int)av[2][j]] = 1;
				write(1, &av[2][j], 1);
			}
			j++;
		}
	}
	write(1, "\n", 1);
}

//Essentially, once you finish processing the first string and marking its characters,
// all characters in it are already marked in lookup.
//So for the second string, simply checking !lookup[(int)av[2][j]]
// alone suffices to know if this character was printed before.
