#include <unistd.h>

int main(int argc, char *argv[])
{
	int i;
	int len;

	i = 0;
	len = 0;
	if (argc == 2)
	{
		while(argv[1][i])
		{
			i++;
		}
		len = i;
		i = len - 1;
		while(argv[1][i])
		{
			write(1, &argv[1][i], 1);
			i--;
		}
	}
	write(1, "\n", 1);
}