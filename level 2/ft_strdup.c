#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char    *ft_strdup(char *src)
{
	int i;
	char *ptr;

	i = 0;
	while(src[i] != '\0')
		i++;
	ptr = (char *)malloc(sizeof(char) * (i + 1));
	if(!ptr)
		return (NULL);
	i = 0;
	while(src[i] != '\0')
	{
		ptr[i] = src[i];
		i++;
	}
	ptr[i] = '\0';
	return(ptr);
}

int main(void)
{
	char src[]= "allo";
	printf("%s", ft_strdup(src));
	//printf("%s", strdup(src));
}