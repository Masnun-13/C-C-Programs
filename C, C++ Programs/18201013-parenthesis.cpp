#include<iostream>
#include<cmath>

using namespace std;


int calc(int a, char b, int c)
{
    if (b=='+')
    {
        return a+c;
    }
    else if (b=='-')
    {
        return a-c;
    }
    if (b=='*')
    {
        return a*c;
    }
}
int T(int i, int j, int num[], char op[], int n)
{
    int k;
    int maxi=-999;
    int res;
    int dp[n][n];
    if(i==j)
    {
        dp[i][j]=num[i];
    }
    else for(k=i; k<j; k++)
    {
        res=calc(T(i, k, num, op, n), op[k], T(k+1, j, num, op, n));
        if(res>maxi)
        {
            maxi=res;
            dp[i][j]=maxi;
        }
    }
    return dp[i][j];
}

int dyn(int i, int j, int num[], char op[], int n)
{
    int k;
    int maxi=-999;
    int maxi2;
    int res;
    int dp[n][n];
    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
        {
            if(i==j)
            {
                dp[i][j]=num[i];
            }
            else dp[i][j]=maxi;

        }

    }
    for(int s=0; s<=n; s++)
    {
    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
        {
            maxi2=maxi;
            if(i==j)
            {
                maxi2=num[i];
            }
            else if(i<j)
            {
                for(k=i; k<j; k++)
                {
                    res=calc(dp[i][k], op[k], dp[k+1][j]);
                    if(res>maxi2)
                    {
                        maxi2=res;
                    }
                }
            }
            else
            {
                for(k=j; k<i; k++)
                {
                    res=calc(dp[j][k], op[k], dp[k+1][i]);
                    if(res>maxi2)
                    {
                        maxi2=res;
                    }
                }
            }

            dp[i][j]=maxi2;
        }
    }
    }
    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
        {
            if(dp[i][j]>maxi)
            {
                maxi=dp[i][j];
            }
        }
    }
    cout<<"Max using entire expression with dp: "<<dp[0][n-1]<<"\n";
    return maxi;
}


int main()
{
    int n;
    cout<<"number of numbers: ";
    cin>>n;
    int num[n];
    char op[n-1];
    int i;
    int j=0, k=0;
    cout<<"insert expression ";
    for(i=0;i<n*2; i++)
    {
        if(i%2==0)
        {
            cin>>num[j];
            j++;
            if(j==n)
            {
                break;
            }
        }
        else
        {
            cin>>op[k];
            k++;
        }
    }
    cout<<"Max using entire expression with recursion: "<<T(0, n-1, num, op, n-1)<<"\n";
    cout<<"Max using any part of expression with dp: "<<dyn(0, n, num, op, n);
}
