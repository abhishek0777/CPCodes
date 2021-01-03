#include<bits/stdc++.h>
#define ll long long int
#define pb push_back
#define mp make_pair
#define inf INT_MAX
#define pii pair<ll,ll>

using namespace std;

ll minJumps(ll a[],ll n)
{
    if(n==1)return 0;
    ll res=INT_MAX;
    for(ll i=0;i<n-1;i++)
    {
        if(i+a[i]>=n-1)
        {
            ll sub_res=minJumps(a,i+1);
            if(sub_res!=INT_MAX)res=min(res,sub_res+1);
        }
    }
    return res;
}
int main()
{
    ll n;cin>>n;
    ll a[n];for(ll i=0;i<n;i++)cin>>a[i];
    if(minJumps(a,n)!=INT_MAX)
    cout<<minJumps(a,n);
    else cout<<"IMPSSIBLE"; 
}