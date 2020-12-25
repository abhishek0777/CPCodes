/*
 In this approach,each operation have worst complexity as logN
*/
#include<bits/stdc++.h>
#define ll long long int
using namespace std;

ll parent[10000];
ll rank[10000];

void initDSU()
{
    for(ll i=0;i<10000;i++){parent[i]=i;rank[i]=0}
}

ll findd(ll x)
{
    if(parent[x]==x)return x;
    return findd(parent[x]);
}

void unionn(ll x,ll y)
{
    ll x_rep=findd(x);
    ll y_rep=findd(y);
    if(x_rep==y_rep)return;

    if(rank[x_rep]<rank[y_rep]){
        parent[x_rep]=y_rep;
    }
    else if(rank[x_rep]>rank[y_rep]){
        parent[y_rep]=x_rep;
    }
    else{
        parent[y_rep]=x_rep;
        rank[x_rep]++;
    }
    
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