#include<bits/stdc++.h>
#define ll long long int
#define pii pair<ll,ll>
using namespace std;

/*
link:https://www.geeksforgeeks.org/number-whose-sum-of-xor-with-given-array-range-is-maximum/
5 3
20 11 18 2 12
1 3
3 5
2 4
*/
int main()
{
    ll n,q;cin>>n>>q;
    ll a[n+1];
    for(ll i=1;i<=n;i++)cin>>a[i];
    
    //make prefix array
    ll cntOne[n+1][32]={};
    for(ll i=1;i<=n;i++)
    {
        for(ll j=0;j<=31;j++)
        {
            if(a[i]&(1LL<<j))cntOne[i][j]=1+cntOne[i-1][j];
            else cntOne[i][j]=cntOne[i-1][j];
        }
    }
    
    while(q--)
    {
        ll l,r;cin>>l>>r;
        ll total_bits=r-l+1;
        ll x=(1LL<<31)-1;
        for(ll i=0;i<=31;i++)
        {
            //count number of 1 at ith bits
            ll c=cntOne[r][i]-cntOne[l-1][i];
            if(c>=total_bits-c)
            {
                x^=(1LL<<i);
            }
        }
        cout<<x<<endl;
    }
}