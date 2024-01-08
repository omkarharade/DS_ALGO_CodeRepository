#include <bits/stdc++.h>
using namespace std;
#define nline "\n";

int n, m;
string a, b;

int dp[10001][1001];

int rec(int i, int j) {

	// returns the LCS of a[i.... n-1] and b[j.......m-1]

	// pruning



	// basecase
	if (i >= n or j >= m) return 0;



	// save and compute
	if (dp[i][j] != -1) return dp[i][j];


	// compute
	int ans = 0;

	ans = max(ans, rec(i + 1 , j));
	ans  = max(ans, rec(i, j + 1));

	if (a[i] == b[j]) {

		ans = max(ans, 1 + rec(i + 1, j + 1));
	}



	// save and return
	return dp[i][j] = ans;
}



int main() {

	cin >> n >> m;
	cin >> a >> b;

	memset(dp, -1, sizeof(dp));
	cout << rec(0, 0) << nline;


	return 0;
}