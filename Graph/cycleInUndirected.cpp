#include<bits/stdc++.h>
#define ll long long int
#define pb push_back
using namespace std;
ll V,E;

bool dfs(vector<ll> adj[],bool visited[],ll s,ll p)
{
    visited[s]=true;
    for(ll v: adj[s])
    {
        if((!visited[v])&&(dfs(adj,visited,v,s)))return true;
        else if(v!=p)return true;
    }
    return false;
}

bool detectCycle(vector<ll> adj[])
{
    bool visited[V];
    memset(visited,false,sizeof(visited));
    for(ll i=0;i<V;i++)
    {
        if(!visited[i])
        {
            if(dfs(adj,visited,i,-1))return true;
        }
    }
    return false;
}
int main()
{
    cin>>V>>E;
    vector<ll> adj[V];
    for(ll i=0;i<E;i++)
    {
        ll u,v;cin>>u>>v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    if(detectCycle(adj))cout<<"Yes,cycle";
    else cout<<"No,cycle";
}