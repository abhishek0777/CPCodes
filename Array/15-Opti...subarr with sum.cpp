#include<bits/stdc++.h>
#define ll long long int
using namespace std;

/*
Link: https://www.geeksforgeeks.org/find-subarray-with-given-sum/
Given an array of non-negative integers,we have to find ,if there is an subarray whose sum of elements is equal to x.
An approach similar to sliding window can be used,since all elements are positive,if sum is exceeding x,then there is no option to increase its length,so we remove starting element of that subarray.
*/

int main()
{
    ll n,x;cin>>n>>x;
    ll a[n];
    for(ll i=0;i<n;i++)cin>>a[i];
    ll l=0,sum=0;
    bool have=false;
    for(ll i=0;i<n;i++)
    {
        sum+=a[i];
        if(sum>x)
        sum-=a[l],l++;
        if(sum==x)
        {
            have=true;
            break;
        }
    }
    cout<<(have?"YES":"NO");
}