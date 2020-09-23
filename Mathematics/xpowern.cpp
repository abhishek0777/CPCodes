/*
    x^n in log(n) using iterative approach
    
*/

#include<bits/stdc++.h>
using namespace std;

void xPowern(int x,int y)
{
    int res=1;
    while(y>0)
    {
        if(y&1)res*=x;
        y>>=1;
        x=x*x;;
    }
    cout<<res;
}
int main()
{
    int x,n;cin>>x>>n;
    xPowern(x,n);
}
