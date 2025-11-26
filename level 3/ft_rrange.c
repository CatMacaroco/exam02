int     *ft_rrange(int start, int end)
{
	int i;
	int *range;
	int len;

	i = 0;
	if(start <= end)
		len = end - start + 1;
	else
		len = start - end + 1;
	range = (int *)malloc(sizeof(int) * len);
	while(i < len)
	{
		if(start <= end)
		{
			range[i] = end;
			end--; 
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