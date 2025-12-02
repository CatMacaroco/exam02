#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int is_space(char c)
{
	if(c == ' ' || c == 9)
		return(1);
	return (0);
}

size_t numb_strings(const char *s)
{
	size_t i;
	size_t count;

	count = 0;
	i = 0;
	if(!s[i])
		return (0);
	while(s[i])
	{
		while(s[i] && is_space(s[i]))
			i++;
		if(s[i] == '\0')
			break;
		count++;
		while(!is_space(s[i]) && s[i])
			i++;
	}
	return (count);
}

char *allocate_substring(const char *start, size_t len)
{
	size_t i;
	char *substr;
	i = 0;
	substr = (char *)malloc(sizeof(char *) * len + 1);
	if(!substr)
		return(NULL);
	while(i < len)
	{
		substr[i] = start[i];
		i++;
	}
	substr[len] = '\0';
	return(substr);
}

char **ft_free(char **result, size_t count)
{
	while(count > 0)
		free(result[--count]);
	free(result);
	return (NULL);
}

// char **ft_free(char **result, size_t count)
// {
// 	while(count > 0)
// 	{
// 		free(result[count - 1]);
// 		count--;
// 	}
// 	free(result);
// 	return (NULL);
// }

char **ft_split(char *str)
{
	size_t i;
	size_t k;
	size_t start;
	size_t word_count;
	char **result;

	i = 0;
	k = 0;
	if(!str)
		return(NULL);
	word_count = numb_strings(str);
	result = (char **)malloc(sizeof(char *) * (word_count + 1));
	if(!result)
		return(NULL);
	while(str[i] && k < word_count)
	{
		while(str[i] && is_space(str[i]))
			i++;
		start = i;
		while(str[i] && !is_space(str[i]))
			i++;
		result[k] = allocate_substring(&str[start], i - start);
		if(!result[k])
			return(ft_free(result, k));
		k++;
	}
	result[k] = "\0";
	return(result);
}

//
//
//
void ft_putstr(char *str)
{
    while (*str)
        write(1, str++, 1);
}

int main(int ac, char **av)
{
    char **words;
    size_t i;

    if (ac != 2)
    {
        write(1, "\n", 1);
        return 0;
    }

    words = ft_split(av[1]);
    if (!words)
        return 1;

    i = 0;
    while (words[i])
    {
        ft_putstr(words[i]);
        write(1, "\n", 1);
        i++;
    }

    // Free allocated memory
    i = 0;
    while (words[i])
    {
        free(words[i]);
        i++;
    }
    free(words);

    return 0;
}