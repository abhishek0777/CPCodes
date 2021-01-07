#include<bits/stdc++.h>
#define ll long long int
#define pb push_back
#define mp make_pair
#define inf INT_MAX
#define pii pair<ll,ll>

using namespace std;

//input arr[]={3,4,2,8,10,5,1}
// o/p : 4

int main()
{
    ll n;cin>>n;
    ll a[n];for(ll i=0;i<n;i++)cin>>a[i];
    ll lis[n];
    lis[0]=1;
    ll ans=1;
    for(ll i=1;i<n;i++)
    {
        lis[i]=1;
        for(ll j=i-1;j>=0;j--)
        {
            if(a[j]<a[i])lis[i]=max(lis[i],lis[j]+1);
        }
        ans=max(ans,lis[i]);
    }
    cout<<ans;
}

ll msis[n];
ll res=0;
for(ll i=0;i<n;i++)
{
    msis[i]=arr[i];
    for(ll j=0;j<i;j++)
    {
        if(arr[j]<arr[i])
        msis[i]=max(msis[i],msis[j]+arr[i]);
    }
    res=max(res,msis[i]);
}
