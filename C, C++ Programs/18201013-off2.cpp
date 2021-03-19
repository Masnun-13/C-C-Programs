#include<chrono>
#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;

class item
{
    public:
    int weight, serial;
    double price;
    double val;
    double getval()
    {
        val=(1.0*price)/(1.0*weight);
        return val;
    }
};

int main()
{
    int n, i ,j;
    cout<<"Insert number of items\n";
    cin>>n;
    item items[n];
    for(i =0; i<n; i++)
    {
        items[i].serial=i+1;
        cout<<"Insert weight and price of item "<<items[i].serial<<"\n";
        cin>>items[i].weight;
        cin>>items[i].price;
    }

    int cap;
    item itemu[n];
    double money=0;
    cout<<"Insert capacity\n";
    cin>>cap;


    //sorting
    for(i=0; i<n; i++)
    {
        int d=0;
        for(j=0; j<n; j++)
        {
            if((items[i].getval()>items[j].getval())||((i>j)&&items[i].getval()==items[j].getval()))
            {
                d++;
            }
        }
        itemu[d]=items[i];
    }

    auto start = chrono::high_resolution_clock::now();



    //main calculation
    for(i=n-1; i>=0; i--)
    {
        int wt = itemu[i].weight;
        if(cap>=wt)
        {
            cap-=wt;
            money+=itemu[i].price;
            cout<<"Item "<<itemu[i].serial<<": "<<wt<<" kg - Remaining capacity "<<cap<<"\n";
        }
        else if (cap>0)
        {
            money+=itemu[i].getval()*cap;
            cout<<"Item "<<itemu[i].serial<<": "<<cap<<" kg out of "<<wt<<" (broken) - Remaining capacity 0\n";
            break;
        }
        else
        {
            break;
        }
    }
    cout<<"\nTotal value gained: "<<money;
    auto stop= chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::microseconds>(stop - start);
    cout<<"\n\nAlgorithm runtime: "<<duration.count()<<" microseconds\n";
}


