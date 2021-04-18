/*
Problem: Maximum sum of elements in array such that no two elements which are contributing to the sum contiguous
Given: a[i] is positive

RECURSIVE APPROACH(interesting):
Lets say we have an array of n elements,
=> start processing elements from back side
=> Have two choices,either pick nth elements or not
=> if pick call function for (arr,n-2)
=> else call function for (arr,n-1)
=>base cases if n==1 return arr[0]
=> if n==2 return max(arr[0],arr[1])


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

ll maxSUM(ll a[], ll n)
{
	if (n == 1)return a[0];
	else if (n == 2)return max(a[0], a[1]);
	else
	{
		return max(maxSUM(a, n - 1), maxSUM(a, n - 2) + a[n - 1]);
	}
}

void solve()
{
	ll n; cin >> n;
	ll a[n];
	for (ll i = 0; i < n; i++)cin >> a[i];

	vector<ll> dp(n + 1, 0);
	dp[1] = a[0];
	if (n > 1)
	{
		dp[2] = max(a[0], a[1]);
		for (ll i = 3; i <= n; i++) {
			dp[i] = max(dp[i - 1], dp[i - 2] + a[i - 1]);
		}
	}
	cout << dp[n];
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









