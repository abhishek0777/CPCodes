/*
Heap sort is based on selection sort
Selection sort picks maximum element and swap it with last element.
So heap sort is also based on selection sort but it is optimized over selection,it used
max heap data structure to find max element and swap it with last

Algorithm:
1. First build a max heap.
2. Swap max element with last element.
3. And then heapify remaining array(size of array decrease by 1)
*/
#include<bits/stdc++.h>
#define ll long long int
using namespace std;

void maxHeapify(ll i,ll a[],ll sz)
{
    ll lt=2*i+1;
    ll rt=2*i+2;
    ll maxIdx=i;
    if(lt<sz&&(a[lt]>a[maxIdx]))maxIdx=lt;
    if(rt<sz&&(a[rt]>a[maxIdx]))maxIdx=rt;
    if(maxIdx==i)return;
    swap(a[i],a[maxIdx]);
    maxHeapify(maxIdx,a,sz);
}
void buildMaxHeap(ll a[],ll sz)
{
    for(ll i=(sz-2)/2;i>=0;i--)
    {
        maxHeapify(i,a,sz);
    }
}
int main()
{
    ll n;cin>>n;
    ll a[n];
    for(ll i=0;i<n;i++)cin>>a[i];
    buildMaxHeap(a,n);
    
    for(ll i=n-1;i>=1;i--)
    {
        swap(a[0],a[i]);
        maxHeapify(0,a,i);
    }
    for(ll i=0;i<n;i++)cout<<a[i]<<" ";
}