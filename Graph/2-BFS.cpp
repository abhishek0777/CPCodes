/*
    BFS traversal of graph
*/
#include<bits/stdc++.h>
using namespace std;

void addEdge(vector<int> adj[],int u,int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}

//BFS of graph is unlike tree BFS(level order traversal)
// in graph there may be chance that we can traverse single 
//vertex twice.So to resolve this dilemma ,we will use visited array
// to manage the status 
void BFS(vector<int> adj[],int v,int s)
{
    int visited[v]={0};
    visited[s]=1;
    queue<int> q;
    q.push(s);
    while(!q.empty())
    {
        int u=q.front();
        q.pop();

        cout<<u<<" ";
        for(auto x:adj[u])
        {
            if(visited[x]==0)
            {
                visited[x]=1;
                q.push(x);
            }
        }
    }
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

    //BFS
    //0 is the source vertex from which BFS starts
    BFS(adj,v,0);

    return 0;
}