#include<chrono>
#include<iostream>
#include<cmath>
using namespace std;


void primesum(int n)
{
    bool a[n];
    int rt=(int)sqrt(n);
    int b[rt], i, j;
    for(i=0; i<n; i++)
    {
        a[i]=true;
    }
    int k=0;
    for(i=2; i<n; i++)
    {
        if(a[i]==true)
        {
            b[k]=i;
            k++;
            for(j=i*2; j<n; j=j+i)
            {
                a[j]=false;
            }
        }
    }
    bool cond=false;
    for(i=0; i<k; i++)
    {

        for(j=i+1; j<k; j++)
        {
            if(b[i]+b[j]==n)
            {
                cout<<n<<" = "<<b[i]<<" + "<<b[j]<<"\n";
                cond = true;
                break;
            }
        }
        if(cond==true)
        {
        break;
        }
    }
    if(cond==true)
    {
        cout<<"\nConjecture verified.\n";
    }
    else cout<<"\nConjecture not verified\n";
}

int main()
{
    int a;
    cout<<"Input the number to test\n";
    cin>>a;
    auto start = chrono::high_resolution_clock::now();
    primesum(a);
    auto stop= chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::microseconds>(stop - start);
    cout<<"\nAlgorithm runtime: "<<duration.count()<<" microseconds\n";
}


