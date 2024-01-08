#include <bits/stdc++.h>
using namespace std;
#define nline "\n";


/*

problem link : https://atcoder.jp/contests/abc231/tasks/abc231_c

*/


bool check(vector<int>& arr, int currIndx, int minHeight) {

	return arr[currIndx] >= minHeight;
}


int main() {

	int n, q;
	cin >> n >> q;

	vector<int> A(n);

	for (int i = 0; i < n; ++i)
	{
		cin >> A[i];
	}

	sort(A.begin(), A.end());

	while (q--) {

		int x;
		cin >> x;

		int lo = 0, hi = n - 1, ans = n;

		while (lo <= hi) {

			int mid = lo + (hi - lo) / 2;

			if (check(A, mid, x)) {

				ans = mid;
				hi = mid - 1;
			}

			else lo = mid + 1;
		}


		cout << n - ans << nline;
	}


	return 0;
}