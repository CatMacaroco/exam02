#include <unistd.h>

int main(int ac, char *av[])
{
    int i;
    int d;
    int j;

    i = 0;
    d = 0;
    j= 0;
    if(ac == 4)
    {
        while(av[1][i] != '\0')
        {
            if(av[1][i] == av[2][d])
                av[1][i] = av[3][j];
            write(1, &av[1][i], 1);
            i++;
        }
    }
    write(1, "/n", 1);
}