/*
arr[]={2,8,30,15,25,12}
ans[]={-1,-1,-1,30,25,15}
*/ 
#include <bits/stdc++.h>
#define ll long long int
using namespace std;

void naive(ll a[],ll n)
{
    cout<<"-1 ";
    for(ll i=1;i<n;i++)
    {
        ll diff=INT_MAX;
        for(ll j=0;j<i;j++)
        {
            if(a[j]>a[i])diff=min(diff,a[j]-a[i]);
        }
        if(diff==INT_MAX)cout<<"-1 ";
        else cout<<a[i]+diff<<" ";
    }
    
}
void efficient(ll a[],ll n)
{
    set<ll> uni;
    cout<<"-1 ";
    uni.insert(a[0]);
    for(ll i=1;i<n;i++)
    {
        auto j=uni.lower_bound(a[i]);
        if(j!=uni.end())
        cout<<*j<<" ";
        else cout<<"-1 ";
        uni.insert(a[i]);
    }
}
int main()
{
    ll n;cin>>n;
    ll a[n];
    for(ll i=0;i<n;i++)cin>>a[i];
    
    naive(a,n);
}