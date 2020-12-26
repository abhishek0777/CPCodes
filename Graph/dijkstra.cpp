/*
    Based on priority queue
    sample input
    9 14
    0 1 4
    0 7 8
    1 7 11
    1 2 8
    7 8 7
    7 6 1
    2 8 2
    8 6 6
    2 3 7
    2 5 4
    6 5 2
    3 5 14
    3 4 9
    5 4 10
    0
*/
#include<bits/stdc++.h>
#define ll long long int
#define pb push_back
#define mp make_pair
#define pii pair<ll,ll>
#define inf INT_MAX
using namespace std;
ll V,E;

void dijkstra(vector<pii> adj[],ll s)
{
    vector<ll> dist;
    dist.assign(V,inf);
    dist[s]=0;
    // min heap
    priority_queue<pii,vector<pii>,greater<pii>> pq;
    pq.push({0,s});
    while(!pq.empty())
    {
        ll d_u=pq.top().first;
        ll from=pq.top().second;
        pq.pop();
        if(dist[from]!=d_u)continue;
        for(pii edge:adj[from])
        {
            ll to=edge.first;
            ll len=edge.second;
            if(dist[to]>dist[from]+len)
            {
                dist[to]=dist[from]+len;
                pq.push(mp(dist[to],to));
            }
        }
    }
    for(ll d:dist)cout<<d<<" ";
}
int main()
{
    cin>>V>>E;
    vector<pii> adj[V];
    for(ll i=0;i<E;i++)
    {
        ll s,d,w;cin>>s>>d>>w;
        adj[s].pb(mp(d,w));
        adj[d].pb(mp(s,w));
    }
    // ll s;cin>>s;
    dijkstra(adj,0);
}