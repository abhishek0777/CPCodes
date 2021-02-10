// Count elements which divide all numbers in range L-R
// Link : https://www.geeksforgeeks.org/count-elements-which-divide-all-numbers-in-range-l-r/
#include<bits/stdc++.h>
#define ll long long int
#define pii pair<ll,ll>
using namespace std;
struct triplet
{
    //first=minimum
    //second=count of minimum
    //third=gcd of range
    ll first=0,second=0,third=0;
};
vector<ll> a(100005);
vector<triplet> tree(400005);

/*
for this ques,if minimum of range ==gcd of range ,return count of minimum else return 0;

6 2
3 4 2 2 4 6
0 3
1 5

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

ll cstGCD(ll l,ll r,ll i)
{
    if(l==r)
    {
        tree[i].third=a[l];
        return tree[i].third;
    }
    ll m=(l+r)/2;
    tree[i].third=__gcd(cstGCD(l,m,2*i+1),cstGCD(m+1,r,2*i+2));
    return tree[i].third;
}

ll getCOUNT(ll ql,ll qr,ll l,ll r,ll i)
{
    if(r<ql||qr<l)
    return 0;
    if(ql<=l&&qr>=r)return tree[i].second;
    ll m=(l+r)/2;
    return getCOUNT(ql,qr,l,m,2*i+1)+getCOUNT(ql,qr,m+1,r,2*i+2);
}
ll getMIN(ll ql,ll qr,ll l,ll r,ll i)
{
    if(qr<l||r<ql)return INT_MAX;
    if(ql<=l&&qr>=r)return tree[i].first;
    ll m=(l+r)/2;
    return min(getMIN(ql,qr,l,m,2*i+1),getMIN(ql,qr,m+1,r,2*i+2));
}
ll getGCD(ll ql,ll qr,ll l,ll r,ll i)
{
    if(qr<l||ql>r)return 0;
    if(ql<=l&&qr>=r)return tree[i].third;
    ll m=(l+r)/2;
    return __gcd(getGCD(ql,qr,l,m,2*i+1),getGCD(ql,qr,m+1,r,2*i+2));
}

int main()
{
    ll n,q;cin>>n>>q;
    for(ll i=0;i<n;i++)cin>>a[i];
    cstMIN(0,n-1,0);
    cstCOUNT(0,n-1,0);
    cstGCD(0,n-1,0);
    while(q--)
    {
        ll l,r;cin>>l>>r;
        ll g=getGCD(l,r,0,n-1,0);
        ll mn=getMIN(l,r,0,n-1,0);
        if(g==mn)
        {
            cout<<getCOUNT(l,r,0,n-1,0)<<endl;
        }
        else
        cout<<"0"<<endl;
    }
}