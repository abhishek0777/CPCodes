/*
    Given two integers ‘a’ and ‘m’, find modular multiplicative inverse of ‘a’ under modulo ‘m’.

    The modular multiplicative inverse is an integer ‘x’ such that.
    a x ≡ 1 (mod m) 
    The value of x should be in {0, 1, 2, … m-1}, i.e., in the range of integer modulo m.

    The multiplicative inverse of “a modulo m” exists if and only if a and m are relatively prime (i.e., if gcd(a, m) = 1).
*/

//naive approach
/*
    int modInverse(int a, int m) 
    { 
        a = a%m; 
        for (int x=1; x<m; x++) 
        if ((a*x) % m == 1) 
            return x; 
    }
*/

//efficient approach
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

void modInverse(int a,int m)
{
    int x,y;
    int g=gcdExtended(a,m,&x,&y);
    if(g!=1)
    {
        cout<<"Inverse does't exist !";
    }
    else
    {
        int res=((x%m)+m)%m;
        cout<<res<<endl;
    }
    
}

int main()
{
    int a,m;cin>>a>>m;
    modInverse(a,m);
}