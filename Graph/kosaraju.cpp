/*
    Kosaraju's algorithm to find strongly connected components
*/
#include<bits/stdc++.h>
#define ll long long int
#define pb push_back
#define mp make_pair
#define inf INT_MAX

using namespace std;
vector<ll> adj[10000],radj[10000];
ll V,E;
vector<bool> visited;
vector<ll> order,component;


void dfs1(ll s)
{
    visited[s]=true;
    for(ll v:adj[s])if(!visited[v])dfs1(v);
    order.pb(s);
}

void dfs2(ll s)
{
    visited[s]=true;
    component.pb(s);
    for(ll v:radj[s])if(!visited[v])dfs2(v);
}
int main()
{
    cin>>V>>E;
    for(ll i=0;i<E;i++)
    {
        ll u,v;cin>>u>>v;
        adj[u].pb(v);
        radj[v].pb(u);
    }
    
    visited.assign(V,false);
    for(ll i=0;i<V;i++)
    {
        if(!visited[i])dfs1(i);
    }
    visited.assign(V,false);
    for(ll i=0;i<V;i++)
    {
        ll o=order[V-1-i];
        if(!visited[o])
        {
            dfs2(o);
            for(ll j=0;j<component.size();j++)cout<<component[j]<<" ";
            cout<<"\n";
            component.clear();
        }
    }
    
}
