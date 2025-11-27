#include <stdio.h>
#include <stdlib.h>

int main(int ac, char *av[])
{
	int nb1;
	int nb2;
	if(ac == 3)
	{
		nb1 = atoi(av[1]);
		nb2 = atoi(av[2]);
		
		if(nb1 > 0 && nb2 > 0)
		{
			while(nb1 != nb2)
			{
				if(nb1 > nb2)
					nb1 = nb1 - nb2;
				else
					nb2 = nb2 - nb1;
			}
			printf("%d", nb1);
		}
	}
	printf("\n");
}