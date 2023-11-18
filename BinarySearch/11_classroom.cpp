#include <bits/stdc++.h>
using namespace std;
#define nline "\n";
typedef long long ll;

bool check(vector<ll>& vec, ll x, ll k) {

	ll placedStudents = 1;
	ll currPlacedPos = vec[0];

	for (int i = 1; i < vec.size(); ++i)
	{
		if (vec[i] - currPlacedPos >= x) {
			placedStudents++;
			currPlacedPos = vec[i];
		}
	}

	return placedStudents >= k;
}

void solve() {

	ll n, k;
	cin >> n >> k;

	vector<ll> vec(n);
	ll minAdjDiff = LLONG_MAX;


	for (int i = 0; i < n; ++i)
	{
		cin >> vec[i];
	}

	sort(vec.begin(), vec.end());

	for (int i = 1; i < n; ++i)
	{
		minAdjDiff = min(vec[i] - vec[i - 1], minAdjDiff);
	}


	ll lo = minAdjDiff, hi = vec[n - 1] - vec[0], ans = minAdjDiff;

	while (lo <= hi) {

		ll mid = lo + (hi - lo) / 2;


		if (check(vec, mid, k)) {

			ans = mid;
			lo = mid + 1;
		}

		else hi = mid - 1;
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