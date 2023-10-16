#include <stdio.h>

//e^x = 1 + (x/1!) + (x^2/2!) + (x^3/3!) + ..... n terms
//e^x = (x^0/0!) + (x/1!) + (x^2/2!) + (x^3/3!) + ..... n terms

double taylor(double x, double n)
{
    static double p = 1,f = 1;
    double res;

    if (n==0)
        return 1;
    else
    {
        res = taylor(x,n-1);
        p = p*x;
        f = f*n;

        return (res+(p/f)) ;
    }       
}

//More efficient method (Horner's Method)

double e (double x,double n)
{
    static double sum = 1;
    if (n==0)
        return sum;
    else
    {
        sum = 1+x/n*sum;
        return e(x,n-1);
    }
}


int main()
{
    double x = 1;
    double no_of_terms = 10;
    double result = taylor(x,no_of_terms);
    double answer = e(1,10);
    printf("result = %f\n",result);
    printf("result = %f\n",answer);

    return 0;
}