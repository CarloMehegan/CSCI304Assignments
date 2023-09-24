#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int i = 2;
    while (i < 256)
    {
        i = square(i);
    }
    printf("%d\n", i);
    return (EXIT_SUCCESS);
}

int square(int x)
{
    int y = x * x;
    return (x * x);
}