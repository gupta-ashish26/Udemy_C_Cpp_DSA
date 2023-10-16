#include<stdio.h>

int exponent(int m,int n)
{
    if (n==0)
        return 1;
    else
        return m*exponent(m,n-1);
}

//faster approach
int powfn(int m,int n)
{
    if (n==0)
        return 1;
    if (n%2==0)
        return powfn(m*m,n/2);
    else
        return m*powfn(m*m,(n-1)/2);
    
}

int main()
{
    int result = exponent(2,10);
    int answer = powfn(2,10);
    printf("%d\n",result);
    printf("%d\n",answer);
    return 0;
}