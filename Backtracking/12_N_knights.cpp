#include <bits/stdc++.h>
using namespace std;
#define nline "\n";
#define vvb vector<vector<bool>>
#define vvi vector<vector<int>>

int countAns = 0;

void display(vector<vector<bool>> &grid, int n) {
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (grid[i][j]) {
				cout << "K ";
			}
			else
				cout << ". ";
		}
		cout << "\n";
	}
	cout << "\n\n";
}

bool isSafe(int r, int c, vvb& grid, int n) {

	if (r - 2 >= 0 and c - 1 >= 0 and grid[r - 2][c - 1]) return false;
	if (r - 2 >= 0 and c + 1 < n and grid[r - 2][c + 1]) return false;
	if (r - 1 >= 0 and c - 2 >= 0 and grid[r - 1][c - 2]) return false;
	if (r - 1 >= 0 and c + 2 < n and grid[r - 1][c + 2]) return false;

	return true;
}

void nKnights(vvb& grid, int r, int c, int n, int knightCount) {

	if (knightCount == n) {
		display(grid, n);
		countAns++;
		return;
	}


	for (int i = r; i < n; ++i)
	{
		// if row is the row r which is passed as parameter start from column c,
		// else start from colum 0

		for (int j = (i == r ? c : 0) ; j < n; ++j)
		{
			if (isSafe(i, j, grid, n)) {

				grid[i][j] = 1;
				nKnights(grid, i, j + 1, n, knightCount + 1);
				grid[i][j] = 0;

			}
		}
	}
}

int main() {

	int n;
	cin >> n;
	cout << n << nline;

	vvb grid(n, vector<bool>(n, 0));
	nKnights(grid, 0, 0, n, 0);
	cout << countAns << nline;

	return 0;
}