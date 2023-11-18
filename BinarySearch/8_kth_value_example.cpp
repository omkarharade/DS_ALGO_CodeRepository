#include <bits/stdc++.h>
using namespace std;
#define nline "\n";
typedef long long ll;

bool check(ll x, ll k, vector<ll>& a, vector<ll>& b, ll n, ll m) {

	ll noOfElements = 0; // satisfying the condition { :. no. elements whose value <= x are >= k}

	for (int i = 0; i < n; ++i)
	{
		noOfElements += (upper_bound(b.begin(), b.end(), x - a[i]) - b.begin());
	}

	// this gives all the elements in array C (a[i] + b[j]) <= x
	// to get the kth element noOfElements should be >= k

	return noOfElements >= k;
}


// check function values for given x is like {F, F, F, F, F, T, T, T, T, T, T}


void solve() {

	ll n, m, k;
	cin >> n >> m >> k;

	vector<ll> a(n), b(m);

	for (int i = 0; i < n; ++i)
	{
		cin >> a[i];
	}

	for (int i = 0; i < m; ++i)
	{
		cin >> b[i];
	}

	sort(a.begin(), a.end());
	sort(b.begin(), b.end());

	if (a.size() > b.size()) {

		swap(a, b);
		swap(n, m);
	}

	ll lo = a[0] + b[0], hi = a[n - 1] + b[m - 1], ans = hi;

	while ( lo <= hi ) {

		ll mid = lo + (hi - lo) / 2;

		if (check(mid, k, a, b, n, m)) {

			ans = mid;
			hi = mid - 1;
		}
		else lo = mid + 1;
	}

	cout << ans << nline;

}


int main() {

	int t;
	cin >> t;

	while (t--) {

		solve();
	}

	return 0;
}