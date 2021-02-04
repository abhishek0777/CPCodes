// https://www.geeksforgeeks.org/rearrange-positive-and-negative-numbers-publish/

#include<bits/stdc++.h>
#define ll long long int
using namespace std;
int main()
{
    ll n;cin>>n;
    ll a[n];
    for(ll i=0;i<n;i++)cin>>a[i];
    
    //first we will separate negative and positive integers
    //so as we do partitioning in quicksort,we do same using pivot as 0
    ll i=-1;
    ll j=0;
    while(j<n)
    {
        if(a[j]<0)
        {
            i++;
            swap(a[i],a[j]);
        }
        j++;
    }
    
    //now to make positive and negative alternative,
    // we will move pointer of negative numbers indexes by and positive by 1
    ll posi=i+1;ll negi=0;
    while(posi<n&&negi<n&&a[negi]<0)
    {
        swap(a[posi],a[negi]);
        negi+=2;
        posi+=1;
    }
    
    for(ll i=0;i<n;i++)cout<<a[i]<<" ";
    
    
    
}