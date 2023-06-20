#include <bits/stdc++.h>
using namespace std;
#define nline "\n";

int totalWays = 0;

bool isSafe(int r, int c, int n, int m) {
	return r < n and c < m and r >= 0 and c >= 0;
}

void gridPaths(int n, int m, int currR, int currC, string path) {

	if (!isSafe(currR, currC, n, m)) {
		return;
	}

	if ((currR == n - 1) and (currC == m - 1)) {

		cout << path << nline;
		totalWays++;
		return;
	}

	gridPaths(n, m, currR, currC + 1, path + 'R');
	gridPaths(n, m, currR + 1, currC, path + 'D');
}

int main() {

	int n, m;
	cin >> n >> m;

	gridPaths(n, m, 0, 0, "");

	cout << "\n" << "Total ways are : " << totalWays << nline;
	return 0;
}