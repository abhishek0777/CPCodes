#include<bits/stdc++.h>
#define ll long long int
#define pii pair<ll,ll>
using namespace std;
vector<ll> a(100005);
vector<pii> tree(400005,{0,0});

/*
Count number of elements which are minimum in given range
6 3
3 4 2 2 2 2
0 2
1 3
3 5
*/

ll cstMIN(ll l,ll r,ll i)
{
    if(l==r)
    {
        tree[i].first=a[l];
        return tree[i].first;
    }
    ll m=(l+r)/2;
    tree[i].first=min(cstMIN(l,m,2*i+1),cstMIN(m+1,r,2*i+2));
    return tree[i].first;
}
ll cstCOUNT(ll l,ll r,ll i)
{
    if(l==r)
    {
        tree[i].second=1;
        return tree[i].second;
    }
    ll m=(l+r)/2;
    if(tree[2*i+1].first<tree[2*i+2].first)
    {
        tree[i].second+=cstCOUNT(l,m,2*i+1);
    }
    else if(tree[2*i+1].first>tree[2*i+2].first)
    {
        tree[i].second+=cstCOUNT(m+1,r,2*i+2);
    }
    else
    {
        tree[i].second+=(cstCOUNT(l,m,2*i+1)+cstCOUNT(m+1,r,2*i+2));
    }
    return tree[i].second;
    
}
ll getCOUNT(ll ql,ll qr,ll l,ll r,ll i)
{
    if(r<ql||qr<l)
    return 0;
    if(ql<=l&&qr>=r)return tree[i].second;
    ll m=(l+r)/2;
    return getCOUNT(ql,qr,l,m,2*i+1)+getCOUNT(ql,qr,m+1,r,2*i+2);
}

int main()
{
    ll n,q;cin>>n>>q;
    for(ll i=0;i<n;i++)cin>>a[i];
    cstMIN(0,n-1,0);
    cstCOUNT(0,n-1,0);
    while(q--)
    {
        ll l,r;cin>>l>>r;
        cout<<getCOUNT(l,r,0,n-1,0)<<endl;
    }
}