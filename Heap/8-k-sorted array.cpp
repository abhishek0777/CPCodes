/*
Algo
1. Make min heap of first k+1 elements
2. Now pick top element one by one and also add new el in pq(min heap)
*/
#include<bits/stdc++.h>
#define ll long long int
using namespace std;
int main()
{
    ll n,k;cin>>n>>k;
    ll a[n];
    for(ll i=0;i<n;i++)cin>>a[i];
    priority_queue<ll,vector<ll>,greater<ll>> pq;
    for(ll i=0;i<=k;i++)
    pq.push(a[i]);
    ll idx=0;
    for(ll i=k+1;i<n;i++)
    {
        a[idx++]=pq.top();
        pq.pop();
        pq.push(a[i]);
    }
    while(!pq.empty())
    {
        a[idx++]=pq.top();
        pq.pop();
    }
    for(ll i=0;i<n;i++)cout<<a[i]<<" ";
}