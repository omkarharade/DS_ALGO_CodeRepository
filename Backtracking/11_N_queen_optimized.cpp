#include <bits/stdc++.h>
using namespace std;
#define nline "\n";

int countAns = 0;
bitset<100> col, ld, rd; // left diagonal , right diagonal


/*


	underlying logic is that :

	left diagonal elements have a relation that difference between
	row and columns are constant

	right diagonal elements have a relation that addition \
	of row and column are constant


*/



void countNQueen(int currRow, int n) {

	if (currRow == n) {

		countAns++;
	}

	for (int i = 0; i < n; i++)
	{
		if (!col[i] and !ld[currRow - i + n - 1] and !rd[currRow + i]) {

			col[i] = ld[currRow - i + n - 1] = rd[currRow + i] = 1;
			countNQueen(currRow + 1, n);
			col[i] = ld[currRow - i + n - 1] = rd[currRow + i] = 0;
		}
	}

}

int main() {

	int n;
	cin >> n;
	countNQueen(0, n);
	cout << countAns << endl;
	return 0;
}