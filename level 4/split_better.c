#include <stdlib.h>
#include <stdio.h>

size_t count_words(char *s)
{
    size_t i = 0;
    size_t count = 0;
    
    while (s[i])
    {
        while (s[i] && (s[i] == ' ' || s[i] == '\t'))
            i++;
			
        if (s[i])
        {
            count++;
            while (s[i] && s[i] != ' ' && s[i] != '\t')
                i++;
        }
    }
    return (count);
}

char *word_dup(char *s, size_t start, size_t end)
{
    char *word;
    size_t i = 0;
    
    word = malloc(end - start + 1);
    if (!word)
        return (NULL);
    while (start < end)
        word[i++] = s[start++];
    word[i] = '\0';
    return (word);
}

char **ft_split(char *str)
{
    char **result;
    size_t i = 0;
    size_t k = 0;
    size_t start;
    
    if (!str)
        return (NULL);
    result = malloc(sizeof(char *) * (count_words(str) + 1));
    if (!result)
        return (NULL);
    while (str[i])
    {
        while (str[i] && (str[i] == ' ' || str[i] == '\t'))
            i++;
        if (str[i])
        {
            start = i;
            while (str[i] && str[i] != ' ' && str[i] != '\t')
                i++;
            result[k] = word_dup(str, start, i);
            if (!result[k])
            {
                while (k > 0)
                    free(result[--k]);
                free(result);
                return (NULL);
            }
            k++;
        }
    }
    result[k] = NULL;
    return (result);
}

int main(void)
{
    char const str[] = "allo sun shine";
    char c = ' ';
    char **result = ft_split((char *)str);

    if (!result) {
        printf("Split failed\n");
        return 1;
    }

    for (int i = 0; result[i] != NULL; i++) {
        printf("Word %d: %s\n", i, result[i]);
        free(result[i]); 
    }
    free(result);
    return 0;
}