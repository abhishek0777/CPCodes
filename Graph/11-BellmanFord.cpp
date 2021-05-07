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
vector<ll> dist;

void bellman(vector<pii> adj[],ll s)
{
    dist.assign(v,inf);
    dist[s]=0;
    for(ll count=0;count<v-1;count++)
    {
        for(ll i=0;i<v;i++)
        {
            for(pii edge:adj[i])
            {
                ll v=edge.first;
                ll len=edge.second;
                if(dist[i]!=inf)
                {
                    if(dist[v]>dist[i]+len)dist[v]=dist[i]+len;
                }
            }
        }
    }
    for(ll d:dist)cout<<d<<" ";
}

int main() {
    FAST
    cin>>v>>e;
    vector<pii> adj[v];
    for(ll i=0;i<e;i++)
    {
        ll u,v,w;cin>>u>>v>>w;
        adj[u].pb(mp(v,w));
    }
    ll s;cin>>s;
    bellman(adj,s);
    
	return 0;
}