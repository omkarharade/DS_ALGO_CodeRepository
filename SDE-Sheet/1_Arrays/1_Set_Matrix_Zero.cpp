#include <bits/stdc++.h>
using namespace std;
#define nline "\n";


void setZeroes(vector<vector<int>>& matrix) {

	int col0 = 1, n = matrix.size(), m = matrix[0].size();

	for (int i = 0; i < n; i++ ) {

		for (int j = 0; j < n; j++) {

			if (matrix[i][j] == 0) {

				// marking for row number
				matrix[i][0] = 0;

				// marking for col number
				if (j == 0) col0 = 0;
				else matrix[0][j] = 0;
			}
		}
	}

	for (int i = 1; i < n; i++) {

		for (int j = 1; j < m; j++) {

			if (matrix[i][0] == 0) matrix[i][j] = 0;
			else if (matrix[0][j] == 0) matrix[i][j] = 0;

		}
	}

	if (col0 == 0) {

		for (int i = 0; i < n; i++) {

			matrix[i][0] = 0;
		}
	}

	if (matrix[0][0] == 0) {

		for (int i; i < m; i++) {

			matrix[0][i] = 0;
		}
	}
}

int main() {


	return 0;
}