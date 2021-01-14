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
set<ll> points;

void IS_AP(ll ap)
{
    if(points.find(ap)==points.end())
    {
        points.insert(ap);
        cout<<ap<<endl;
    }
    
}


void dfs(vector<ll> adj[],ll v,ll p)
{
    used[v]=true;
    disc[v]=low[v]=timer++;
    //lets define no of children this (v) node going to have
    ll childrens=0;
    
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
            // we are excluding root node here bcz we'll check for root node as a different case
            if((low[to]>=disc[v])&&(p!=-1))
            {
                IS_AP(v);
            }
            childrens++;
        }
    }
    
    // when root node is an AP;
    if(p==-1 && childrens>1)
    IS_AP(v);
}


void articulationPoint(vector<ll> adj[])
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
    articulationPoint(adj);
}