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
    vector<int> visited;
    bool* not_visited;

    int *distance;
    int *parent;

    Graph(int V);
    void addEdge(int v1, int v2, int w);

    void dij(int s)
    {
        int i;
        distance[s]=0;
        parent[s]=0;
        while(visited.size()<4)
        {
            int x=9999;
            int dist=9999;

            for(i=0; i<v; i++)
            {
                if(distance[i]<dist && not_visited[i]==true)
                {
                    x=i;
                    dist=distance[i];
                }
            }
            visited.push_back(x);
            not_visited[x]=false;
            for(int i=0; i<adj[x].size(); i++)
            {
                int m = adj[x].at(i);
                int dis = distance[x]+weights[x].at(i);
                if(dis<distance[m])
                {
                    distance[m]=dis;
                    parent[m]=x;
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
    not_visited= new bool[v];
    int i;
    for(i=0; i<4; i++)
    {
        distance[i]=99999;
        parent[i]=-1;
        not_visited[i]=true;
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
    g.dij(s);
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
