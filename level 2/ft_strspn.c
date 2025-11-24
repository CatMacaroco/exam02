#include <stdio.h>
#include <string.h>

size_t	ft_strspn(const char *s, const char *accept)
{
	size_t i;
	size_t j;

	i = 0;
	while(s[i] != '\0')
	{
		j = 0;
		while(accept[j] != '\0' && s[i] != accept[j])
			j++;
		if(accept[j] == '\0')
			break;
		i++;
	}
	return (i);
}

int main(void)
{
	const char s[] = "allo";
	const char accept[] = "all";
	printf("%zu", ft_strspn(s, accept));
	//printf("%zu", strspn(s, accept));
}