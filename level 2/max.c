#include <stdio.h>

int		max(int* tab, unsigned int len)
{	
	int count = 0;
	int result = 0;
	int i = 0;
	if(len > 0)
	{
		while(count < len)
		{
			if(tab[i] > result)
				result = tab[i];
			i++;
			count++;
		}
		return (result);
	}
	return (0);
}

int main(void)
{
	int tab[] = {1, 4, 9, 0, 76, 3};
	printf("%d", max(tab, 6));
}