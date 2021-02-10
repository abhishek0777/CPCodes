#include<bits/stdc++.h>
#define ll long long int
using namespace std;
/*
link: https://www.geeksforgeeks.org/queries-for-decimal-values-of-subarray-of-a-binary-array/
test Input:
6 4
1 0 1 0 1 1
0 5
2 5
4 5
1 4
*/
int main()
{
    ll n,q;cin>>n>>q;
    ll a[n+1]={0};
    for(ll i=0;i<n;i++)
    {
        cin>>a[i];
        a[i]*=(1LL<<(n-1-i));
    }
    for(ll i=n-1;i>=0;i--)
    {
        a[i]+=a[i+1];
    }
    while(q--)
    {
        // l & r 0-based indexing
        ll l,r;cin>>l>>r;
        cout<<(a[l]-a[r+1])/(1LL<<(n-1-r))<<endl;
        
    }
}