/*
    ----------------directed acyclic graph-----------
    Algorithm 
    1. Create an empty stack st
    2. For every vertex u,do following
        if(u is not visited)
            DFS(u,st,visited)
    3. while(st is not empty)
        pop an item from st and print it
*/
#include<bits/stdc++.h>
#include<stack>
using namespace std;

stack<int> st;

void addEdge(vector<int> adj[],int u,int v)
{
    adj[u].push_back(v);   
}

void DFS(int u,int visited[],vector<int> adj[])
{
    visited[u]=1;
    for(auto v:adj[u])
    {
        if(visited[v]==0)
        {
            DFS(v,visited,adj);
        }
    }
    st.push(u);
}


int main()
{
    int v,e;
    cin>>v>>e;
    vector<int> adj[v];

    int indegree[v];
    for(int i=0;i<v;i++)indegree[i]=0;

    for(int i=0;i<e;i++)
    {
        int a,b;
        cin>>a>>b;
        addEdge(adj,a,b);
    }

   /* 
        IMPORTANT : stack is initialized globally !
   */
   //topological sorting using DFS
   int visited[v];
   for(int i=0;i<v;i++)visited[i]=0;

   for(int u=0;u<v;u++)
   {
       if(visited[u]==0)
        {
            DFS(u,visited,adj);
        }
   }

    //print stack
    while(!st.empty())
    {
        cout<<st.top()<<" ";
        st.pop();
    }
    return 0;
}