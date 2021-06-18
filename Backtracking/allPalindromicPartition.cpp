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

bool is_palindrome(string s) {
   for (int i = 0; i < s.size() / 2; i++) {
      if (s[i] != s[s.size() - 1 - i])return false;
   }
   return true;
}


void partition(string s, string output)
{
   if (s.size() == 0) {
      cout << output << endl;
      return;
   }
   int n = s.size();
   for (int i = 0; i < n; i++) {
      if (is_palindrome(s.substr(0, i + 1))) {
         partition(s.substr(i + 1, n - i - 1), output + "(" + s.substr(0, i + 1) + ")");
      }
   }
   return;
}

void solve()
{
   string s; cin >> s;
   string output = "";
   partition(s, output);
}


int main() {
   FAST
   ll t = 1;
   // cin >> t;
   while (t--)solve();
   return 0;
}


