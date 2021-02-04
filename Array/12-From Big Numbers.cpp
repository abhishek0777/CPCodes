#include<bits/stdc++.h>
#define ll long long int
using namespace std;
/*Given an array of numbers, arrange them in a way that yields the largest value For example, if the given numbers are {54, 546, 548, 60}, the arrangement 6054854654 gives the largest value
*/
bool mycmp(string x,string y)
{
    string xy=x.append(y);
    string yx=y.append(x);
    return (xy.compare(yx)>0);
}
int main()
{
    ll n;cin>>n;
    vector<string> a;
    for(ll i=0;i<n;i++){string y;cin>>y;a.push_back(y);}
    sort(a.begin(),a.end(),mycmp);
    for(ll i=0;i<n;i++)cout<<a[i]<<" ";
}