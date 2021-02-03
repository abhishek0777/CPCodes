#include<bits/stdc++.h>
#define ll long long int
using namespace std;
//Juggling algorithm to rotate array by d in left

// youtube link : https://www.youtube.com/watch?v=utE_1ppU5DY

// Time complexity : O(n)
void rotate(ll a[],ll n,ll d)
{
    for(ll i=0;i<__gcd(n,d);i++)
    {
        ll temp=a[i];
        ll j=i,k;
        while(true)
        {
            k=(j+d)%n;
            if(k==i)break;
            a[j]=a[k];
            j=k;
        }
        a[j]=temp;
    }
}
int main()
{
    ll n,d;cin>>n>>d;    
    ll a[n];
    for(ll i=0;i<n;i++)cin>>a[i];
    rotate(a,n,d);
    for(ll i=0;i<n;i++)cout<<a[i]<<" ";
}