#include<bits/stdc++.h>
#define ll long long int
using namespace std;
/*
Approach: So the basic approach is to check only consecutive pairs of x and y. For every element x or y,
 check the index of the previous occurrence of x or y and if the previous occurring element is not similar 
 to current element update the minimum distance. But a question arises what if an x is preceded by another x and that is preceded by a y, 
 then how to get the minimum distance between pairs. By analyzing closely it can be seen that every x followed by a y or vice versa can only be the closest pair (minimum distance) so ignore all other pairs.
Algorithm:
1.Create a variable prev=-1 and m= INT_MAX
2.Traverse through the array from start to end.
3.If the current element is x or y, prev is not equal to -1 and array[prev] is not equal to current element then update m = max(current_index – prev, m), i.e. find the distance between consecutive pairs and update m with it.
4.print the value of m
*/
int main()
{
    ll n;cin>>n;
    ll a[n];
    for(ll i=0;i<n;i++)cin>>a[i];
    ll x,y;cin>>x>>y;
    ll prev=-1;
    ll d=INT_MAX;
    for(ll i=0;i<n;i++)
    {
        if(a[i]==x||a[i]==y)
        {
            if(prev!=-1)
            {
                if(a[prev]!=a[i])
                {
                    d=min(d,i-prev);
                }
            }
            prev=i;
        }
    }
    cout<<d;
    
}