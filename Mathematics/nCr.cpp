/*
    Precompute the inverse of factorials in O(n) time

    Solution specially for queries based problems
 
*/

#include<bits/stdc++.h>
#define int long long int
const int N=1000001;
using namespace std;

int factInverse[N+1];
int numInverse[N+1];
int factorial[N+1];

void invNum(int p)
{
    numInverse[0]=numInverse[1]=1;
    for(int i=2;i<=N;i++)
    {
        numInverse[i]=numInverse[p%i]*(p-p/i)%p;
    }
}

void invFact(int p)
{
    factInverse[0]=factInverse[1]=1;
    for(int i=2;i<=N;i++)
    {
        factInverse[i]=numInverse[i]*factInverse[i-1]%p;
    }
}

void fact(int p)
{
    factorial[0]=1;
    for(int i=1;i<=N;i++)
    {
        factorial[i]=(factorial[i-1]*i)%p;
    }
}

int binomial(int n,int r,int p)
{
    int ans=(((factorial[n]*factInverse[r])%p)*factInverse[n-r])%p;
    return ans;
}

signed main()
{
    int p=1000000007;
    invNum(p);
    invFact(p);
    fact(p);

    int n,r;
    cin>>n>>r;
    cout<<binomial(n,r,p);
}
