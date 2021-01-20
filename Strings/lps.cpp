//Longest proper prefix which is also suffix
#include<bits/stdc++.h>
#include<algorithm>
#define ll long long int
#define pii pair<ll,ll>
#define pb push_back
#define mp make_pair
#define FAST ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;

#define ALL(x) x.begin(),x.end()
#define MOD 1000000007
#define inf INT_MAX

ll add(ll x,ll y){ll res=x+y; return (res>=MOD?res-MOD:res);}
ll mul(ll x,ll y){ll res=x*y; return ( res>=MOD?res%MOD:res);}
ll sub(ll x,ll y){ll res=x-y; return (res<0?res+MOD:res);}

void fillLps(string s,vector<ll> &lps)
{
    ll n=s.length();
    ll len=0;
    lps[0]=0;
    ll i=1;
    while(i<n)
    {
        if(s[i]==s[len])
        {
            len++;
            lps[i]=len;
            i++;
        }
        else
        {
            if(len==0)
            {
                lps[i]=0;
                i++;
            }
            else
            {
                len=lps[len-1];
            }
        }
    }
    
}

void solve()
{
   string s;cin>>s;
   vector<ll> lps(s.length());
   fillLps(s,lps);
   for(ll i=0;i<s.length();i++)cout<<lps[i]<<" ";
}

int main()
{
    solve();
    return 0;
}