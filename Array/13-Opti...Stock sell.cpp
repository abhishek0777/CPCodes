/*
Maximum profit by buying and selling a share at most twice
*/
#include<bits/stdc++.h>
#define ll long long int
using namespace std;
int main()
{
    ll n;cin>>n;
    ll price[n];
    for(ll i=0;i<n;i++)cin>>price[i];
    ll first_profit[n];
    ll mxprofit=0,min_price=INT_MAX,max_price=INT_MIN;
    for(ll i=0;i<n;i++)
    {
        min_price=min(min_price,price[i]);
        mxprofit=max(mxprofit,price[i]-min_price);
        first_profit[i]=mxprofit;
    }
    mxprofit=0;
    for(ll i=n-1;i>=0;i--)
    {
        max_price=max(max_price,price[i]);
        if(i>0)
        mxprofit=max(mxprofit,first_profit[i-1]+max_price-price[i]);
        else mxprofit=max(mxprofit,max_price-price[i]);
    }
    cout<<mxprofit;
}