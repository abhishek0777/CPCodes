#include<bits/stdc++.h>
#define ll long long int
#define pb push_back
#define mp make_pair
#define inf INT_MAX
#define pii pair<ll,ll>

// Minimum coins to make a value
// test : coins[]={3,4,1}  val=5     ANS : 2 i.e {4,1}

using namespace std;

ll getMin(ll coins[],ll n,ll val)
{
    ll dp[val+1];
    for(ll i=0;i<=val;i++)dp[i]=inf;
    dp[0]=0;
    for(ll i=1;i<=val;i++)
    {
        for(ll j=0;j<n;j++)
        {
            if(coins[j]<=i)
            {
                ll sub_res=dp[i-coins[j]];
                if(sub_res!=inf)dp[i]=min(dp[i],1+sub_res);
            }
        }
    }
    
    return dp[val];
}


int main()
{
    ll n,val;cin>>n>>val;
    ll coins[n];
    for(ll i=0;i<n;i++)cin>>coins[i];
    cout<<getMin(coins,n,val);
}