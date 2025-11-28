#include <unistd.h>

int is_space(char c)
{
	if(c == ' ' || c == 9)
		return (1);
	return(0);
}

void capitalize(char *s)
{
	int i;

	i = 0;
	while(s[i])
	{
		if(s[i] >= 'A' && s[i] <= 'Z')
			s[i] += 32;
		if((s[i] >= 'a' && s[i] <= 'z') && (s[i + 1] == '\0' || is_space(s[i + 1])))
		{
			s[i] -= 32;
		}
		write(1, &s[i], 1);
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



////rstr_capitalize
// void r_capitalizer(char *s)
// {
//     int i = 0;
//
//     while (s[i])
//     {
//         if (s[i] >= 'A' && s[i] <= 'Z')
//             s[i] += 32;
//
//         if ((s[i] >= 'a' && s[i] <= 'z') && (s[i + 1] == '\0' || s[i + 1] == ' '))
//             s[i] -= 32;
//
//         write(1, &s[i], 1);
//         i++;
//     }
// }
//
// int main(int argc, char **argv)
// {
//   if (argc < 2)
//   {
//     write (1, "\n", 1);
//     return 0;
//   }
//   int i = 1;
//   while (i < argc)
//   {
//     r_capitalizer(argv[i]);
//     write (1, "\n", 1);
//     i++;
//   }
//   return 0;
// }