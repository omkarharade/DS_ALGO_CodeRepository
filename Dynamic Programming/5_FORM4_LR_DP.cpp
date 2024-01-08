#include <bits/stdc++.h>
using namespace std;
#define nline "\n";

int n;
int x[1001];
int dp[1001][1001];

int rec(int l, int r) {

	// pruning

	// base case
	if (l + 1 == r) {
		return 0;
	}

	// cache check
	if (dp[l][r] != -1) return dp[l][r];


	// compute
	int ans = -1e9;

	for (int p = l + 1; p <= r - 1; ++p)
	{
		ans = min(ans, x[r] - x[l] + rec(l, p) + rec(p, r));
	}

	// save and return
	return dp[l][r] = ans;
}

int main() {

	cin >> n;

	for (int i = 1; i <= n; ++i)
	{
		cin >> x[i];
	}

	x[0] = 0;

	memset(dp, -1, sizeof(dp));

	cout << rec(0, n) << nline;

	return 0;
}