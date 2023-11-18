#include <bits/stdc++.h>
using namespace std;
#define nline "\n";
typedef long long ll;


/*


Description

We have to paint n boards of length {A1, A2…An}. There are k painters available and each takes 1 unit
time to paint 1 unit of the board. The problem is to find the minimum time to get
this job done under the constraints that any painter will only paint continuous sections of boards.

Note:

2 painters cannot share a board to paint. A board cannot be painted partially by one painter, and partially by another.
A painter will only paint contiguous boards. If a painter paints board 1 and 3 but not 2 is invalid.

Input Format:

The first line contains a single integer T (1 ≤ T ≤ 100000) - the number of test cases.

The first line of each test case contains 2 space-separated
integers N, K (1 ≤ N ≤ 100000, 1 ≤ K ≤ 100000) - the number of boards and the number of painters.

The second line of each test case contains N space-separated
integers (0 ≤ xi ≤ 10^9) - the length of the boards.

Sum of N across all test cases ≤ 10^6.


Output Format:

For each test case print the minimum time required to complete the painting in a new line.


Sample Output 1:

5
5 2
1 2 3 4 5
5 3
2 5 7 2 5
5 1
1 2 3 4 5
5 5
1 2 3 4 5
5 4
1 7 2 3 5

Sample Input 2:

9
7
15
5
7


*/

bool check(ll time, ll k, vector<ll>& vec) {

	ll subarrayCnt = 1LL;
	ll currTime = 0LL;

	for (int i = 0; i < vec.size(); ++i)
	{

		if (currTime + vec[i] <= time) {
			currTime += vec[i];
		}
		else if (vec[i] <= time) {
			subarrayCnt++;
			currTime = vec[i];
		}
		else return 0;
	}

	//   if subarray count is less than k then we can break other subarray to match the condition
	//   however if the subarray which satisfy the conditions of subarray than the required subarray then
	//   there is no option to match the condition specified, hence the below condition

	return subarrayCnt <= k;
}

int main() {

	int t;
	cin >> t;

	while (t--) {

		ll n, k, sum = 0;
		cin >> n >> k;

		vector<ll> vec(n);

		for (int i = 0; i < n; ++i)
		{
			cin >> vec[i];
			sum += vec[i];
		}

		// binary search on time factor


		ll lo = 0, hi = sum, ans = -1;  // lo = max(vec);

		while ( lo <= hi) {

			ll mid = lo + (hi - lo) / 2;


			if (check(mid, k, vec)) {

				ans = mid;
				hi = mid - 1;
			}
			else lo = mid + 1;
		}

		cout << ans << nline;
	}


	return 0;
}

/*

 (non sublinear) Binary search on answer second form -- sweep check
 Time Complexity = O( log(hi - lo + 1) * O(check)) = O(n * log (sum(vec)))

 */