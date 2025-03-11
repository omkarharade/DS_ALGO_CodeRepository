#include <bits/stdc++.h>
using namespace std;
#define nline "\n";

/*

question is to find no. of rotations of a circular sorted array

observation : the no. of rotations is exactly the index of smallest element
			  in the array

			  so question condense to find the index of smallest element of array

*/

int func(vector<int>& vec, int n) {

	int lo = 0, hi = n - 1, ans = 0;

	while (lo <= hi) {

		cout << "lo = " << lo << ", hi = " << hi << nline;
		int mid = lo + (hi - lo) / 2;

		if (vec[lo] > vec[mid]) {
			cout << "if" << nline;
			ans = mid;
			hi = mid - 1; // shift left
		}
		else {

			lo = mid + 1;
		}
	}

	return ans;
}
int main() {

	int n;
	cin >> n;

	vector<int> vec(n);


	for (int i = 0; i < n; ++i)
	{
		cin >> vec[i];
	}

	cout << "no. of rotations are " << func(vec, n) << nline;

	return 0;
}