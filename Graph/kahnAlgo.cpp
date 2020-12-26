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
#define ll long long int
#define pb push_back
using namespace std;
ll V,E;
vector<ll> indeg;
ll cnt;
bool topo(vector<ll> adj[])
{
    queue<ll> q;
    for(ll i=0;(i<V)&&(indeg[i]==0);i++)q.push(i);
    while(!q.empty())
    {
        ll u=q.front();
        q.pop();
        cnt++;
        for(ll v:adj[u])
        {
            indeg[v]--;
            if(indeg[v]==0)q.push(v);
        }
    }
    return V!=cnt;
}
int main()
{
    cin>>V>>E;
    vector<ll> adj[V];
    indeg.assign(V,0);
    for(ll i=0;i<E;i++)
    {
        ll u,v;cin>>u>>v;
        adj[u].pb(v);
        indeg[v]++;
    }
    if(topo(adj))cout<<"Yes,cycle";
    else cout<<"No,cycle";
}