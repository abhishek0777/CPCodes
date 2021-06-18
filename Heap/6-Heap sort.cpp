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
#include <bits/stdc++.h>
#define ll long long int
#define FAST ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;

#define MOD 1000000007
/*
   notes

*/

void heapify(int i, int a[], int n)
{
   int lt = 2 * i + 1, rt = 2 * i + 2, largest = i;
   if (lt < n && a[lt] > a[largest])largest = lt;
   if (rt < n && a[rt] > a[largest])largest = rt;
   if (largest != i) {
      swap(a[i], a[largest]);
      heapify(largest, a, n);
   }
}

void buildMaxHeap(int a[], int n)
{
   for (int i = (n - 2) / 2; i >= 0; i--) {
      heapify(i, a, n);
   }
}

void heapSort(int a[], int n)
{
   for (int i = n - 1; i >= 0; i--) {
      swap(a[i], a[0]);
      heapify(0, a, i);
   }
}
void solve()
{
   int n; cin >> n;
   int a[n];
   for (int i = 0; i < n; i++)cin >> a[i];
   buildMaxHeap(a, n);
   heapSort(a, n);
   for (int i = 0; i < n; i++)cout << a[i] << " ";

}



int main() {
   FAST
   ll t = 1;
   cin >> t;
   while (t--)solve();
   return 0;
}