#include <bits/stdc++.h>
using namespace std;
#define nline "\n";

bool isSafe(int row, int col, int m, int n) {
	return row < m and col < n and row >= 0 and col >= 0;
}


bool partialExist(vector<vector<char>>& board, string& word, vector<vector<bool>>& vis, int row, int col, int m, int n, int wordIndx) {

	if (wordIndx == word.length()) return true;

	if (!isSafe(row, col, m, n)) return 0;
	if (vis[row][col]) return 0;

	if (board[row][col] != word[wordIndx]) return 0;
	vis[row][col] = 1;

	bool doesExists = 0;

	doesExists = doesExists or partialExist(board, word, vis, row + 1, col, m, n, wordIndx + 1);

	doesExists = doesExists or partialExist(board, word, vis, row - 1, col, m, n, wordIndx + 1);

	doesExists = doesExists or partialExist(board, word, vis, row, col + 1, m, n, wordIndx + 1);

	doesExists = doesExists or partialExist(board, word, vis, row, col - 1, m, n, wordIndx + 1);

	vis[row][col] = 0;
	return doesExists;
}


bool exist(vector<vector<char>>& board, string word) {

	int m = board.size();
	int n = board[0].size();
	bool doesExists = 0;
	int wordIndx = 0;

	vector<vector<bool>> vis(m, vector<bool>(n, 0));

	for (int i = 0; i < m; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			if (word[wordIndx] == board[i][j] and partialExist(board, word, vis, i, j, m, n, wordIndx)) {
				return true;
			}
		}
	}

	return false;
}

int main() {

	int m, n;
	cin >> m >> n;

	vector<vector<char>> board(m, vector<char>(n));
	string word;

	for (int i = 0; i < m; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			cin >> board[i][j];
		}
	}

	cin.ignore();
	cin >> word;

	cout <<  (exist(board, word) ? "true" : "false") << nline;
	return 0;
}