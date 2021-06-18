#include <bits/stdc++.h>
#define ll long long int
#define FAST ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;

#define MOD 1000000007
/*
   notes

*/

void solve()
{
   int n, k; cin >> n >> k;
   int a[n];
   for (int i = 0; i < n; i++)cin >> a[i];
   priority_queue<int, vector<int>, greater<int>> pq;
   for (int i = 0; i < n; i++) {
      if (pq.size() < k)pq.push(a[i]);
      else if (pq.top() < a[i]) {pq.pop(); pq.push(a[i]);}
   }
   while (!pq.empty()) {
      cout << pq.top() << " ";
      pq.pop();
   }

}



int main() {
   FAST
   ll t = 1;
   cin >> t;
   while (t--)solve();
   return 0;
}