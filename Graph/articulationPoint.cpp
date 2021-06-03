/*
    Input test case:
    5 5
    0 1
    0 2
    2 3
    3 4
    1 2
*/
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
vector<int> adj[100005];
vector<bool> vis(100005, false);
set<int> aps;
int timer = 1;
vector<int> disc(100005, 0), low(100005, 0);

void dfs(int u, int p)
{
  vis[u] = true;
  disc[u] = low[u] = timer++;
  int childrens = 0;
  for (int v : adj[u]) {
    if (!vis[v]) {
      dfs(v, u);
      low[u] = min(low[u], low[v]);
      if (low[v] >= disc[u] && (p != -1)) {
        aps.insert(u);
      }
      childrens++;
    }
    else if (v != p) {
      low[u] = min(low[u], disc[v]);
    }
  }
  if (p == -1 && childrens > 1) {
    aps.insert(u);
  }
}
void solve()
{
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int u, v; cin >> u >> v;
    adj[u].pb(v);
    adj[v].pb(u);
  }
  for (int i = 0; i < n; i++) {
    if (!vis[i])dfs(i, -1);
  }
  for (int x : aps)cout << x << " ";

}

int main() {
  FAST
  ll t = 1;
  // cin >> t;
  while (t--)solve();
  return 0;
}



