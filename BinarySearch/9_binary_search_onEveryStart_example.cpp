#include <bits/stdc++.h>
using namespace std;
#define nline "\n";

/*

Description

Given a binary array of length N. Count number of subarrays which consists of 1s
if you can change at most K elements of the array from 0 to 1.


Input Format

The first line contains an integer T, the number of test cases.
The first line of each test case contains two space-separated integer N, K where
The next line contains N space-separated integers which are either 0 or 1.


Output Format

For each test case print the total number of subarrays possible if you can change
at most K elements of the array in a new line.


*/

int numZeroes(vector<int> prefx, int l, int r) {

	return prefx[r] - (l == 0 ? 0 : prefx[l - 1]);
}

bool check(int start, int end, vector<int>&prefx, int k) {

	return numZeroes(prefx, start, end) <= k;
}


void solve() {

	int n, k;
	cin >> n >> k;

	vector<int> vec(n), prefx(n);
	long long total = 0LL;

	for (int i = 0; i < n; ++i)
	{
		cin >> vec[i];

		vec[i] = 1 - vec[i]; // swap 0s and 1s for simplicity in counting no. of 0s

	}

	for (int i = 0; i < n; ++i)
	{
		prefx[i] = vec[i] + (i == 0 ? 0 : prefx[i - 1]);
	}


	for (int start = 0; start < n; ++start)
	{
		int lo = start;
		int hi = n - 1;
		int ans = start - 1; // putting ans = 0 can lead to false positive (ie. it will consider first element as a valid value)

		while (lo <= hi) {

			int mid = lo + (hi - lo) / 2;

			if (check(start, mid, vec, k)) {

				ans = mid;
				lo = mid + 1;
			}

			else hi = mid - 1;
		}


		total += (ans - start + 1);  // the false negative in case when we keep ans = 0 by default will add +1 to total

	}

	cout << total << nline;


}


int main() {

	int t;
	cin >> t;

	while (t--) {

		solve();
	}
	return 0;
}