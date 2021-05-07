/*
input:
5 5
0 2
2 3
0 3
1 3
1 4
*/
#include<bits/stdc++.h>
#define ll long long int
#define pb push_back
using namespace std;
ll V,E;
vector<ll> tsort;
vector<ll> indeg;
void topo(vector<ll> adj[])
{
    queue<ll> q;
    for(ll i=0;(i<V)&&(indeg[i]==0);i++)q.push(i);
    while(!q.empty())
    {
        ll u=q.front();
        q.pop();
        tsort.pb(u);
        for(ll v:adj[u])
        {
            indeg[v]--;
            if(indeg[v]==0)q.push(v);
        }
    }
    for(ll x:tsort)cout<<x<<" ";
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
    topo(adj);
}