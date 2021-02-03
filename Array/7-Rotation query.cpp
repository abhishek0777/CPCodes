// https://www.geeksforgeeks.org/queries-left-right-circular-shift-array/
#include<bits/stdc++.h>
#define ll long long int
using namespace std;

int main()
{
    ll n,q;cin>>n>>q;
    ll a[n],psum[n+1]={0};
    for(ll i=0;i<n;i++)
    {
        cin>>a[i];
        psum[i+1]=psum[i]+a[i];
    }
    ll sum=0;
    ll type,rot,l,r;
    while(q--)
    {
        cin>>type;
        if(type==1)
        {
            cin>>rot;
            sum-=rot;
        }
        else if(type==2)
        {
            cin>>rot;
            sum+=rot;
        }
        else
        {
            cin>>l>>r;
            l=(n+(l+n+sum)%n)%n;
            r=(n+(r+n+sum)%n)%n;
            if(l<=r)cout<<psum[r+1]-psum[l]<<endl;
            else cout<<psum[n]-psum[l]+psum[r+1]<<endl;
        }
    }
}