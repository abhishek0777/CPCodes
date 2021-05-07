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
#define ll long long int
#define pb push_back
#define inf INT_MAX
#define pii pair<ll,ll>
#define mp make_pair
using namespace std;
ll V,E;
vector<ll> dist;
vector<ll> indeg;
void topo(vector<pii> adj[])
{
    dist.assign(V,inf);
    dist[0]=0;
    queue<ll> q;
    for(ll i=0;(i<V)&&(indeg[i]==0);i++)q.push(i);
    while(!q.empty())
    {
        ll u=q.front();
        q.pop();
        // shortest path
        for(pii edge:adj[u])
        {
            ll v=edge.first;
            ll w=edge.second;
            if(dist[v]>dist[u]+w)
            dist[v]=dist[u]+w;
            
            indeg[v]--;
            if(indeg[v]==0)q.push(v);
        }
    }
    for(ll i=0;i<V;i++)cout<<dist[i]<<" ";
    
}
int main()
{
    cin>>V>>E;
    vector<pair<ll,ll>> adj[V];
    indeg.assign(V,0);
    for(ll i=0;i<E;i++)
    {
        ll u,v,w;cin>>u>>v>>w;
        adj[u].pb(mp(v,w));
        indeg[v]++;
    }
    topo(adj);
}