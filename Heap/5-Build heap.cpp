/*
Build heap:
Given a random array,rearrange its elements to form a min heap
*/
#include<bits/stdc++.h>
#define ll long long int
using namespace std;
void minHeapify(ll i,ll a[],ll sz)
{
    ll lt=2*i+1;
    ll rt=2*i+2;
    ll minidx=i;
    if(lt<sz&&(a[lt]<a[minidx]))minidx=lt;
    if(rt<sz&&(a[rt]<a[minidx]))minidx=rt;
    if(minidx==i)return;
    swap(a[minidx],a[i]);
    minHeapify(minidx,a,sz);
}
void buildHeap(ll a[],ll sz)
{
    ll i=((sz-1)-1)/2;
    for(;i>=0;i--)
    {
        minHeapify(i,a,sz);
    }
}
int main()
{
    ll n;cin>>n;
    ll a[n];
    for(ll i=0;i<n;i++)cin>>a[i];
    buildHeap(a,n);
    for(ll i=0;i<n;i++)cout<<a[i]<<" ";
}

/*
Time complexity: O(n) not O(nlogn)
For more precise ,check video
*/