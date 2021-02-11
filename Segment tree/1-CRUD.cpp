#include<bits/stdc++.h>
#define ll long long int
using namespace std;
vector<ll> stree(400000),a(100000);

/*
Test Input:
5 4
1 2 3 4 5
1 0 4
1 1 4
2 4 6
1 3 4
*/

ll cTree(ll l,ll r,ll i)
{
    if(l==r)
    {
        stree[i]=a[l];
        return stree[i];
    }
    ll m=(l+r)/2;
    stree[i]=cTree(l,m,2*i+1)+cTree(m+1,r,2*i+2);
    return stree[i];
}
ll getSum(ll ql,ll qr,ll l,ll r,ll i)
{
    if(qr<r||ql>r)return 0;
    if(ql<=l&&qr>=r)return stree[i];
    ll m=(l+r)/2;
    return getSum(ql,qr,l,m,2*i+1)+getSum(ql,qr,m+1,r,2*i+2);
}

void upd(ll l,ll r,ll si,ll i,ll val)
{
    if(l==r)
    {
        tree[si]=val;
        return;
    }
    ll m=(l+r)/2;
    if(i<=m)upd(l,m,2*si+1,i,val);
    else upd(m+1,r,2*si+2,i,val);
    tree[si]=tree[2*si+1]+tree[2*si+2];
}
int main()
{
    ll n,q;cin>>n>>q;
    for(ll i=0;i<n;i++)cin>>a[i];
    cTree(0,n-1,0);
    while(q--)
    {
        ll type;cin>>type;
        if(type==1)  //get sum
        {
            ll l,r;
            cin>>l>>r;
            cout<<getSum(l,r,0,n-1,0)<<endl;
        }
        else  //upd
        {
            ll i,val;cin>>i>>val;
            upd(0LL,n-1,0LL,i,val);
        }
    }
}