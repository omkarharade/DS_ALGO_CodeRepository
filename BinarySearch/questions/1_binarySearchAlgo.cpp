#include <bits/stdc++.h>
using namespace std;
#define nline "\n";

int binary_search_iter(vector<int>& vec, int n, int target) {

	int lo = 0, hi = n - 1, ans = -1;

	while (lo <= hi) {

		int mid = lo + (hi - lo) / 2;

		if (vec[mid] == target) {

			ans = mid;
			return ans;
		}
		else if (vec[mid] < target) {
			lo = mid + 1;
		}
		else {
			hi = mid - 1;
		}
	}

	return ans;

}

int binary_search_recur(vector<int>& vec, int n, int lo, int hi, int target) {

	// base case for element not found
	if (lo > hi) return -1;

	int mid = lo + (hi - lo) / 2;


	if (vec[mid] == target) return mid;

	else if ( vec[mid] < target) {
		return binary_search_recur(vec, n, mid + 1, hi, target);
	}

	else return binary_search_recur(vec, n, lo, mid - 1, target);

}
int main() {

	int n, target;
	cin >> n >> target;

	vector<int> vec(n);


	for (int i = 0; i < n; ++i)
	{
		cin >> vec[i];
	}

	cout << "index of target is " << binary_search_iter(vec, n, target) << nline;
	cout << "index of target is " << binary_search_recur(vec, n, 0, n - 1, target) << nline;

	return 0;
}