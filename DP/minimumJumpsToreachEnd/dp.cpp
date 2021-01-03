#include<bits/stdc++.h>
#define ll long long int
#define pb push_back
#define mp make_pair
#define inf INT_MAX
#define pii pair<ll,ll>

using namespace std;

ll minJumps(ll a[],ll n)
{
    int dp[n];
    dp[0]=0;
    for(ll i=1;i<n;i++)dp[i]=INT_MAX;
    for(ll i=1;i<n;i++)
    {
        for(ll j=0;j<i;j++)
        {
            if(a[j]+j>=i)
            {
                if(dp[j]!=INT_MAX)dp[i]=min(dp[i],dp[j]+1);
            }
        }
    }
    return dp[n-1];
}
int main()
{
    ll n;cin>>n;
    ll a[n];for(ll i=0;i<n;i++)cin>>a[i];
    if(minJumps(a,n)!=INT_MAX)
    cout<<minJumps(a,n);
    else cout<<"IMPSSIBLE"; 
}