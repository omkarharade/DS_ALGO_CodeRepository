#include <bits/stdc++.h>
using namespace std;
#define nline "\n";


int lower_bound(vector<int>& vec, int n, int target) {

	int lo = -1, hi = n;

	while (lo + 1 < hi) {

		int mid = lo + (hi - lo) / 2;

		if (vec[mid] >= target) {

			hi = mid;
		}
		else {

			lo = mid;
		}
	}

	if (vec[lo] == target) return lo; // edge case for first element as target
	else return hi;
}


int upper_bound(vector<int>& vec, int n, int target) {

	int lo = -1, hi = n;

	while (lo + 1 < hi) {

		int mid = lo + (hi - lo) / 2;

		if (vec[mid] <= target) {

			lo = mid;
		}
		else {

			hi = mid;
		}
	}

	return hi;
}



int main() {

	int n, target;
	cin >> n >> target;

	vector<int> vec(n);

	for (int i = 0; i < n; ++i)
	{
		cin >> vec[i];
	}

	cout << "lower_bound index is " << lower_bound(vec, n, target) << nline;
	cout << "upper_bound index is " << upper_bound(vec, n, target) << nline;
	return 0;
}