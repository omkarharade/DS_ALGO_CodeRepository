#include <bits/stdc++.h>
using namespace std;
#define nline "\n";

bool check(vector<int>& arr, int m, int currIndx) {

	return arr[currIndx] <= m;

}
int main() {

	int n;
	cin >> n;

	vector<int> x(n);

	for (int i = 0; i < n; ++i)
	{
		cin >> x[i];
	}

	sort(x.begin(), x.end());

	int q;
	cin >> q;

	while (q--) {

		int m;
		cin >> m;

		int lo = 0, hi = n - 1, ans = -1;

		while (lo <= hi) {

			int mid = lo + (hi - lo) / 2;

			if (check(x, m, mid)) {

				ans = mid;
				lo = mid + 1;

			}

			else hi = mid - 1;
		}

		cout << ans + 1 << nline;
	}

	return 0;
}