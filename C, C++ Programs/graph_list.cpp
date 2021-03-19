#include <bits/stdc++.h>
using namespace std;

int nNodes;
int nEdges;
vector<vector<int> > arr;

void setNodes(int n)
{
    nNodes=n;
    for(int i=0;i<nNodes;i++){
        vector<int> v;
        arr.push_back(v);
    }
}
void addEdge(int i,int j)
{
    if(i<0 || i>=nNodes || j<0 || j>=nNodes) return;
    arr[i].push_back(j);
    arr[j].push_back(i);
}

void removeEdge(int i,int j)
{
    if(i<0 || i>=nNodes || j<0 || j>=nNodes) return;
    int p=0;
    for(p=0;p<arr[i].size();p++){
        if(arr[i][p]==j) break;
    }
    if(p>=arr[i].size()) return;
    arr[i].erase(arr[i].begin()+p);

    p=0;
    for(p=0;p<arr[j].size();p++){
        if(arr[j][p]==i) break;
    }
    if(p>=arr[j].size()) return;
    arr[j].erase(arr[j].begin()+p);
}

int getDegree(int i)
{
    return arr[i].size();
}

void printGraph()
{
    for(int i=0;i<nNodes;i++){
        for(int j=0;j<arr[i].size();j++){
            cout<<arr[i][j]<<' ';
        }
        cout<<"\n";
    }
}

int main()
{
    setNodes(4);
    addEdge(0,1);
    addEdge(0,3);
    addEdge(1,2);
    printGraph();
}
