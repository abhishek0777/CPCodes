#include<bits/stdc++.h>
#define ll long long int
#define pii pair<ll,ll>
using namespace std;
vector<ll> a(100005);
vector<set<ll>> tree(400005);
/*
Find the number of distinct elements in given range
test input:
5 1
1 1 2 1 3
0 3
*/
void cst(ll l,ll r,ll i)
{
    if(l==r)
    {
        tree[i].insert(a[l]);
        return;
    }
    ll m=(l+r)/2;
    cst(l,m,2*i+1);
    cst(m+1,r,2*i+2);
    tree[i].insert(tree[2*i+1].begin(),tree[2*i+1].end());
    tree[i].insert(tree[2*i+2].begin(),tree[2*i+2].end());
}
set<ll> getdistinct(ll ql,ll qr,ll l,ll r,ll i)
{
    set<ll> left,right,result;
    if(ql>r||qr<l)
    return result;
    if(ql<=l&&qr>=r)return tree[i];
    ll m=(l+r)/2;
    left=getdistinct(ql,qr,l,m,2*i+1);
    result.insert(left.begin(),left.end());
    right=getdistinct(ql,qr,m+1,r,2*i+2);
    result.insert(right.begin(),right.end());
    return result;
}

int main()
{
    ll n,q;cin>>n>>q;
    for(ll i=0;i<n;i++)cin>>a[i];
    cst(0,n-1,0);
    while(q--)
    {
        ll l,r;cin>>l>>r;
        cout<<getdistinct(l,r,0,n-1,0).size()<<endl;
    }
}