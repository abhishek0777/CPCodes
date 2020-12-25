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
#include <bits/stdc++.h>
#define int long long int
#define FAST ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;


int gcdExt(int a,int m,int *x,int *y)
{
    if(a==0)
    {
        *x=0;
        *y=1;
        return m;
    }
    
    int x1,y1;
    int gcd=gcdExt(m%a,a,&x1,&y1);
    
    *x=y1-(m/a)*x1;
    *y=x1;
    
    return gcd;
}

int modInverse(int a,int m)
{
    int x,y;
    int gcd=gcdExt(a,m,&x,&y);
    
    if(gcd!=1){
        cout<<"Modular multiplicative of a under modula m doesn't exist";
    }
    else{
        return x;
    }
    
}

void solve()
{
    int a,m;
    cin>>a>>m;
    cout<<modInverse(a,m);
}

signed main() {
    FAST
    int t;cin>>t;
    while(t--)solve();
	return 0;
}
