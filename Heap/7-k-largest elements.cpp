/*
Method-1:
Build a max heap => O(n)
Extract k items one by one => O(klogn)
So overall time complexity => O(n + klogn) = O(klogn)
So when k reaches n,complexity will be nlogn,

There is one more efficient method
Method-2:
Build a min heap of first k-elements
Then loop from k+1 to n,and everytime checks top element of heap
with current element,if current is greater than top,swap it,and heapify
Complexity:
Building a min heap=>O(k)
Looping over remaining elements=>O((n-k)logk)
so overall O(k+(n-k)logk) 
so if k is too small its of O(k) and when k is too large, its O(n),
Hence efficient in all cases
*/
#include<bits/stdc++.h>
#define ll long long int
using namespace std;

void heapify(ll a[],ll i,ll sz)
{
    ll lt=2*i+1;
    ll rt=2*i+2;
    ll minIdx=i;
    if(lt<sz&&(a[lt]<a[minIdx]))minIdx=lt;
    if(rt<sz&&(a[rt]<a[minIdx]))minIdx=rt;
    if(minIdx==i)return;
    swap(a[i],a[minIdx]);
    heapify(a,minIdx,sz);
}

void buildMinHeap(ll a[],ll sz)
{
    for(ll i=(sz-2)/2;i>=0;i--)
    {
        heapify(a,i,sz);
    }
}
int main()
{
    ll n,k;cin>>n>>k;
    ll a[n];
    for(ll i=0;i<n;i++)cin>>a[i];
    buildMinHeap(a,k);
    for(ll i=k;i<n;i++)
    {
        if(a[0]<a[i])
        {
            a[0]=a[i];
            heapify(a,0,k);
        }
    }
    for(ll i=0;i<k;i++)cout<<a[i]<<" ";
}