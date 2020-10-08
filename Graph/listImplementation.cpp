/*
    ----------------List Implementation of graph--------------
    We also can use vector of vector ,for flexibility to add or remove a vertex
*/

#include<bits/stdc++.h>
using namespace std;

void addEdge(vector<int> adj[],int u,int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void printGraph(vector<int> adj[],int v)
{
    for(int i=0;i<v;i++)
    {
        for(auto x:adj[i])cout<<x<<" ";
        cout<<endl;
    }
}
int main()
{
    int v,e;
    cin>>v>>e;

    vector<int> adj[v];
    int a,b;

    //let it be undirected graph
    for(int i=0;i<e;i++)
    {
        cin>>a>>b;
        addEdge(adj,a,b);
    }

    printGraph(adj,v);

    return 0;
}