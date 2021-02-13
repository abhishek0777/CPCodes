#include<bits/stdc++.h>
#define ll long long int
//link:https://www.geeksforgeeks.org/minimum-length-subarray-sum-greater-given-value/
using namespace std;
int main()
{
    ll n,x;cin>>n>>x;
    ll a[n];
    for(ll i=0;i<n;i++)cin>>a[i];
    ll s=0,e=0,sum=0,len=INT_MAX;
    //initialize starting and ending indexes
    while(e<n)
    {
        //keep adding array elements while sum<=x
        while(sum<=x&&e<n)sum+=a[e++];
        //if sum>=x
        while(sum>x&&s<n)
        {
            //update min length
            if(e-s<len)len=e-s;
            sum-=a[s++];
        }
    }
    cout<<len;
}