#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>


size_t count_words(char *str)
{
	int i;
	int count;
	count = 0;
	i = 0;
	if(!str)
		return(0);
	while(str[i])
	{
		while(str[i] && (str[i] == ' ' || str[i] == 9))
		{
			i++;
		}
		if(str[i] == '\0')
			break;
		count++;
		while(str[i] && (str[i] != ' ' && str[i] != 9))
			i++;
	}
	return(count);
}

char *word_dup(char *s, size_t len)
{
	char *word;
	size_t i;
	i = 0;

	word = malloc(sizeof(char) * (len + 1));
	if(!word)
		return (NULL);
	while(i < len)
	{
		word[i] = s[i];
		i++;
	}
	word[i] = '\0';
	return(word);
}

char **ft_split(char *str)
{
	char **result;
	size_t k;
	size_t i;
	size_t start;
	i = 0;
	k = 0;

	if(!str)
		return (NULL);
	result = (char **)malloc(sizeof(char *) * (count_words(str) + 1));
	if(!result)
		return(NULL);
	while(str[i])
	{
		while(str[i] && (str[i] == ' ' || str[i] == 9))
			i++;
		if(!str[i])
			break;
		start = i;
		while(str[i] && (str[i] != ' ' && str[i] != 9))
			i++;
		result[k] = word_dup(&str[start], (i - start));
		if(!result[k])
		{
			while(k > 0)
				free(result[--k]);
			free(result);
			return(NULL);
		}
		k++;
	}
	result[k] = NULL;
	return(result);
}

int main(void)
{
    char str[] = "  sol estrela lua  ";
    char **split_result = ft_split(str);
    
    if(split_result)
    {
        for(int i = 0; split_result[i] != NULL; i++)
        {
            printf("Word %d: '%s'\n", i, split_result[i]);
			free(split_result[i]);
        }
        free(split_result);
    }
    return (0);
}