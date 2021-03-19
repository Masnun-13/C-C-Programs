#include<iostream>
#include<vector>

using namespace std;

class Graph
{
public:
    int V;
    vector<int> *adj;
    bool *visited;
    int *color;
    Graph(int V);
    void addEdge(int v1, int v2);
    void DFS(int s);
};

Graph::Graph(int V)
{
    this->V = V;
    adj = new vector<int>[V];
    color = new int(V);
    visited = new bool[V];
    for(int i=0;i<V;i++)
    {
        visited[i]=false;
        color[i]=2;
    }
}

void Graph::addEdge(int v1, int v2)
{
    adj[v1].push_back(v2);
    adj[v2].push_back(v1);
}

void Graph::DFS(int s)
{
    visited[s] = true;
    cout<<s<<", ";

    for(int i=0;i<adj[s].size();i++)
    {
        int v = adj[s].at(i);
        if(!visited[v])
        {
            if(color[s]==2)
            {
                color[v]=1;
            }
            else color[v]=2;
            DFS(v);
        }
    }
}

int main()
{
    int N=6;
    Graph g(N);

    g.addEdge(0,2);
    g.addEdge(1,2);
    g.addEdge(2,3);
    g.addEdge(2,4);
    g.addEdge(2,5);
    g.addEdge(4,5); //this edge causes not bicolorable


    g.DFS(0);
    cout<<"\n";

    cout<<"adjacency list:\n";

    for(int i=0;i<N; i++)
    {
        cout<<i<<": ";
        for(int j=0;j<g.adj[i].size();j++)
        {
            cout<<g.adj[i].at(j)<<", ";

        }
        cout<<"\n";
    }
   cout<<"\n";

   cout<<"color list:\n";
   for(int i=0;i<N; i++)
    {
        cout<<i<<"-";
        if(g.color[i]==2)
        {
            cout<<"red";
        }
        else cout<<"blue";
        cout<<"\n";
    }
   cout<<"\n";

   for(int i=0;i<N; i++)
    {

        for(int j=0;j<g.adj[i].size();j++)
        {

            if(g.color[i] == g.color[g.adj[i].at(j)] )
            {
                cout<<"not bicolorable";
                return 0;
            }
        }

    }
   cout<<"bicolorable";
}
