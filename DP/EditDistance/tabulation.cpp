#include<bits/stdc++.h>
#define ll long long int
#define pb push_back
#define mp make_pair
#define pii pair<ll,ll>

using namespace std;

// Edit distance : in this problem we need to find minimum no of operation to convert str1 to str2
// Operations are : insert,del,replace
// test case : CAT to CUT 

 
ll eD(string s1,string s2,ll m,ll n)
{
    ll dp[m+1][n+1];
    for(ll i=0;i<=n;i++)dp[0][i]=i;
    for(ll i=0;i<=m;i++)dp[i][0]=i;
    for(ll i=1;i<=m;i++)
    {
        for(ll j=1;j<=n;j++)
        {
            //if last char of strings of length i and length j
            // string s1 from 0 to i-1,similarly 0 to j-1
            if(s1[i-1]==s2[j-1])dp[i][j]=dp[i-1][j-1];
            else
            {
                dp[i][j]=1+min(dp[i][j-1],min(dp[i-1][j-1],dp[i-1][j]));
            }
        }
    }
    return dp[m][n];
}


int main()
{
    string s1,s2;cin>>s1>>s2;
    ll m=s1.length();
    ll n=s2.length();
    cout<<eD(s1,s2,m,n);
}