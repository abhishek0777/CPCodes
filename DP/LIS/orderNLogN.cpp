#include<bits/stdc++.h>
#define ll long long int
#define pb push_back
#define mp make_pair
#define inf INT_MAX
#define pii pair<ll,ll>

using namespace std;

//input arr[]={3,4,2,8,10,5,1}
// o/p : 4

//it uses binary search

//tail array: tail[i]  stores the minimum possible tail value of LIS of length i+1

int main()
{
    ll n;cin>>n;
    ll a[n];for(ll i=0;i<n;i++)cin>>a[i];
    ll tail[n];
    tail[0]=a[0];
    ll len=1;
    for(ll i=1;i<n;i++)
    {
        if(a[i]>tail[len-1])
        {
            tail[len]=a[i];
            len++;
        }
        else
        {
            auto j=upper_bound(tail,tail+len,a[i])-tail;
            tail[j]=a[i];
        }
    }
    cout<<len;
}