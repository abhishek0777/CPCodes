/*
   SIEVE OF ERATOSTHENES
   Given a number n, print all primes smaller than or equal to n. It is also given that n is a small number.

   ALERT ! ==> 
   The sieve of Eratosthenes is one of the most efficient ways to
   find all primes smaller than n when n is smaller than 10 million or so.

   Algorithm :
   * Create a list of consecutive integers from 2 to n: (2, 3, 4, …, n).
   * Initially, let p equal 2, the first prime number.
   * Starting from p2, count up in increments of p and mark each of these numbers greater than or equal to p2 itself in the list. These numbers will be p(p+1), p(p+2), p(p+3), etc..
   * Find the first number greater than p in the list that is not marked. If there was no such number, stop. Otherwise, let p now equal this number (which is the next prime), and repeat from step 3.

*/

#include<bits/stdc++.h>
using namespace std;


int main()
{
    int n;cin>>n;
    bool prime[n+1];
    memset(prime,true,sizeof(prime));
    for(int p=2;p*p<=n;p++)
    {
         if(prime[p]==true)
         {
             for(int i=p*p;i<=n;i+=p)
             {
                 prime[i]=false;
             }
         }
    }

    for(int i=1;i<=n;i++)
    {
        if(prime[p])cout<<i<<" ";
    }
    return 0;
}

