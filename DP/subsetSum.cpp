#include<bits/stdc++.h>
#define ll long long int
#define pb push_back
#define mp make_pair
#define inf INT_MAX
#define pii pair<ll,ll>

using namespace std;

bool subsetSum(ll a[],ll sum,ll n)
{
    bool dp[n][sum+1];
    for(ll i=0;i<n;i++)for(ll j=0;j<=sum;j++)dp[i][j]=false;
    for(ll i=0;i<n;i++)dp[i][0]=true;
    for(ll j=0;j<=sum;j++){if(j==a[0])dp[0][j]=true;else dp[0][j]=false;}
    for(ll i=1;i<n;i++)
    {
        for(ll j=1;j<=sum;j++)
        {
            //exclue a[i]
            if(dp[i-1][j])dp[i][j]=true;
            //include a[i]
            else
            {
                if(j>=a[i])dp[i][j]=dp[i-1][j-a[i]];
            }
            
            
        }
    }
    return dp[n-1][sum];
}

int main()
{
    ll n,sum;cin>>n>>sum;
    ll a[n];
    for(ll i=0;i<n;i++)cin>>a[i];
    if(subsetSum(a,sum,n))cout<<"Possible";
    else cout<<"NOt Possible";
}