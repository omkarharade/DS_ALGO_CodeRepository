#include <bits/stdc++.h>
using namespace std;
#define nline "\n";
typedef long long ll;

/*

Description

You are given N distinct points on the number line in a sorted array A. You can place at most K more points on the Line
(Integer coordinates only). You have to make the maximum separation between any two consecutive points in the final
 configuration as minimum as possible. Output this minimal value.

Note - You can place the points anywhere you like, but you cannot place more than one point at the same position on the line.


Input Format:

The first line contains an integer T, the number of test cases (1<=T<=10000).

The first line of each test case contains two space-separated integers N, K, 2<=N<=10^5, 0<=K<=10^9.

Next line contains N space-separated distinct integers (0<=Ai<=1e9).

Sum of N across all test cases <= 10^6.


Output Format:

For each test case output the minimum maximum separation between any two consecutive points possible in a new line.


Sample Input 1:

5
5 5
1 2 3 4 5
5 0
2 5 7 8 10
3 2
100 200 230
6 5
1 3 5 7 9 11
6 4
1 4 8 13 19 26


Sample Output 1:

1
3
34
1
4



Note

For the first test case - do not place any additional points or place points at 6,7.

For the third test case - place the points at 133, 166. So final
configuration = [100, 133, 166, 200, 230] and maximum difference between two consecutive numbers = 34.

For fourth test case - place the points at 2, 4, 6, 8, 10.
So final configuration = [1,2,3,4,5,6,7,8,9,10,11] and maximum difference between two consecutive numbers = 1.


*/

bool check(ll dist, ll k, vector<ll>& vec) {

	ll currPoints = 0LL;

	for (int i = 1; i < vec.size(); ++i)
	{
		ll adjacentDist = vec[i] - vec[i - 1];

		// (ceil division) - 1  ...... no. of points can be placed such that dist between points
		// is <= dist

		currPoints += (((adjacentDist + dist - 1) / dist) - 1);
	}

	return currPoints <= k;
}

int main() {

	int t;
	cin >> t;

	while (t--) {

		ll n, k;
		cin >> n >> k;

		vector<ll> vec(n);

		ll maxInitDist = LLONG_MIN;

		for (int i = 0; i < n; ++i)
		{
			cin >> vec[i];
		}

		for (int i = 1; i < n; ++i)
		{
			if (vec[i] - vec[i - 1] > maxInitDist) {
				maxInitDist = vec[i] - vec[i - 1];
			}
		}


		ll lo = 1, hi = maxInitDist, ans = maxInitDist;

		while ( lo <= hi ) {

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
 Time Complexity = O( log(hi - lo + 1) * O(check)) = O(n * log (maxInitDiff.))

*/