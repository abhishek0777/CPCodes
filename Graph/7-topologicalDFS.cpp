#include<bits/stdc++.h>
#define ll long long int
#define pb push_back
using namespace std;
ll V,E;
stack<ll> tsort;
vector<bool> used;

void dfs(vector<ll> adj[],ll s)
{
    used[s]=true;
    for(ll v:adj[s])
    {
        if(!used[v])dfs(adj,v);
    }
    tsort.push(s);
}

void topo(vector<ll> adj[])
{
    used.assign(V,false);
    for(ll i=0;i<V;i++)
    {
        if(!used[i])dfs(adj,i);
    }
    while(!tsort.empty())
    {
        cout<<tsort.top()<<" ";
        tsort.pop();
    }
}
int main()
{
    cin>>V>>E;
    vector<ll> adj[V];
    for(ll i=0;i<E;i++)
    {
        ll u,v;cin>>u>>v;
        adj[u].pb(v);
    }
    topo(adj);
}