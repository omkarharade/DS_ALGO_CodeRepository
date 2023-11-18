#include <bits/stdc++.h>
using namespace std;
#define nline "\n";

/*

Description

Given a binary array of length N. The score of an array is the length of the longest continuous subsegment consisting of only one.

Find the maximum score possible if you can change at most K elements of the array.


Input Format

The first line contains an integer T, the number of test cases.
The first line of each test case contains two space-separated integer N, K where
The next line contains N space-separated integers which are either 0 or 1.


Output Format

For each test case print the maximum score possible if you can change at most K elements of the array in a new line.


Constraints

1 ≤ T ≤ 104
1 ≤ N ≤ 105
0 ≤ K ≤ N
Sum of N across all test cases ≤ 106.


Sample Input 1

5
10 2
1 0 1 1 0 1 1 0 0 1
10 1
1 1 0 1 0 0 0 1 0 0
10 3
1 0 0 1 1 0 1 1 0 1
10 3
1 1 1 0 0 0 1 1 1 1
10 3
1 1 0 0 1 1 0 0 1 1

Sample Output 1

7
4
8
10
7

*/

int numZeroes(vector<int> &prefx, int l, int r) {

	return prefx[r] - (l == 0 ? 0 : prefx[l - 1]);
}

bool check(int start, int end, vector<int>&prefx, int k) {

	return numZeroes(prefx, start, end) <= k;
}


void solve() {

	int n, k;
	cin >> n >> k;

	vector<int> vec(n), prefx(n);
	int maxSubArrayLen = 0LL;

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


			if (check(start, mid, prefx, k)) {
				ans = mid;
				lo = mid + 1;
			}

			else hi = mid - 1;
		}


		maxSubArrayLen  = max(maxSubArrayLen, (ans - start + 1)) ;
		// the false negative in case when we keep ans = 0 by default will add +1 to total

	}

	cout << maxSubArrayLen << nline;


}


int main() {

	int t;
	cin >> t;

	while (t--) {

		solve();
	}
	return 0;
}