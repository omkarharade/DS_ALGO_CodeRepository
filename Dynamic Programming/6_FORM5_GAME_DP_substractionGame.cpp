#include <bits/stdc++.h>
using namespace std;
#define nline "\n";

int dp[100100];

int rec(int x) {

	// pruning

	// base case
	if (x == 0) return 0;


	// cache check
	if (dp[x] != -1) {
		return dp[x];
	}



	// compute
	int ans = 0;

	for (int m = 0; (1 << m) <= x; m++) {

		if (rec(x - (1 << m)) == 0) {
			ans = 1;
			break;
		}
	}

	// save and return
	return ans;
}

int main() {

	int n;
	cin >> n;

	memset(dp, -1, sizeof(dp));

	for (int i = 0; i < 10; ++i)
	{
		cout <<  i << " " << rec(i) << nline;
	}

	/*

	if (n % 3 == 0) {
		cout << "Lose" << nline;
	}
	else {
		cout << "Win" << nline;
	}

	*/


	return 0;
}