#include<bits/stdc++.h>
#define ll long long int
using namespace std;
//Search an element in a sorted and rotated array
ll binSearch(ll a[],ll l,ll r,ll key)
{
    ll m=(l+r)/2;
    if(a[m]==key)return m;
    else if(a[m]>=a[l]) //check l to m is sorted
    {
        if(key<=a[m]&&key>=a[l])return binSearch(a,l,m-1,key);
        return binSearch(a,m+1,r,key);
    }
    else
    {
        if(key>=a[m]&&key<=a[r])return binSearch(a,m+1,r,key);
        return binSearch(a,l,m-1,key);
    }
    
}

int main()
{
    ll n,key;cin>>n>>key;
    ll a[n];
    for(ll i=0;i<n;i++)cin>>a[i];
    cout<<binSearch(a,0,n-1,key);
}