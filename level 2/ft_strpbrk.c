#include <string.h>
#include <stdio.h>

char	*ft_strpbrk(const char *s1, const char *s2)
{
	int i;
	int j;

	i = 0;
	while(s1[i] != '\0')
	{
		j = 0;
		while(s2[i] != '\0')
		{
			if(s1[i] == s2[j])
				return ((char *)&s1[i]);
			j++;
		}
		i++;
	}
	return(NULL);
}

int main(void)
{
	const char s1[] = "allo";
	const char s2[] = "o";
	printf("%p", ft_strpbrk(s1, s2));
	//printf("%p", strpbrk(s1, s2));
}