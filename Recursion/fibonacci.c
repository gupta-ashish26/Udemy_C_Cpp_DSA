#include <stdio.h>

int fib(int n)
{
    if (n<=1)
        return n;
    else
        return fib(n-2)+fib(n-1);
}

//Momoization: Reducing the excessive function calls.(Better approach)

int f[10];
int fibonacci(int n)
{
    if (n<=1)
    {
        f[n] = n;
        return n;
    }
    else
    {
        if (f[n-2] == -1)
            f[n-2] = fibonacci(n-2);
        if (f[n-1] == -1)
            f[n-1] = fibonacci(n-1);
        
        return f[n-2]+f[n-1];
    }
}


int main()
{
    //initialize array as -1 as a whole
    for(int i = 0;i<10;i++)
        f[i] = -1;

    int n = 7;
    printf("fibonacci series term %dth : %d\n",n,fib(n));
    printf("fibonacci series term %dth : %d\n",n,fibonacci(n));

    return 0;
}