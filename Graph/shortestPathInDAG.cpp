// Shortest Path in DAG 
//  Algorithm :
//      (i) Initialize dist[v]={inf,inf,.....}
//     (ii) dist[s]=0;
//    (iii) Find a topological sort of graph
//     (iv) For every vertex u in the topological sort
//      (v)        For every adjacent v of u
//                     if dist[v]>dist[u]+weight[u][v]
//                            dist[v]=dist[u]+weight[u][v]

#include<bits/stdc++.h>
using namespace std;

void addEdge(vector<int> adj[],int u,int v,int indegree[])
{
    adj[u].push_back(v);
    indegree[v]++;
}
int main()
{
    int v,e;cin>>v>>e;
    vector<int> adj[v];

    int dist[v];
    for(int i=0;i<v;i++)dist[i]=10000; //treat 10000 as infinite
    dist[0]=0;
    int indegree[v];
    for(int i=0;i<v;i++)indegree[i]=0;

    int weight[v][v];

    for(int i=0;i<e;i++)
    {
        int u,v;cin>>u>>v;
        cin>>weight[u][v];
        addEdge(adj,u,v,indegree);
    }

    queue<int> q;
    for(int i=0;i<v;i++)
    {
        if(indegree[i]==0)q.push(i);
    }

    while(!q.empty())
    {
        int u=q.front();
        q.pop();


        // here comes shortest path
        for(auto v:adj[u])
        {
            if(dist[v]>dist[u]+weight[u][v]){
                dist[v]=dist[u]+weight[u][v];
            }
        }



        for(auto v:adj[u])
        {
            indegree[v]--;
            if(indegree[v]==0)q.push(v);
        }
    }


    for(auto d:dist)
    {
        cout<<d<<" ";
    }
}