/*
    Reducing height of tree

    Time complexity
    for m operations on n elements
    O(m alpha(n))    where alpha(x) is ammortized time complexity
    and alpha(n)<=4
    alpha(n) is inverse ackermann function
    so for m operation,complexity is constant
*/
#include<bits/stdc++.h>
#define ll long long int
using namespace std;

ll parent[10000];

void initDSU()
{
    for(ll i=0;i<10000;i++)parent[i]=i;
}

ll findd(ll x)
{
    if(parent[x]==x)return x;
    parent[x]=findd(parent[x]);
    return parent[x];
}

void unionn(ll x,ll y)
{
    ll x_rep=findd(x);
    ll y_rep=findd(y);
    if(x_rep==y_rep)return;
    parent[y_rep]=x_rep;
}
int main()
{
    // n is number of disjoint initially
    ll n=5;
    initDSU();
    unionn(0,1);
    unionn(1,2);
    unionn(3,4);
    cout<<findd(0)<<" "<<findd(1)<<" "<<findd(2)<<endl;
    cout<<findd(3)<<" "<<findd(4)<<endl;
    
    
}