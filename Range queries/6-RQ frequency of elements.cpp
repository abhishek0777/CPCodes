#include<bits/stdc++.h>
#define ll long long int
using namespace std;
int main()
{
    ll n,m;cin>>n>>m;
    ll a[n];
    ll len=sqrt(n)+1;
    vector<map<ll,ll>> b(n);
    for(ll i=0;i<n;i++)
    {
        cin>>a[i];
        b[i/len][a[i]]++;
    }
    ll freq=0;
    while(m--)
    {
        ll l,r,x;cin>>l>>r>>x;
        l--,r--;
        freq=0;
        ll lblock=l/len;
        ll rblock=r/len;
        if(lblock==rblock)
        {
            for(ll i=l;i<=r;i++)if(a[i]==x)freq++;
            cout<<freq<<endl;
        }
        else
        {
            for(ll i=l;i<(lblock+1)*len;i++)if(a[i]==x)freq++;
            for(ll i=lblock+1;i<rblock;i++)freq+=b[i][x];
            for(ll i=rblock*len;i<=r;i++)if(a[i]==x)freq++;
            
            cout<<freq<<endl;
        }
        
    }   
}