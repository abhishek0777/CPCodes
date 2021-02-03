/*
add query function
and output value at given index
*/
#include<bits/stdc++.h>
#define ll long long int
using namespace std;
int main()
{
    ll n,q;cin>>n>>q;
    ll a[n];
    ll len=sqrt(n)+1;
    vector<ll> b(len,0);
    for(ll i=0;i<n;i++)cin>>a[i];
    while(q--)
    {
        ll type;cin>>type;
        //type=1 for add query ,TC = O(sqrt(n)
        if(type==1)
        {
            ll l,r,add;cin>>l>>r>>add;
            ll lblock=l/len;
            ll rblock=r/len;
            if(lblock==rblock)
            {
                for(ll i=l;i<=r;i++)a[i]+=add;
            }
            else
            {
                for(ll i=l;i<(lblock+1)*len;i++)a[i]+=add;
                for(ll i=lblock+1;i<rblock;i++)b[i]+=add;
                for(ll i=rblock*len;i<=r;i++)a[i]+=add;
            }
            
        }
        else
        {
            ll i;cin>>i;
            cout<<a[i]+b[i/len]<<endl;
        }
    }
}