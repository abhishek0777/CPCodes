/*
0->1
1->1
2->2
3->5
4->14

int the below eq,one key is used for root,remaining n-1 is partioned into two child subtree
res(n)=res(0)*res(n-1)+res(1)*res(n-2)+......+res(n-1)*res(0)
res(n)=i=0 to n-1 sigma res(i)*res(n-1-i)
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

void solve()
{
	ll n; cin >> n;
	ll dp[n + 1] = {};
	dp[0] = 1;
	for (ll i = 1; i <= n; i++)
	{
		dp[i] = 0;
		for (ll j = 0; j < i; j++) {
			dp[i] += dp[j] * dp[i - 1 - j];
		}
	}
	cout << dp[n] << endl;
}


int main() {
	FAST
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	ll t = 1;
	cin >> t;
	while (t--)solve();
	return 0;
}


