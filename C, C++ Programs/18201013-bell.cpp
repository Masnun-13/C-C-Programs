#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

class Graph
{
    public:
    int v;
    vector<int> *adj;
    vector<int> *weights;

    int *distance;
    int *parent;

    Graph(int V);
    void addEdge(int v1, int v2, int w);
    void bell(int s)
    {
        int i, j, k;
        distance[s]=0;
        parent[s]=0;
        for(k=1; k<v; k++)
        {
            for(j=0; j<v; j++)
            {
                for(i=0; i<adj[j].size(); i++)
                {
                    int m = adj[j].at(i);
                    int dis = distance[j]+weights[j].at(i);
                    if(dis<distance[m])
                    {
                        distance[m]=dis;
                        parent[m]=j;
                    }
                }
            }
        }
    }
};

Graph::Graph(int a)
{
    v=a;
    adj = new vector<int>[v];
    weights = new vector<int>[v];
    parent = new int[v];
    distance = new int[v];
    int i;
    for(i=0; i<4; i++)
    {
        distance[i]=99999;
        parent[i]=-1;
    }

}

void Graph::addEdge(int v1, int v2, int w)
{
    adj[v1].push_back(v2);
    weights[v1].push_back(w);
}

int main()
{
    Graph g(4);
    g.addEdge(0, 1, 5);
    g.addEdge(0, 2, 3);
    g.addEdge(2, 1, 1);
    g.addEdge(1, 3, 2);
    int s=0;
    g.bell(s);
    for(int i=0; i<4; i++)
    {
        int p=i;
        cout<<"distance of vertex "<<i<<" from "<<s<<" = "<<g.distance[i];
        cout<<" path is ";
        while(p!=s)
        {
            cout<<p<<"-";
            p=g.parent[p];
        }
        cout<<s<<"\n";
    }
    return 0;
}
