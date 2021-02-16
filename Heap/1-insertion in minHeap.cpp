//insertion in given min heap
#include<bits/stdc++.h>
#define ll long long int
using namespace std;

ll parent(ll i)
{
    return (i-1)/2;
}
//insertion in min heap
// similarly we can do decrease key operation
void insert(ll el,vector<ll> &heap)
{
    ll i=heap.size();
    heap.push_back(el);
    //since insertion is not sufficient,we have to also check the second property i.e each node have value smaller than its descendants.
    //index of new elment will be i now.so 
    while((i>=0)&&(heap[parent(i)]>heap[i]))
    {
        swap(heap[parent(i)],heap[i]);
        i=parent(i);
    }

}
int main()
{
    //already have heap
    ll given[]={10,20,15,40,50,100,25,45};
    vector<ll> heap(given,given+8);
    ll el;cin>>el;
    insert(el,heap);
    for(ll x:heap)cout<<x<<" ";
}

/*
i/p : 12
o/p :10 12 15 20 50 100 25 45 40 
*/