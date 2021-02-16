#include<bits/stdc++.h>
#define ll long long int
using namespace std;
//get min is basically extract function,otherwise get minimum is constant op i.e return heap[0];

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
    //now we have moved last element to first position,now we will heapify the min heap
    minHeapify(0,heap);
    
}

int main()
{
    ll given[]={20,25,30,35,40,80,32,100,70,60};
    vector<ll> heap(given,given+10);
    extractMin(heap);
    for(ll x:heap)cout<<x<<" ";
}

/*
o/p:25 35 30 60 40 80 32 100 70 
*/