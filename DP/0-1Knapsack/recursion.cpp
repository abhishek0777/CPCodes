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
    if(n==0||W==0)return 0;
    if(W<w[n-1])return knapsack(W,val,w,n-1);
    else
    return max(knapsack(W,val,w,n-1),val[n-1]+knapsack(W-w[n-1],val,w,n-1));
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
