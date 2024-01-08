#include <bits/stdc++.h>
using namespace std;
#define nline "\n";

int main() {

	int n;
	cin >> n;

	vector<int> vec(n);

	for (int i = 0; i < n; ++i) cin >> vec[i];

	vector<int> dp(n, 1);

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < i; ++j)
		{
			if (vec[i] > vec[j]) {
				dp[i] = max(dp[i], 1 + dp[j]);
			}
		}
	}

	int ans = LLONG_MIN;

	for (int i = 0; i < n; ++i)
	{
		ans = max(ans, dp[i]);
	}

	cout << ans << nline;



	return 0;
}