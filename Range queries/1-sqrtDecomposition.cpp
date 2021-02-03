/*
We have an array of n integers and for each query we have to find the sum of elements in the range of [l,r] inclusive.
I have already known to prefix sum problem which can answer in O(1),but sqrt decompositon has its own benefits.

For sqrt decomposition ,time complexity = O(sqrt(n)) for each query

https://cp-algorithms.com/data_structures/sqrt_decomposition.html

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