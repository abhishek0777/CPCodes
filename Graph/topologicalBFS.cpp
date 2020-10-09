/*
    Topological Sorting -BFS 
    Algorithm : 
    1. Store indegree of every vertex
    2. Create a queue ,q
    3. Add all 0 indegree vertices to q
    4.  while(q is not empty)
            a. u=q.front();
            b. q.pop();
            c. for(every adj v of u)
                    i. reduce indegree by 1
                    ii. if indegree of v==0
                            push it into q
        //while loop ends here
*/

#include<bits/stdc++.h>
using namespace std;

void addEdge(vector<int> adj[],int u,int v,int indegree[])
{
    adj[u].push_back(v);
    indegree[v]++;    
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
        addEdge(adj,a,b,indegree);
    }

    //Topological sorting
    queue<int> q;
    for(int i=0;i<v;i++)
    {
        if(indegree[i]==0)q.push(i);
    }

    while(!q.empty())
    {
        int u=q.front();
        q.pop();  
        cout<<u<<" ";
        for(auto v:adj[u])
        {
            indegree[v]--;
            if(indegree[v]==0)q.push(v);
        }
    }
    
    
    return 0;
}