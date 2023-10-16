#include<iostream>
#include<stdio.h>       //includes c programs also

using namespace std;

int main()
{
    cout<<"Hello Ashish!"<<endl;
    cout<<"Welcome to C++ programming"<<endl;

    int n;
    cout<<"Enter size of array";
    cin>>n;
    int a[n];
    a[0]=2;

    for(int i:a)
    {
        cout<<i<<endl;
    }

    return 0;
}
