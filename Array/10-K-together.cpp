#include<bits/stdc++.h>
#define ll long long int
using namespace std;

// Minimum swaps required to bring all elements less than or equal to k together

//We can solve it using sliding window technique,
//first count elements <=k and maintain count of bad elements which we'll be the ans of that window 
int main()
{
    ll n,k;cin>>n>>k;
    ll a[n],cnt=0;
    for(ll i=0;i<n;i++)
    {
        cin>>a[i];
        if(a[i]<=k)cnt++;
    }
    //1st window
    ll bad=0;
    for(ll i=0;i<k;i++)
    {
        if(a[i]>k)bad++;
    }
    ll ans=bad;
    for(ll i=k;i<n-cnt;i++)
    {
        if(a[i-k]>k)bad--;
        if(a[i]>k)bad++;
        ans=min(ans,bad);
    }
    cout<<ans;
}