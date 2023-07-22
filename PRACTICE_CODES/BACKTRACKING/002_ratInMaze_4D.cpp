#include <bits/stdc++.h>
using namespace std;
#define nline "\n";


bool isSafe(int i, int j, int n, int m) {

	return (i < n and i >= 0 and j < m and j >= 0);
}

int paths(int r, int c, int n, int m, vector<vector<bool>>& vis) {

	if (!isSafe(r, c, n, m)) return 0;
	if (vis[r][c]) return 0;
	if (r == n - 1 and c == m - 1) return 1;

	vis[r][c] = 1;

	int waysCount = 0;

	waysCount += paths(r + 1, c, n, m, vis);
	waysCount += paths(r - 1, c, n, m, vis);
	waysCount += paths(r, c + 1, n, m, vis);
	waysCount += paths(r, c - 1, n, m, vis);

	vis[r][c] = 0;
	return waysCount;
}

int main() {

	int n, m;
	cin >> n >> m;

	vector<vector<bool>> vis(n, vector<bool>(m, 0));

	cout << paths(0, 0, n, m, vis) << nline;

	return 0;
}