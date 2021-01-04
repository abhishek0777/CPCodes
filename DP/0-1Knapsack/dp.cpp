#include <bits/stdc++.h>
#include <algorithm>
#define ll long long int
#define pii pair<ll,ll>
#define pb push_back
#define mp make_pair
#define FAST ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;

#define pb push_back
#define mp make_pair

#define MOD 1000000007
#define inf 1000000007

//test input : val[]={10,40,30,50}   wt[]={5,4,6,3}   W=10

ll knapsack(ll W,ll val[],ll w[],ll n)
{
    ll dp[W+1][n+1];
    for(ll i=0;i<=n;i++)dp[0][i]=0;
    for(ll i=0;i<=W;i++)dp[i][0]=0;
    for(ll i=1;i<=W;i++)
    {
        for(ll j=1;j<=n;j++)
        {
            if(w[j-1]>i)
            dp[i][j]=dp[i][j-1];
            else
            dp[i][j]=max(dp[i-w[j-1]][j-1]+val[j-1],dp[i][j-1]);
        }
    }
    return dp[W][n];
}


int main() {
    FAST
    ll n;cin>>n;
    ll val[n],w[n];
    ll W;
    for(ll i=0;i<n;i++)cin>>val[i];
    for(ll i=0;i<n;i++)cin>>w[i];
    cin>>W;
    cout<<knapsack(W,val,w,n);
	return 0;
}
