/*
   Checking a number (n),whether it is prime or not

   ==>Solution
   If a number n is not a prime, it can be factored into two factors a and b:

n = a * b
Now a and b can't be both greater than the square root of n,
since then the product a * b would be greater than sqrt(n) * sqrt(n) = n.
So in any factorization of n, at least one of the factors must be smaller than the square root of n,
and if we can't find any factors less than or equal to the square root, n must be a prime.

*/

#include<bits/stdc++.h>
using namespace std;

bool checkPrime(int n)
{
    if(n==1)return false;
    for(int i=2;i<=sqrt(n);i++)
    {
        if(n%i==0)return false;
    }
    return true;
}

int main()
{
    int n;cin>>n;
    if(checkPrime(n))cout<<"Yes,it is prime";
    else cout<<"Not a prime no.";
    
}
