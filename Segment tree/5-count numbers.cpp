// Count elements which divide all numbers in range L-R
// Link : https://www.geeksforgeeks.org/count-elements-which-divide-all-numbers-in-range-l-r/
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

struct triplet {
	/*min,count,gcd*/
	ll first = 0, second = 0, third = 0;
};


vector<triplet> segTree(10000);
vector<ll> a(2500);

ll CSTMin(ll s, ll e, ll si) {
	if (s == e) {
		return segTree[si].first = a[s];
	}
	ll mid = (s + e) / 2;
	return segTree[si].first = min(CSTMin(s, mid, 2 * si + 1), CSTMin(mid + 1, e, 2 * si + 2));
}

ll CSTCount(ll s, ll e, ll si)
{
	if (s == e) {
		return segTree[si].second = 1;
	}
	ll mid = (s + e) / 2;
	ll lc = CSTCount(s, mid, 2 * si + 1);
	ll rc = CSTCount(mid + 1, e, 2 * si + 2);
	if (segTree[2 * si + 1].first < segTree[2 * si + 2].first)
		segTree[si].second = lc;
	else if (segTree[2 * si + 1].first > segTree[2 * si + 2].first)
		segTree[si].second = rc;
	else
		segTree[si].second = lc + rc;
	return segTree[si].second;
}

ll CSTGcd(ll s, ll e, ll si)
{
	if (s == e) {
		return segTree[si].third = a[s];
	}
	ll mid = (s + e) / 2;
	return segTree[si].third = __gcd(CSTGcd(s, mid, 2 * si + 1), CSTGcd(mid + 1, e, 2 * si + 2));
}

ll getCount(ll qs, ll qe, ll s, ll e, ll si)
{
	if (qe < s || qs > e)return 0;
	if (s >= qs && e <= qe)return segTree[si].second;
	ll mid = (s + e) / 2;
	if (segTree[2 * si + 1].first < segTree[2 * si + 2].first)return getCount(qs, qe, s, mid, 2 * si + 1);
	else if (segTree[2 * si + 1].first > segTree[2 * si + 2].first)return getCount(qs, qe, mid + 1, e, 2 * si + 2);
	else return (getCount(qs, qe, s, mid, 2 * si + 1) + getCount(qs, qe, mid + 1, e, 2 * si + 2));
}

ll getMin(ll qs, ll qe, ll s, ll e, ll si)
{
	if (qe < s || qs > e)return INT_MAX;
	if (s >= qs && e <= qe)return segTree[si].first;
	ll mid = (s + e) / 2;
	return min(getMin(qs, qe, s, mid, 2 * si + 1), getMin(qs, qe, mid + 1, e, 2 * si + 2));
}

ll getGcd(ll qs, ll qe, ll s, ll e, ll si)
{
	if (qe < s || qs > e)return 0;
	if (s >= qs && e <= qe)return segTree[si].third;
	ll mid = (s + e) / 2;
	return __gcd(getGcd(qs, qe, s, mid, 2 * si + 1), getGcd(qs, qe, mid + 1, e, 2 * si + 2));
}


void solve()
{
	ll n; cin >> n;
	for (ll i = 0; i < n; i++)cin >> a[i];
	CSTMin(0, n - 1, 0);
	CSTCount(0, n - 1, 0);
	CSTGcd(0, n - 1, 0);
	ll q; cin >> q;
	while (q--) {
		ll l, r; cin >> l >> r;
		if (getGcd(l, r, 0, n - 1, 0) == getMin(l, r, 0, n - 1, 0)) {
			cout << getCount(l, r, 0, n - 1, 0) << endl;
		}
		else cout << "0" << endl;
	}
}

int main() {
	FAST
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	ll t = 1;
	// cin >> t;
	while (t--)solve();
	return 0;
}