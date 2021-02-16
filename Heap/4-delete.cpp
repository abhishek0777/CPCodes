#include<bits/stdc++.h>
#define ll long long int
using namespace std;
/*
Algorithm:
1. Decrease key op on given idx,ie replace it wid minus infinity
2. Now minus infinity reaches to root.so extract min operation will delete it
*/
ll parent(ll i)
{
    return (i-1)/2;
}
void decreaseKey(ll i,vector<ll> &heap)
{
    heap[i]=INT_MIN;
    while((i>=0)&&(heap[parent(i)]>heap[i]))
    {
        swap(heap[parent(i)],heap[i]);
        i=parent(i);
    }
}
void minHeapify(ll i,vector<ll> &heap)
{
    ll lt=2*i+1;
    ll rt=2*i+2;
    ll sz=heap.size();
    ll minidx=i;
    if(lt<sz&&(heap[lt]<heap[minidx]))minidx=lt;
    if(rt<sz&&(heap[rt]<heap[minidx]))minidx=rt;
    if(minidx==i)return;
    swap(heap[i],heap[minidx]);
    minHeapify(minidx,heap);
}

void extractMin(vector<ll> &heap)
{
    swap(heap[0],heap[heap.size()-1]);
    ll sz=heap.size();
    heap.erase(heap.begin()+sz-1);
    minHeapify(0,heap);
}
int main()
{
    ll given[]={10,20,30,40,50,35,38,45};
    vector<ll> heap(given,given+8);
    ll i=3;//idx to be deleted
    decreaseKey(i,heap);
    extractMin(heap);
    for(ll x:heap)cout<<x<<" ";
}

/*
o/p:10 20 30 45 50 35 38 
*/