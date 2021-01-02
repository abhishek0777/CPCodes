#include<bits/stdc++.h>
#define ll long long int
#define pb push_back
#define mp make_pair
#define pii pair<ll,ll>
#define ios_base::sync_with_stdio(NULL);cin.tie(false);
using namespace std;

ll lcs(string s1,string s2,ll m,ll n)
{
    ll memo[m+1][n+1];
    for(ll i=0;i<=m;i++)memo[i][0]=0;
    for(ll i=0;i<=n;i++)memo[0][i]=0;
    for(ll i=1;i<=m;i++)
    {
        for(ll j=1;j<=n;j++)
        {
            if(s1[i-1]==s2[j-1])memo[i][j]=1+memo[i-1][j-1];
            else memo[i][j]=max(memo[i-1][j],memo[i][j-1]);
        }
    }
    return memo[m][n];
}

int main()
{
    string s1,s2;cin>>s1>>s2;
    ll m=s1.length();
    ll n=s2.length();
    cout<<lcs(s1,s2,m,n);
}