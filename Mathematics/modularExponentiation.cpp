#include<bits/stdc++.h>
using namespace std;

void power(int x,int y,int p)
{
    int res=1;
    x%=p;
    if(x==0)cout<<"0";
    else
    {
        while(y>0)
        {
            if(y&1)(res*=x)%=p;
            y>>=1;
            (x*=x)%=p;
        }
        cout<<res<<endl;
    }
}
int main()
{
    int x,y,p;
    cin>>x>>y>>p;
    power(x,y,p);
}