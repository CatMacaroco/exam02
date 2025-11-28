#include <unistd.h>

void capitalize(char *s)
{
	int i;
	int new_word = 1;

	i = 0;
	while(s[i])
	{
		if(s[i] == ' ' || s[i] == 9)
		{
			write(1, &s[i], 1);
			new_word = 1;
		}
		else
		{
			if(new_word && s[i] >= 'a' && s[i] <= 'z')
				s[i] -= 32;
			else if(!new_word && s[i] >= 'A' && s[i] <= 'Z')
				s[i] += 32;
			write(1, &s[i], 1);
			new_word = 0;
		}
		i++;
	}
}

int main(int ac, char **av)
{
	int i;
	if(ac >= 2)
	{
		i = 1;
		while(i < ac)
		{
			capitalize(av[i]);
			write(1, "\n", 1);
			i++;
		}
	}
	write(1, "\n", 1);
}
