#include<bits/stdc++.h>
#define ll long long int
#define pb push_back
#define mp make_pair
#define pii pair<ll,ll>
#define ios_base::sync_with_stdio(NULL);cin.tie(false);
using namespace std;
ll memo[1000][1000];

ll lcs(string s1,string s2,ll m,ll n)
{
    if(memo[m][n]!=-1)return memo[m][n];
    if(m==0||n==0)memo[m][n]=0;
    else
    {
        if(s1[m-1]==s2[n-1])
        memo[m][n]=1+lcs(s1,s2,m-1,n-1);
        else
        memo[m][n]=max(lcs(s1,s2,m-1,n),lcs(s1,s2,m,n-1));
    }
    return memo[m][n];
}

int main()
{
    string s1,s2;cin>>s1>>s2;
    ll m=s1.length();
    ll n=s2.length();
    for(ll i=0;i<=m;i++)for(ll j=0;j<=n;j++)memo[i][j]=-1;
    cout<<lcs(s1,s2,m,n);
}