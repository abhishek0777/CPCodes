#include<bits/stdc++.h>
#define ll long long int
using namespace std;
vector<ll> a(100005),tree(400005);

/*
5 3
2 3 60 90 50
1 3
2 4
0 2
*/

ll cstGCD(ll l,ll r,ll i)
{
    if(l==r)
    {
        tree[i]=a[l];
        return tree[i];
    }
    ll m=(l+r)/2;
    tree[i]=__gcd(cstGCD(l,m,2*i+1),cstGCD(m+1,r,2*i+2));
}
ll getGCD(ll ql,ll qr,ll l,ll r,ll i)
{
    if(l>qr||r<ql)return 0;
    if(ql<=l&&qr>=r)return tree[i];
    ll m=(l+r)/2;
    return __gcd(getGCD(ql,qr,l,m,2*i+1),getGCD(ql,qr,m+1,r,2*i+2));
}
int main()
{
    ll n,q;cin>>n>>q;
    for(ll i=0;i<n;i++)cin>>a[i];
    cstGCD(0,n-1,0);
    while(q--)
    {
        ll l,r;cin>>l>>r;
        cout<<getGCD(l,r,0,n-1,0)<<endl;
    }
}