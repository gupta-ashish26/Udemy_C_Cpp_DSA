#include<stdio.h>

void tower(int n, int a, int b, int c)
{
    if(n>0)
    {
        tower(n-1,a,c,b);
        printf("(%d,%d)\n",a,c);
        tower(n-1,b,a,c);
    }
}

int main()
{
    tower(16,1,2,3);
    return 0;
}