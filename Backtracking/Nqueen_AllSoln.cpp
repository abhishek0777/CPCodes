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
int n;
int board[40][40];

bool isSafe(int r, int c)
{
   //left side
   for (int i = 0; i < c; i++) {
      if (board[r][i] == 1)return false;
   }
   //left upper diagonal
   for (int i = r - 1, j = c - 1; i >= 0 && j >= 0; i--, j--) {
      if (board[i][j] == 1)return false;
   }
   //left lower diagonal
   for (int i = r + 1, j = c - 1; i < n && j >= 0; i++, j--) {
      if (board[i][j] == 1)return false;
   }
   return true;
}


bool Nqueen(int col)
{
   if (col == n) {
      for (int i = 0; i < n; i++) {
         for (int j = 0; j < n; j++) {
            cout << board[i][j] << " ";
         }
         cout << endl;
      }
      cout << endl;
      return true;
   }
   bool res = false;
   for (int row = 0; row < n; row++) {
      if (isSafe(row, col)) {
         board[row][col] = 1;
         res = Nqueen(col + 1) || res;
         board[row][col] = 0;
      }
   }
   return res;
}

void solve()
{
   cin >> n;
   Nqueen(0);
}


int main() {
   FAST
   ll t = 1;
   // cin >> t;
   while (t--)solve();
   return 0;
}


