#include<bits/stdc++.h>
#define ll long long int
#define pb push_back
#define inf INT_MAX
using namespace std;

ll V,E;

ll minDist(ll dist[],bool sptSET[])
{
    ll minD=INT_MAX,minI;
    for(ll i=0;i<V;i++)
    {
        if(sptSET[i]==false && dist[i]<minD)minD=dist[i],minI=i;
    }
    return minI;
}
int main()
{
    // ll V,E;
    cin>>V>>E;
    ll adj[V][V];
    for(ll i=0;i<V;i++)for(ll j=0;j<V;j++)adj[i][j]=0;
    for(ll i=0;i<E;i++)
    {
        ll u,v,w;cin>>u>>v>>w;
        adj[u][v]=w;
        adj[v][u]=w;
    }
    
    bool sptSET[V];
    memset(sptSET,false,sizeof(sptSET));
    ll dist[V];
    for(ll i=0;i<V;i++)dist[i]=inf;
    ll s;cin>>s;
    dist[s]=0;
    
    for(ll i=0;i<V-1;i++)
    {
        ll u=minDist(dist,sptSET);
        sptSET[u]=true;
        for(ll v=0;v<V;v++)
        {
            if(!sptSET[v] && adj[u][v]!=0 && dist[u]!=inf && dist[v]>dist[u]+adj[u][v])
            {
                dist[v]=dist[u]+adj[u][v];
            }
        }
    }
    
    for(ll i=0;i<V;i++)
    cout<<dist[i]<<" ";

    
}