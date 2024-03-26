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


void insertionSort(vector<int>& vec, int n) {

	for (int i = 1; i < n; ++i)
	{
		int el = vec[i];
		int j = i - 1;

		// check for the right position for element - el

		// if prev elements less than el -> push elements forward
		while (j >= 0 and vec[j] > el ) {

			vec[j + 1] = vec[j];
			j--;
		}

		// set element to right position
		vec[j + 1] = el;
	}
}


int main() {

	int n;
	cin >> n;

	vector<int> vec(n);

	for (int i = 0; i < n; ++i)
	{
		cin >> vec[i];
	}

	insertionSort(vec, n);
	printArray(vec, n);



	return 0;
}