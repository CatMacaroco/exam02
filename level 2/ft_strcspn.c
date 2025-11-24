#include <string.h>
#include <stdio.h>

size_t	ft_strcspn(const char *s, const char *reject)
{
	size_t i;
	size_t j;

	i = 0;
	while(s[i] != '\0')
	{
		i++;
		j = 0;
		while(reject[j])
		{
			if(s[i] == reject[j])
				return(i);
				j++;
		}
	}
	return(i);
}

int main(void)
{
	const char s[]= "erallo";
	const char reject[]= "al";
	printf("%zu", ft_strcspn(s, reject));
	//printf("%zu", strcspn(s, reject));
}