/*
if along with the query to find sum of elements in the range of [l,r],
there is to update a[i]old= a[i]new
then we can simply update b[k]+=a[i]new-a[i]old ,where k=block number in which i belongs
queries are:
1 i a[i]
2 l r
*/
#include<bits/stdc++.h>
#define ll long long int
using namespace std;

int main()
{
    ll n,q;cin>>n>>q;
    ll a[n];
    for(ll i=0;i<n;i++)cin>>a[i];
    ll len=sqrt(n)+1;
    vector<ll> b(len,0);
    for(ll i=0;i<n;i++)b[i/len]+=a[i];
    while(q--)
    {
        ll type;cin>>type;
        if(type==1)
        {
            ll i,ai;cin>>i>>ai;
            b[i/len]+=(ai-a[i]);
            a[i]=ai;
        }
        else
        {
            ll l,r;cin>>l>>r;
            ll ans=0;
            ll l_block=l/len;
            ll r_block=r/len;
            if(l_block==r_block)
            {
                for(ll i=l;i<=r;i++)ans+=a[i];
                cout<<ans<<endl;
                continue;
            }
            for(ll i=l;i<=(l_block+1)*len-1;i++)ans+=a[i];
            for(ll i=l_block+1;i<r_block;i++)ans+=b[i];
            for(ll i=r_block*len;i<=r;i++)ans+=a[i];
            cout<<ans<<endl;
        }
    }
    
    
}