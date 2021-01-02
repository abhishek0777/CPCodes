#include<bits/stdc++.h>
#define ll long long int
#define pb push_back
#define mp make_pair
#define pii pair<ll,ll>
#define ios_base::sync_with_stdio(NULL);cin.tie(false);
using namespace std;

// In coin change problem ,we have to count the combinations of coins to get given sum
ll cc(ll coins[],ll n,ll sum)
{
    ll dp[sum+1][n+1];
    for(ll i=0;i<=n;i++)dp[0][i]=1;
    for(ll i=1;i<=sum;i++)dp[i][0]=0;
    
    for(ll i=1;i<=sum;i++)
    {
        for(ll j=1;j<=n;j++)
        {
            dp[i][j]=dp[i][j-1];   //ignore the jth coins
            if(coins[j-1]<=i)dp[i][j]+=dp[i-coins[j-1]][j];  //include jth coin
        }
    }
    return dp[sum][n];
}


int main()
{
    ll n,sum;cin>>n>>sum;
    ll coins[n];
    for(ll i=0;i<n;i++)cin>>coins[i];
    cout<<cc(coins,n,sum);
}