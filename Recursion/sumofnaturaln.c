#include <stdio.h>

int sumnatural(int n)
{
    if (n>0)
    {
        return sumnatural(n-1)+n;
    }
    else
        return 0;
}

int main()
{
    int x = 10;
    printf("Sum of %d natural numbers are: %d \n",x,sumnatural(x));
    return 0;
}