#include<bits/stdc++.h>
using namespace std;

void addEdge(vector<int> adj[],int u,int v)
{
    adj[u].push_back(v);
}

//main DFS recursive fun
bool DFSRec(vector<int> adj[],int s,int visited[],int recSt[])
{
    visited[s]=1;
    recSt[s]=1;
    for(auto x : adj[s])
    {
        if(visited[x]==0)
        {
            if(DFSRec(adj,x,visited,recSt)==true)
            {
                return true;
            }
        }
        else if(recSt[x]==1)
        {
                return true;
        }
    }
    recSt[s]=false;
    return false;
}

bool DFS(vector<int> adj[],int v)
{
    int visited[v];
    for(int i=0;i<v;i++)visited[i]=0;
    int recSt[v];
    for(int i=0;i<v;i++)recSt[i]=0;

    //this for loop is to manage disconnected graph
    for(int i=0;i<v;i++)
    {
        if(visited[i]==0)
        {
            if(DFSRec(adj,i,visited,recSt)==true)
            return true;
        }
        
    }
    return false;
    
    
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
    //print 1 if cycle else 0
    cout<<DFS(adj,v);
    

    return 0;
}