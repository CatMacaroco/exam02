#include <stdlib.h>
#include <stdio.h>

char **ft_split(char *str)
{
	char **result;
	size_t word_count;
	size_t k;
	size_t i;
	size_t j;
	size_t start;
	size_t len;
	
	// Handle NULL input
	if(!str)
		return (NULL);
	
	// Count words inline
	i = 0;
	word_count = 0;
	while(str[i])
	{
		while(str[i] && (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'))
			i++;
		if(str[i] == '\0')
			break;
		word_count++;
		while(str[i] && (str[i] != ' ' && str[i] != '\t' && str[i] != '\n'))
			i++;
	}
	
	// Allocate result array
	result = (char **)malloc(sizeof(char *) * (word_count + 1));
	if(!result)
		return(NULL);
	
	// Extract words
	i = 0;
	k = 0;
	while(str[i])
	{
		// Skip whitespace
		while(str[i] && (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'))
			i++;
		if(!str[i])
			break;
		
		// Mark start and find length
		start = i;
		while(str[i] && (str[i] != ' ' && str[i] != '\t' && str[i] != '\n'))
			i++;
		len = i - start;
		
		// Allocate and copy word inline
		result[k] = malloc(sizeof(char) * (len + 1));
		if(!result[k])
		{
			// Free everything on failure
			while(k > 0)
				free(result[--k]);
			free(result);
			return(NULL);
		}
		
		// Copy the word
		j = 0;
		while(j < len)
		{
			result[k][j] = str[start + j];
			j++;
		}
		result[k][j] = '\0';
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