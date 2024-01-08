#include <bits/stdc++.h>
using namespace std;
#define nline "\n";


bool check(long long element, long long n, long long k) {

	return element - (element / n) >= k;

}

void solve() {

	int n, k;
	cin >> n >> k;


	long long lo = 1,  hi = 1e18 + 5, ans  = -1;

	while (lo <= hi) {

		long long mid = lo + (hi - lo) / 2;

		if (check(mid, n, k)) {

			ans = mid;
			hi = mid - 1;
		}
		else {

			lo = mid + 1;
		}
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