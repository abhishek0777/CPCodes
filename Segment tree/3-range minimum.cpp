#include<bits/stdc++.h>
#define ll long long int
using namespace std;
vector<ll> a(100005),tree(400005);

/*
6 4
1 3 2 7 9 11
0 1
1 2
2 5
3 5
*/

ll cstMIN(ll l,ll r,ll i)
{
    if(l==r)
    {
        tree[i]=a[l];
        return tree[i];
    }
    ll m=(l+r)/2;
    tree[i]=min(cstMIN(l,m,2*i+1),cstMIN(m+1,r,2*i+2));
    return tree[i];
}
ll getMIN(ll ql,ll qr,ll l,ll r,ll i)
{
    if(r<ql||qr<l)
    return INT_MAX;
    if(ql<=l&&qr>=r)return tree[i];
    ll m=(l+r)/2;
    return min(getMIN(ql,qr,l,m,2*i+1),getMIN(ql,qr,m+1,r,2*i+2));
}

int main()
{
    ll n,q;cin>>n>>q;
    for(ll i=0;i<n;i++)cin>>a[i];
    cstMIN(0,n-1,0);
    while(q--)
    {
        ll l,r;cin>>l>>r;
        cout<<getMIN(l,r,0,n-1,0)<<endl;
    }
}