#include <bits/stdc++.h>
using namespace std;
#define nline "\n";
typedef long long ll;

/*


Description

You are given N balls and an integer K. The color of each ball is given in an array A. A basket is filled if it contains at least K balls of different colors. Find the maximum number of filled baskets you can get if you optimally put the balls in the baskets.


Input Format

The first line contains T, the number of test cases (1<=T<=100000).

The first line contains three space-separated integers N, K where 1<=N<=10^5, 1<=K<=N.

Next line contains N space-separated integers (0<=Ai<=1e9).

Sum of N across all test cases <=10^6.


Output Format

For each test case output the maximum number of filled baskets in a new line.


Sample Input 1

3
5 5
1 2 3 4 5
5 2
1 2 3 4 5
6 3
1 2 2 1 3 3

Sample Output 1

1
2
2

Note

1st test case:
1st basket -> {1,2,3,4,5}

2nd test case:
1st basket -> {1,2,3}
2nd basket -> {4,5}

3rd test case:
1st basket -> {1,2,3}
2nd basket -> {1,2,3}


*/

bool check(unordered_map<ll, ll>& ump, ll x, ll k) {

	ll distinctColors = 0LL;
	ll restAllColorCount = 0LL;

	for (auto m : ump) {

		if (m.second >= x) distinctColors++;
		else restAllColorCount += m.second;
	}

	return distinctColors + (restAllColorCount / x) >= k;
}


void solve() {

	ll n, k;
	cin >> n >> k;

	vector<ll> vec(n);
	unordered_map<ll, ll> ump;
	ll sumofAllColors = n;

	for (int i = 0; i < n; ++i)
	{
		cin >> vec[i];
		ump[vec[i]]++;
	}

	ll lo = 1, hi = sumofAllColors, ans = 0;

	while ( lo <= hi ) {

		ll mid = lo + (hi - lo) / 2;


		if (check(ump, mid, k)) {

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