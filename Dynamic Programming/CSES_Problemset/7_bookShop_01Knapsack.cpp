#include <bits/stdc++.h>
using namespace std;
#define nline "\n"


void file_i_o()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("error.txt", "w", stderr);
#endif
}


void solve() {
	// solve here....

	int n, budget;
	cin >> n >> budget;

	vector<int> cost(n), pages(n);

	for (int i = 0; i < n; ++i)
	{
		cin >> cost[i];
	}


	for (int i = 0; i < n; ++i)
	{
		cin >> pages[i];
	}

	vector<vector<int>> dp(n, vector<int>(budget + 1));

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j <= budget; j++) {

			if (i == 0) {
				dp[i][j] = (j < cost[i] ? 0 : pages[i]);
			}
			else {

				if (j < cost[i]) {
					dp[i][j] = dp[i - 1][j];
				}
				else {
					int maxPages = 0;

					maxPages = max(maxPages, dp[i - 1][j - cost[i]] + pages[i]);
					maxPages = max(maxPages, dp[i - 1][j]);
					dp[i][j] = maxPages;
				}
			}
		}
	}

	cout << dp[n - 1][budget];


}

int main()
{
	clock_t begin = clock();
	file_i_o();
	// Write your code here....

	int t = 1;
	// cin >> t;

	while (t-- > 0)
	{
		solve();
	}

#ifndef ONLINE_JUDGE
	clock_t end = clock();
	cout << "\n\nExecuted In: " << double(end - begin) / CLOCKS_PER_SEC * 1000 << " ms";
#endif
	return 0;
}