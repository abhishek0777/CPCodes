/*

    We are given two arrays num[0..k-1] and rem[0..k-1]. In num[0..k-1], every pair is coprime (gcd for every pair is 1). We need to find minimum positive number x such that:

        x % num[0]    =  rem[0], 
        x % num[1]    =  rem[1], 
        .......................
        x % num[k-1]  =  rem[k-1] 
    Basically, we are given k numbers which are pairwise coprime, and given remainders of these numbers when an unknown number x is divided by them. We need to find the minimum possible value of x that produces given remainders.    


    x =  ( ∑ (rem[i]*pp[i]*inv[i]) ) % prod
    Where 0 <= i <= n-1

    rem[i] is given array of remainders

    prod is product of all given numbers
    prod = num[0] * num[1] * ... * num[k-1]

    pp[i] is product of all divided by num[i]
    pp[i] = prod / num[i]

    inv[i] = Modular Multiplicative Inverse of 
             pp[i] with respect to num[i]
*/

//------------------Chinese remainder Theorem------------------//

#include<bits/stdc++.h>
using namespace std;

int gcdExtended(int a,int b,int* x,int* y)
{
    if(a==0)
    {
        *x=0;
        *y=1;
        return b;
    }

    int x1,y1;
    int gcd=gcdExtended(b%a,a,&x1,&y1);

    *x=y1-(b/a)*x1;
    *y=x1;

    return gcd;
}

int inv(int a,int m)
{
    int x,y;
    int g=gcdExtended(a,m,&x,&y);
    // if(g!=1)
    // {
    //     cout<<"Inverse does't exist !";
    // }
    // else
    {
        int res=((x%m)+m)%m;
        return res;
    }
    
}

void minX(int num[],int rem[],int n)
{
    int prod=1;
    for(int i=0;i<n;i++)prod*=num[i];

    int res=0;

    for(int i=0;i<n;i++)
    {
        int pp=prod/num[i];
        res+=rem[i]*inv(pp,num[i])*pp;
    }
    res%=prod;

    cout<<res<<endl;
}

int main()
{
    int n;cin>>n;
    int num[n],rem[n];
    for(int i=0;i<n;i++)cin>>num[i];
    for(int i=0;i<n;i++)cin>>rem[i];

    minX(num,rem,n);
}

