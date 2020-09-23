/*
   while n divides by 2 ,divide it by 2
   when n becomes odd
   start a for loop from i=3 to sqrt(n),then for each i divide n till it is divisible,
   and when it fails to divide, increment i =i+2.
   after above two operations if n!=1 and n>2,include n in its factors.
*/

#include<bits/stdc++.h>
using namespace std;

void primeF(int n)
{
    while(n%2==0)
    {
        cout<<"2 ";
        n/=2;
    }
    for(int i=3;i<=sqrt(n);i+=2)
    {
        while(n%i==0)
        {
            cout<<i<<" ";
            n/=i;
        }
    }
    if(n>2)cout<<n;
}
int main()
{
    int n;cin>>n;
    primeF(n);
    return 0;
}