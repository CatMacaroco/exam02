#include <unistd.h>

void capitalizer(char *s)
{
	int i;

	i = 0;
	while(s[i])
	{
		if(s[i] == 32 || s[i] == 9)
		{
			write(1, &s[i], 1);
			i++;
		}
		if((i == 0 || s[i - 1] == 32 || s[i - 1] == 9) && s[i] >= 'a' && s[i] <= 'z')
			s[i] -= 32;
		else if(s[i] >= 'A' && s[i] <= 'Z')
			s[i] += 32;
		write(1, &s[i], 1);
		i++;
	}
}

int main(int ac, char **av)
{
	int i;
	i = 1;

	if(ac >= 2)
	{
		while(i < ac)
		{
			capitalizer(av[i]);
			write(1, "\n", 1);
			i++;
		}
	}
	write(1, "\n", 1);

}