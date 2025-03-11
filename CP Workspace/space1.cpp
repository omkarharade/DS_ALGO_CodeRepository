#include <bits/stdc++.h>
using namespace std;
#define nline "\n";



// implement bubble sort all variations you know

void printArray(vector<int>&vec, int n) {

	for (int i = 0; i < n; ++i)
	{
		cout << vec[i] << " ";
	}

	cout << nline;
}



void bubble_sort(vector<int>& vec, int n) {


	// first loop sets the second last element to be checked
	// as last element is compared with 2nd last

	for (int i = n - 2; i >= 0; i--) {

		// then loop to compare every element till the i-th element is compared

		for (int j = 0; j <= i; j++) {

			// if element in the left is greater, swap those elements values

			if (vec[j] > vec[j + 1]) {

				swap(vec[j], vec[j + 1]);

			}
		}
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

	bubble_sort(vec, n);

	printArray(vec, n);


	return 0;
}