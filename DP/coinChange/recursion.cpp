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
    if(sum==0)return 1;
    if(n==0)return 0;
    ll res=cc(coins,n-1,sum);
    if(coins[n-1]<=sum)res+=cc(coins,n,sum-coins[n-1]);
    return res;
}


int main()
{
    ll n,sum;cin>>n>>sum;
    ll coins[n];
    for(ll i=0;i<n;i++)cin>>coins[i];
    cout<<cc(coins,n,sum);
}