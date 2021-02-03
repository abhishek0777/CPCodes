/*
queries to (i) find minimum element from subarray
          (ii) update element of array
*/
#include<bits/stdc++.h>
#define ll long long int
using namespace std;
int main()
{
    ll n,q;cin>>n>>q;
    ll a[n];
    ll len=sqrt(n)+1;
    vector<ll> b(len,INT_MAX);
    for(ll i=0;i<n;i++)
    {
        cin>>a[i];
        b[i/len]=min(b[i/len],a[i]);
    }
    while(q--)
    {
        ll type;
        cin>>type;
        if(type==1)
        {
            ll i,ai;cin>>i>>ai;
            //updation requires O(sqrt(n)) time
            ll block_num=i/len;
            a[i]=ai;
            b[block_num]=INT_MAX;
            for(ll j=block_num*len;j<(block_num+1)*len;j++)
            {
                b[block_num]=min(b[block_num],a[j]);
            }
        }
        else
        {
            ll l,r;cin>>l>>r;
            ll lblock=l/len;
            ll rblock=r/len;
            ll ans=INT_MAX;
            if(lblock==rblock)
            {
                for(ll i=l;i<=r;i++)ans=min(ans,a[i]);
            }
            else
            {
                for(ll i=l;i<(lblock+1)*len;i++)ans=min(ans,a[i]);
                for(ll i=lblock+1;i<rblock;i++)ans=min(ans,b[i]);
                for(ll i=rblock*len;i<r;i++)ans=min(ans,a[i]);
            }
            cout<<ans<<endl;
        }
    }
    
}