#include<bits/stdc++.h>
#define ll long long int
using namespace std;
//https://www.geeksforgeeks.org/reorder-a-array-according-to-given-indexes/
//Do is O(1) auxilary space
int main()
{
    ll n;cin>>n;
    ll a[n];
    for(ll i=0;i<n;i++)cin>>a[i];
    ll idx[n];
    for(ll i=0;i<n;i++)cin>>idx[i];
    for(ll i=0;i<n;i++){
        while(idx[i]!=i)
        {
            ll olde=a[idx[i]];
            ll oldi=idx[idx[i]];
            a[idx[i]]=a[i];
            idx[idx[i]]=idx[i];
            a[i]=olde;
            idx[i]=oldi;
        }
    }
    for(ll i=0;i<n;i++)cout<<a[i]<<" ";
    cout<<"\n";
    for(ll i=0;i<n;i++)cout<<idx[i]<<" ";
    
}