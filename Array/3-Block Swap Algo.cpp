#include<bits/stdc++.h>
#define ll long long int
using namespace std;
//blog : https://www.geeksforgeeks.org/block-swap-algorithm-for-array-rotation/
//Block swap algorithm
// Time complexity : O(n)
void swap(ll a[],ll fi,ll si,ll len)
{
    for(ll i=0;i<len;i++)
    {
        swap(a[fi+i],a[si+i]);
    }
}
void rotate(ll a[],ll n,ll d)
{
    if(d%n==0)return;
    // i and j are lengths of A and B
    ll i=d,j=n-d;
    while(i!=j)
    {
        if(i>j)
        {
            swap(a,d-i,d,j);
            i-=j;
        }
        else
        {
            swap(a,d-i,d+j-i,i);
            j-=i;
        }
    }
    swap(a,d-i,i,i);
}
int main()
{
    ll n,d;cin>>n>>d;    
    ll a[n];
    for(ll i=0;i<n;i++)cin>>a[i];
    rotate(a,n,d);
    for(ll i=0;i<n;i++)cout<<a[i]<<" ";
}