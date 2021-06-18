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
   multiset<int> mset;
   for (int i = 0; i < k; i++) {
      mset.insert(a[i]);
   }
   vector<int> ans;
   ans.push_back(*(--mset.end()));
   for (int i = k; i < n; i++) {
      mset.insert(a[i]);
      mset.erase(mset.find(a[i - k]));
      ans.push_back(*(--mset.end()));
   }
   for (int x : ans)cout << x << " ";

}



int main() {
   FAST
   ll t = 1;
   cin >> t;
   while (t--)solve();
   return 0;
}