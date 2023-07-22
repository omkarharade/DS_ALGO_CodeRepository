#include <bits/stdc++.h>
using namespace std;
#define nline "\n";


// boundary check function
bool isSafe(int i, int j, int n, int m) {

	return i < n and j < m and i >= 0 and j >= 0;
}

void printPaths(vector<vector<int>>& grid, int i, int j, int n, int m, vector<int>& path, int pIndx) {

	// base case #1
	if (!isSafe(i, j, n, m)) return;

	// base case #2: print the path on reaching bottom right
	if (i == n - 1 and j == m - 1) {

		path[pIndx] = grid[i][j];

		for (int i = 0; i <= pIndx; ++i)
		{
			cout << path[i] << " ";
		}
		cout << nline;
	}

	path[pIndx] = grid[i][j];

	// path downwards
	printPaths(grid, i + 1, j, n, m, path, pIndx + 1);

	// path rightwards
	printPaths(grid, i, j + 1, n, m, path, pIndx + 1);

	path[pIndx] = 0;
}


int main() {

	int n, m;
	cin >> n >> m;

	vector<vector<int>> grid(n, vector<int>(m, 0));
	vector<int> path(m + n, 0);

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			cin >> grid[i][j];
		}
	}

	printPaths(grid, 0, 0, n, m, path, 0);



	return 0;
}