#include<iostream>
#include<cmath>

using namespace std;

int fibr(int n)
{
    if(n<=1)
    {
        return n;
    }
    else return fibr(n-1)+fibr(n-2);
}

int fibd(int n, int* arr)
{
    arr[0]=0;
    arr[1]=1;
    for(int i=2; i<=n; i++)
    {
        arr[i]=arr[i-1]+arr[i-2];
    }
}

int main()
{
    int* fib = new int[7];
    fibd(6, fib);
    for(int i = 0; i <=6; i++)
    {
        cout<<fib[i]<<" ";
    }
}
