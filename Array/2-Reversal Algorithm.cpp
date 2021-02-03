#include<bits/stdc++.h>
#define ll long long int
using namespace std;

// Time complexity : O(n)
void rotate(ll a[],ll n,ll d)
{
    reverse(a,a+d);
    reverse(a+d,a+n);
    reverse(a,a+n);
}
int main()
{
    ll n,d;cin>>n>>d;    
    ll a[n];
    for(ll i=0;i<n;i++)cin>>a[i];
    rotate(a,n,d);
    for(ll i=0;i<n;i++)cout<<a[i]<<" ";
}