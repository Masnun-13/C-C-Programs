#include<chrono>
#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;

int lcs(string a, string b, int c, int d)
{
    if(c==0||d==0)
    {
        return 0;
    }
    else if(a[c-1]==b[d-1])
    {
        return 1+lcs(a, b, c-1, d-1);
    }
    else
    {
        return lcs(a, b, c-1, d-1);
    }

}


int main()
{
    string a = "ABCBANGLAWQ";
    string b = "ZBANGLASQ";
    int c=a.length();
    int d=b.length();
    int arr[c][d];
    auto start = chrono::high_resolution_clock::now();
    for(int i=0; i<=c; i++)
        {
            for(int j=0; j<=d; j++)
            {
              arr[i][j]=lcs(a, b, i, j);
            }
        }
        int maxa=0;
    for(int i=0; i<=c; i++)
        {
            for(int j=0; j<=d; j++)
            {
              if((arr[i][j]>maxa)&&!(i<c-5))
              {
                  maxa=arr[i][j];
              }
            }
        }
    cout<<maxa;

    auto stop= chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::microseconds>(stop - start);
    cout<<"\n\nAlgorithm runtime: "<<duration.count()<<" microseconds\n";
}


