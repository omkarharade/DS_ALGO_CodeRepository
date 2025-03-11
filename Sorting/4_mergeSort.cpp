#include <bits/stdc++.h>
using namespace std;
#define nline "\n";


void merge(vector<int>& vec, int start, int mid, int end) {

	vector<int> temp(end - start + 1);

	int i = start, j = mid + 1, k = 0;

	// elements from start to mid - first array
	// elements from mid+1 to end - second array


	while (i <= mid and j <= end) {

		if (vec[i] <= vec[j]) {

			temp[k] = vec[i];
			i++;
			k++;
		}
		else {

			temp[k] = vec[j];
			j++;
			k++;
		}
	}

	while ( i <= mid ) {

		temp[k] = vec[i];
		k++;
		i++;
	}

	while (j <= end) {

		temp[k] = vec[j];
		k++;
		j++;
	}


	// now re-enter the sorted data back to original array

	for (int i = start; i <= end ; ++i)
	{
		vec[i] = temp[i - start];
	}
}


void merge_sort(vector<int>& vec, int start, int end) {

	if (start < end) {

		int mid = start + (end - start) / 2;

		// first half
		merge_sort(vec, start, mid);

		// second half
		merge_sort(vec, mid + 1, end);

		// merge these two sorted halfs
		merge(vec, start, mid, end);

	}
}


void printArray(vector<int>& vec, int n) {

	for (int i = 0; i < n; i++)
	{
		cout << vec[i] << " ";
	}
	cout << nline;
}


int main() {

	int n;
	cin >> n;

	vector<int> vec(n);

	for (int i = 0; i < n; ++i)
	{
		cin >> vec[i];
	}

	cout << "(merge sort output) \n" << nline;

	merge_sort(vec, 0, n - 1);
	printArray(vec, n);

	return 0;
}