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
#define inf INT_MAX
#define pii pair<ll,ll>
using namespace std;

ll V,E;
void addEdge(vector<pair<ll,ll>> adj[],ll s,ll d,ll w)
{
    adj[s].pb(mp(d,w));
    adj[d].pb(mp(s,w));
}

void Dijkstra(vector<pii> adj[],ll s)
{
    ll d[V];
    for(ll i=0;i<V;i++)d[i]=inf;
    d[s]=0;
    priority_queue<pii,vector<pii>,greater<pii>> pq;
    pq.push(mp(0,s));
    
    while(!pq.empty())
    {
        int u=pq.top().second;
        int d_u=pq.top().first;
        pq.pop();
        if(d_u!=d[u])continue;
        
        for(pii edge:adj[u])
        {
            ll to=edge.first;
            ll len=edge.second;
            if(d[to]>d[u]+len)
            {
                d[to]=d[u]+len;
                pq.push(mp(d[to],to));
            }
        }
    }
    
    
    for(ll i=0;i<V;i++)cout<<d[i]<<" ";
    
}
int main()
{
    cin>>V>>E;
    vector<pair<ll,ll>> adj[V];
    for(ll i=0;i<E;i++)
    {
        ll s,d,w;
        cin>>s>>d>>w;
        addEdge(adj,s,d,w);
    }
    
    ll s;cin>>s;
    Dijkstra(adj,s);
}