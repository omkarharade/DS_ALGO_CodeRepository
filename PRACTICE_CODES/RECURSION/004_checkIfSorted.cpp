#include <bits/stdc++.h>
using namespace std;
#define nline "\n";

// check if array is sorted or not using recursion

bool isSorted(int arr[], int n, int currIndx) {

	if (currIndx == n - 1) {
		return true;
	}

	if (isSorted(arr, n, currIndx + 1) and (arr[currIndx] <= arr[currIndx + 1])) {
		return true;
	}
	else return false;
}

int main() {

	int n;
	cin >> n;

	int arr[n];

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	cout << (isSorted(arr, n, 0) ? "array is sorted" : "array is not sorted") << nline;
	return 0;
}