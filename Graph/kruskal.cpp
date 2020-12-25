
#include<bits/stdc++.h>
#define ll long long int
using namespace std;

ll parent[10000],rankk[10000];

bool mycmp(const pair<pair<ll,ll>,ll> &a,const pair<pair<ll,ll>,ll> &b)
{
    return a.second<b.second;
}

void initDSU()
{
    for(ll i=0;i<10000;i++){parent[i]=i;rankk[i]=0;}
}

ll findd(ll x)
{
    if(parent[x]==x)return x;
    return findd(parent[x]);
}

void unionn(ll x,ll y)
{
    ll x_rep=findd(x);
    ll y_rep=findd(y);
    if(rankk[x_rep]>rankk[y_rep]){
        parent[y_rep]=x_rep;
    }
    else if(rankk[x_rep]<rankk[y_rep]){
        parent[x_rep]=y_rep;
    }
    else{
        parent[y_rep]=x_rep;
        rankk[x_rep]++;
    }
}

int main()
{
    ll V,E;cin>>V>>E;
    // input in the form of s d w
    vector< pair< pair<ll,ll> ,ll> > edge(E);
    for(ll i=0;i<E;i++)
    {
        ll s,d,w;
        cin>>s>>d>>w;
        edge[i].first.first=s;
        edge[i].first.second=d;
        edge[i].second=w;
    }


    initDSU();
    sort(edge.begin(),edge.end(),mycmp);
    ll res=0;
    for(ll i=0,s=0;s<V-1;i++)
    {
        pair<pair<ll,ll>,ll> e=edge[i];
        ll x=findd(e.first.first);
        ll y=findd(e.first.second);
        if(x!=y)
        {
            res+=e.second;
            unionn(x,y);
            s++;
        } 
    }
    cout<<res;


}