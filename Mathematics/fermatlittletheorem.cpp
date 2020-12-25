/*
    Fermat’s little theorem states that if p is a prime number, then for any integer a, the number a^p – a is an integer multiple of p.

    Here p is a prime number
    a^p ≡ a (mod p).

    Special Case: If a is not divisible by p, Fermat’s little theorem is equivalent to the statement that a^(p-1)-1 is an integer multiple of p.

    a^(p-1) ≡ 1 (mod p)
    OR
    a^(p-1) % p = 1 
    Here a is not divisible by p.


    ==>Use of Fermat’s little theorem

    If we know m is prime, then we can also use Fermats’s little theorem to find the inverse.

    a^(m-1) ≡ 1 (mod m)
    If we multiply both sides with a^(-1), we get
    a^(-1) ≡ a^(m-2)(mod m)
*/

#include<bits/stdc++.h>
using namespace std;


// modular exponentiation
int power(int x,int y,int m)
{
    int res=1;
    x%=m;
    if(x==0){return 0;}
    else if(y==0){return 1;}
    else
    {
        while(y>0)
        {
            if(y&1){
                res=(res*x)%m;
            }
            y=y>>1;
            x=(x*x)%m;
        }
        return res;
    }
    
    
}

void modInv(int a,int m)
{
    if(__gcd(a,m)!=1)
    {
         cout<<"Inverse doesn't exist !";
         return;
    }
    cout<<power(a,m-2,m);
}
int main()
{
    int a,m;cin>>a>>m;
    modInv(a,m);
}