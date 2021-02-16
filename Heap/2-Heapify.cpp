//Min heapify: fiven a binary heap with one possible violation ,fix the heap.
#include<bits/stdc++.h>
#define ll long long int
using namespace std; 
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
int main()
{
    ll given[]={40,20,30,35,25,80,32,100,70,60};
    vector<ll> heap(given,given+10);
    //we are also given index of violating node
    ll i=0;
    minHeapify(i,heap);
    for(ll x:heap)cout<<x<<" ";
}

/*
o/p :20 25 30 35 40 80 32 100 70 60 
*/