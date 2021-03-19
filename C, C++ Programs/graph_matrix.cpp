#include <bits/stdc++.h>
using namespace std;

int nNodes;
int nEdges;
int **matrix;

void setNodes(int n)
{
    nNodes = n ;
    matrix = new int*[nNodes];
    for(int i=0;i<nNodes;i++)
    {
        matrix[i] = new int[nNodes];
    }
    for(int i=0;i<nNodes;i++)
    {
        for(int j=0;j<nNodes;j++){
            matrix[i][j]=0;
        }
    }
}

void addEdge(int i,int j)
{
    if(i<0 || i>=nNodes || j<0 || j>=nNodes) return;
    matrix[i][j]=1;
    matrix[j][i]=1;
}

void removeEdge(int i,int j)
{
    if(i<0 || i>=nNodes || j<0 || j>=nNodes) return;
    matrix[i][j]=0;
    matrix[j][i]=0;
}

void printGraph()
{
    for(int i=0;i<nNodes;i++){
        for(int j=0;j<nNodes;j++){
            cout<<matrix[i][j]<<' ';
        }
        cout<<"\n";
    }
}

int getDegree(int i)
{
    int c=0;
    for(int j=0;j<nNodes;j++){
        if(matrix[i][j]==1) c++;
    }
    return c;
}

int main()
{
    setNodes(4);
    addEdge(0,1);
    addEdge(0,3);
    addEdge(1,2);
    printGraph();
}
