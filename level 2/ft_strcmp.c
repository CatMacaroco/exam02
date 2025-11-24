#include <string.h>
#include <stdio.h>

int    ft_strcmp(char *s1, char *s2)
{
	int i;

	i = 0;
	// if(!s1 || !s2)
	// 	return (NULL);
	while((s1[i] != '\0' || s2[i] != '\0') && s1[i] == s2[i])
		i++;
	return(s1[i] - s2[i]);
}

int main(void)
{
	char s1[]= "allo";
	char *s2= NULL;
	//printf("%d", ft_strcmp(s1, s2));
	printf("%d", strcmp(s1, s2));
}