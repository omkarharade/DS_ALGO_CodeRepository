#include <bits/stdc++.h>
using namespace std;
#define nline "\n";


void printArray(vector<int>& vec, int n) {

	for (int i = 0; i < n; i++)
	{
		cout << vec[i] << " ";
	}

	cout << nline;

}

// bubble sort iterative -  T/C : O(N^2)
void bubbleSort(vector<int>& vec, int n) {


	for (int i = 0; i < n - 1; ++i)
	{
		bool is_swapped = false;

		for (int j = 0; j < n - i - 1; ++j)
		{
			if (vec[j] > vec[j + 1]) {

				// swap and update status

				swap(vec[j], vec[j + 1]);
				is_swapped = true;
			}
		}

		if (not is_swapped) {
			// array is sorted
			break;
		}
	}

}


void bubbleSortRecur(vector<int> &vec, int i, int n) {

	if (n == 1) return;
	if (i == n - 1) {

		// if reached last index then start again from 0th index
		// with currLast - 1 element as the new lastElement

		bubbleSortRecur(vec, 0, n - 1);
		return;
	}

	// swap if first element is greater than other
	if (vec[i] > vec[i + 1]) {
		swap(vec[i], vec[i + 1]);
	}

	// move the index forward
	bubbleSortRecur(vec, i + 1, n);

}


int main() {

	int n;
	cin >> n;

	vector<int> vec(n);

	for (int i = 0; i < n; ++i)
	{
		cin >> vec[i];
	}

	bubbleSort(vec, n);
	// bubbleSortRecur(vec, 0, n);
	printArray(vec, n);


	return 0;
}