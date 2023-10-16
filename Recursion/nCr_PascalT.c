#include<stdio.h>

//Pascal triangle gives you the result for nCr.
//For more understanding of the below code the triangle can be drawn and reffered.

int ncrpascal(int n,int r)
{
    if (r==0 || r==n)
        return 1;
    else
        return ncrpascal(n-1,r-1)+ncrpascal(n-1,r);
}


int main()
{
    int n = 5;
    int r = 3;
    printf("Using pascal triangle, Value of %dC%d is: %d\n",n,r,ncrpascal(n,r));

    return 0;
}