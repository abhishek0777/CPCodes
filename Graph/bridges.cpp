/*
Input test case:
5 5
0 1
0 2
2 3
3 4
1 2
*/
#include<bits/stdc++.h>
#include<algorithm>
#define ll long long int
#define pii pair<ll,ll>
#define pb push_back
#define mp make_pair
#define FAST ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;
 
#define pb push_back
#define mp make_pair
 
#define MOD 1000000007
#define inf INT_MAX
ll v,e;
ll timer;
//discovery time and low value
vector<ll> disc,low;
vector<bool> used;
set<pii> bridge;

void IS_BRIDGE(ll a,ll b)
{
    if(bridge.find(mp(a,b))==bridge.end())
    {
        bridge.insert(mp(a,b));
        cout<<a<<" "<<b<<endl;
    }
}


void dfs(vector<ll> adj[],ll v,ll p)
{
    used[v]=true;
    disc[v]=low[v]=timer++;
    
    // now standard dfs
    for(ll to:adj[v])
    {
        if(to==p)continue;
        if(used[to])
        {
            low[v]=min(low[v],disc[to]);
        }
        else
        {
            dfs(adj,to,v);
            low[v]=min(low[v],low[to]);
            if(low[to]>disc[v])
            {
                IS_BRIDGE(v,to);
            }
        }
    }
}


void findBridges(vector<ll> adj[])
{
    disc.assign(v,-1);
    low.assign(v,-1);
    used.assign(v,false);
    timer=0;
    for(ll i=0;i<v;i++)
    {
        if(!used[i])dfs(adj,i,-1);
    }
}

int main()
{
    cin>>v>>e;
    vector<ll> adj[v];
    for(ll i=0;i<e;i++)
    {
        ll x,y;cin>>x>>y;
        adj[x].pb(y);
        adj[y].pb(x);
    }
    findBridges(adj);
}