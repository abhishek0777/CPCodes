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
*/




int eggDroppingPuzzle(int e, int f)
{

   if (f == 1 || f == 0)return f;
   if (e == 1)return f;
   int ans = INT_MAX;
   for (int i = 1; i <= f; i++) {
      ans = min(ans, max(eggDroppingPuzzle(e - 1, i - 1), eggDroppingPuzzle(e, f - i))) ;
   }
   return ans + 1;
}

void solve()
{
   int e, f; cin >> e >> f;
   cout << eggDroppingPuzzle(e, f) << endl;
}


int main() {
   FAST
   ll t = 1;
   // cin >> t;
   while (t--)solve();
   return 0;
}


