#include<bits/stdc++.h>
#define ll long long int
#define pb push_back
#define mp make_pair
#define pii pair<ll,ll>
#define ios_base::sync_with_stdio(NULL);cin.tie(false);
using namespace std;


ll lcs(string s1,string s2,ll m,ll n)
{
    if(m==0||n==0)return 0;
    if(s1[m-1]==s2[n-1])return (1+lcs(s1,s2,m-1,n-1));
    else return max(lcs(s1,s2,m-1,n),lcs(s1,s2,m,n-1));
}

int main()
{
    string s1,s2;cin>>s1>>s2;
    ll m=s1.length();
    ll n=s2.length();
    cout<<lcs(s1,s2,m,n);
}