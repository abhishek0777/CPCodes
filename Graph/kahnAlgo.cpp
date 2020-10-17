/*
        Kahn's algorithm is for cycle detection.

        Algorithm :
            1. Apply topological sorting(since we know it work only for directed acyclic graph).
            2. But if a graph have cycle ,then there comes a certain point when,elements remains to process,but no one will have indegree =0
            At that time,while loop ends.
            3.Basically we will take a count variable which counts processed element.
            4. if count!=v.Then ther is a cycle
*/


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
    int count=0;
    queue<int> q;
    for(int i=0;i<v;i++)
    {
        if(indegree[i]==0)
        {
            q.push(i);
            count++;
        }
    }


    while(!q.empty())
    {
        int u=q.front();
        q.pop();  
        for(auto v:adj[u])
        {
            indegree[v]--;
            if(indegree[v]==0)q.push(v);
        }
        count++;
    }

    if(count!=v){cout<<"Yes,cyclic";}
    else {cout<<"No cycle";}
    
    
    return 0;
}