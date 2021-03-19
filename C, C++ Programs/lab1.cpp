#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

class Graph
{
public:
    int V;
    vector<int> *adj;
    //vector<int> *weights;
    //vector<int> visited
    //not_visited

    //int *distance;
    //parent array

    Graph(int V);
    void addEdge(int v1, int v2, int w);

    //dijkstra declare
};

Graph::Graph(int V)
{
    this->V = V;
    adj = new vector<int>[V];
    //initialize weights

    //initialize parent and distance array

    //initialize not_visited vector

}

void Graph::addEdge(int v1, int v2, int w)
{
    adj[v1].push_back(v2);
    //weight update
}

//dijkstra(int s) implement

int main()
{
    Graph g(4);
    g.addEdge(0, 1, 5);
    g.addEdge(0, 2,3);
    g.addEdge(2, 1,1);
    g.addEdge(1, 3,2);

    //g.distace[s] = 0
    //call dijkstra

    //test shortest path (distance + path)

}
