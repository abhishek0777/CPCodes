#include<bits/stdc++.h>
#define ll long long int
#define pb push_back
#define mp make_pair
#define pii pair<ll,ll>

using namespace std;

// Edit distance : in this problem we need to find minimum no of operation to convert str1 to str2
// Operations are : insert,del,replace
ll eD(string s1,string s2,ll m,ll n)
{
    if(m==0)return n;
    if(n==0)return m;
    if(s1[m-1]==s2[n-1])return eD(s1,s2,m-1,n-1);
    
    return 1+min(
                eD(s1,s2,m-1,n),   //delete
             min(
                 eD(s1,s2,m-1,n-1),  //replace
                 eD(s1,s2,m,n-1)     // insert
                )   
        );
}


int main()
{
    string s1,s2;cin>>s1>>s2;
    ll m=s1.length();
    ll n=s2.length();
    cout<<eD(s1,s2,m,n);
}