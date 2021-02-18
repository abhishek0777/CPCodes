#include<bits/stdc++.h>
#define ll long long int
#define pii pair<ll,ll>
#define pb push_back

using namespace std;
void printMedians(ll a[],ll n)
{
    priority_queue<ll> s;  //smaller  half
    priority_queue<ll,vector<ll>,greater<ll>> g;    //greater half
    s.push(a[0]);
    cout<<a[0]<<" ";
    for(ll i=1;i<n;i++)
    {
        ll x=a[i];
        if(s.size()==g.size())
        {
            if(x>g.top())
            {
                g.push(x);
                s.push(g.top());
                g.pop();
            }
            else
            {
                s.push(x);
            }
            cout<<s.top()<<" ";
        }
        else
        {
            if(x<s.top())
            {
                g.push(s.top());
                s.pop();
                s.push(x);
            }
            else
            {
                g.push(x);
            }
            cout<<(float)(g.top()+s.top())/2<<" ";
        }
    }
}

int main()
{
    ll n;cin>>n;
    ll a[n];
    for(ll i=0;i<n;i++)cin>>a[i];
    printMedians(a,n);
}

/*
Input:
7
12 15 10 5 8 7 16
Output:
12 13.5 12 11 10 9 10 

*/