// This is a pattern searching algorithm
// Worst Time complexity is quad,otherwise linear

//Test Input : 
// txt : abdabcbabc
// pat : abc
//O/P : 3 7

//hash value for 'abc'=1*d^2 + 2*d + 3  where d is weight
//Rolling hash : t(i+1)=d(ti-txt[i]*d^(m-1))+txt[i+m]

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
ll mul(ll x,ll y){ll res=x*y; return (res>=MOD?res%MOD:res);}
ll sub(ll x,ll y){ll res=x-y; return (res<0?res+MOD:res);}

void RBsearch(string pat,string txt,ll m,ll n)
{
    ll h=1;
    // compute d^(m-1)
    ll d=26;
    for(ll i=1;i<=m-1;i++)h=mul(h,d);
    
    ll p=0,t=0;
    for(ll i=0;i<m;i++)
    {
        p=add(mul(p,d),pat[i]);
        t=add(mul(t,d),txt[i]);
    }
    for(ll i=0;i<=n-m;i++)
    {
        if(p==t)
        {
            bool flag=true;
            for(ll j=0;j<m;j++)
            {
                if(txt[i+j]!=pat[j]){flag=false;break;}
            }
            if(flag==true)cout<<i<<" ";
        }
        if(i<n-m)
        {
            t=add( txt[i+m] , mul(d,sub(t,mul(txt[i],h))));
            if(t<0)t+=MOD;
        }
    }
}

void solve()
{
    string txt,pat;
    cin>>txt>>pat;
    ll n=txt.length();
    ll m=pat.length();
    
    RBsearch(pat,txt,m,n);
}

int main()
{
    solve();
    return 0;
}