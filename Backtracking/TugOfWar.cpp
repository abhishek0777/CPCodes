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
   1.Generate all subsets of size n/2
   2.Find best of them
   3. print answer for it
*/
int n;
int a[20];
bool is[20];


void tugOfWar()
{
   int sum1 = 0, sum2 = 0, sum = 0, diff = INT_MAX;
   for (int i = 0; i < n; i++)sum += a[i];

   for (int subsets = 0; subsets < (1 << n); subsets++) {
      if (__builtin_popcount(subsets) == n / 2) {
         sum1 = 0;
         for (int j = 0; j < n; j++) {
            if (subsets & (1 << j))sum1 += a[j];
         }
         sum2 = sum - sum1;
         if (abs(sum1 - sum2) < diff) {
            for (int j = 0; j < n; j++) {
               is[j] = 0;
               if (subsets & (1 << j))is[j] = 1;
            }
            diff = abs(sum1 - sum2);
         }
      }
   }
}
void solve()
{
   cin >> n;
   for (int i = 0; i < n; i++)cin >> a[i];
   tugOfWar();

   cout << "set-1 : ";
   for (int i = 0; i < n; i++) {
      if (is[i])cout << a[i] << " ";
   }
   cout << endl;
   cout << "set-2 : ";
   for (int i = 0; i < n; i++) {
      if (!is[i])cout << a[i] << " ";
   }
}


int main() {
   FAST
   ll t = 1;
   // cin >> t;
   while (t--)solve();
   return 0;
}


