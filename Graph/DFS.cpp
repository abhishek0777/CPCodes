/*
    DFS is not unique,it depend on how we are picking adjacent of vertex
*/
#include<bits/stdc++.h>
using namespace std;

void addEdge(vector<int> adj[],int u,int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}

//main DFS recursive fun
void DFSRec(vector<int> adj[],int s,int visited[])
{
    visited[s]=1;
    cout<<s<<" ";
    for(auto x : adj[s])
    {
        if(visited[x]==0)
        {
            DFSRec(adj,x,visited);
        }
    }
}

void DFS(vector<int> adj[],int v,int s)
{
    int visited[v]={0};

    int c=0; //c=number of connected graphs
    //this for loop is to manage disconnected graph
    for(int i=0;i<v;i++)
    {
        if(visited[i]==0)
        {
            DFSRec(adj,i,visited);
        }
        c++;
    }
    cout<<"count="<<c;
    
}

int main()
{
    int v,e;
    cin>>v>>e;
    vector<int> adj[v];

    for(int i=0;i<e;i++)
    {
        int a,b;
        cin>>a>>b;
        addEdge(adj,a,b);
    }

    //DFS
    //0 is the source vertex from which BFS starts
    DFS(adj,v,0);

    return 0;
}