#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int is_space(char c)
{
    if(c == ' ' || c == 9)
        return(1);
    return(0);
}

size_t numb_substrings(char const *s)
{
    size_t count;
    size_t i;
    i = 0;
    count = 0;
    if(!s)
        return (0);
    while(s[i])
    {
        while(s[i] && is_space(s[i]))
            i++;
        if(s[i] == '\0')
            break;
        count++;
        while(s[i] && !is_space(s[i]))
            i++;
    }
    return(count);
}

char *allocate_substr(const char *start, size_t len)
{
    size_t i;
    char *substr;
    i = 0;
    substr = (char *)malloc(sizeof(char) * len + 1);
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
    return(NULL);
}

char    **ft_split(char *str)
{
    size_t i;
    size_t k;
    size_t start;
    size_t word_count;
    char **result;

    i = 0;
    k = 0;
    if(!str)
        return (NULL);
    word_count = numb_substrings(str);
    result = (char **)malloc(sizeof(char *) * (word_count + 1));
    if(!result)
        return (NULL);
    while(str[i] && k < word_count)
    {
        while(str[i] && is_space(str[i]))
            i++;
        start = i;
        while(str[i] && !is_space(str[i]))
            i++;
        result[k] = allocate_substr(&str[start], i - start);
        if(!result[k])
            return(ft_free(result, k));
        k++;
    }
    result[k] = NULL;
    return(result); 
}


int main(void)
{
    char str[] = "  lkaka aiia lua  ";
    char **split_result = ft_split(str);
    
    if(split_result)
    {
        for(int i = 0; split_result[i] != NULL; i++)
        {
            printf("Word %d: '%s'\n", i, split_result[i]);
        }
        ft_free(split_result, numb_substrings(str));
    }
    return (0);
}