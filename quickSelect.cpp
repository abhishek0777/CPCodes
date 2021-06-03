#include <bits/stdc++.h>
#define ll long long int
#define pii pair<ll,ll>
#define pb push_back
#define mp make_pair
#define FAST ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;

#define MOD 1000000007

/*
   notes
   Quick-select algorithm is a selection algorithm to find kth smallest element efficiently.
   Quick sort and quick select algos are very similar,partition method is same in both
   

*/

int partition(int a[], int st, int end)
{
   int i = st - 1, j = st;
   int pivot = end;
   for (; j < end; j++) {
      if (a[j] <= a[pivot]) {
         swap(a[i + 1], a[j]);
         i++;
      }
   }
   swap(a[i + 1], a[pivot]);
   return i + 1;

}

int quickSelect(int a[], int st, int end, int k)
{
   int pi = partition(a, st, end);
   if (pi + 1 > k) {
      return quickSelect(a, 0, pi - 1, k);
   }
   else if (pi + 1 < k) {
      return quickSelect(a, pi + 1, end, k - (pi + 1));
   }
   else return a[pi];

}


void solve()
{
   int n, k; cin >> n >> k;
   int a[n];
   for (int i = 0; i < n; i++)cin >> a[i];
   cout << quickSelect(a, 0, n - 1, k);
}


int main() {
   FAST
   ll t = 1;
   // cin >> t;
   while (t--)solve();
   return 0;
}


