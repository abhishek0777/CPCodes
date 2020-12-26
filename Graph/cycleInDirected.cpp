#include<bits/stdc++.h>
#define ll long long int
#define pb push_back
using namespace std;
ll V,E;
vector<bool> used;
vector<bool> recSt;

bool dfs(vector<ll> adj[],ll s)
{
    used[s]=true;
    recSt[s]=true;
    for(ll v:adj[s])
    {
        if( (!used[v])&&(dfs(adj,v)) )return true;
        else if(recSt[v])return true;
    }
    recSt[s]=false;
    return false;
}

bool detectCycle(vector<ll> adj[])
{
    used.assign(V,false);
    recSt.assign(V,false);
    for(ll i=0;i<V;i++)
    {
        if( (!used[i])&&(dfs(adj,i)) )return true;
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
    }
    
    if(detectCycle(adj))cout<<"Yes,cycle";
    else cout<<"No,cycle";
}