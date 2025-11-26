#include <stdio.h>
#include <stdlib.h>

int     *ft_range(int start, int end)
{
	int i;
	int len;
	int *range;

	i = 0;
	if(start <= end)
		len = end - start + 1;
	else
		len = start - end + 1;
	range = (int *)malloc(sizeof(int) * len);
	while(i < len)
	{
		if(start < end)
		{
			range[i] = start;
			start++;
		}
		else
		{
			range[i] = start;
			start--;
		}
		i++;
	}
	return(range);
}
