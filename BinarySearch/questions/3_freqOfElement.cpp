#include <bits/stdc++.h>
using namespace std;
#define nline "\n";

int customLowerBound(vector<int>& vec, int n, int target) {

	int lo = 0, hi = n - 1, ans = -1;

	while ( lo <= hi ) {

		int mid = lo + (hi - lo) / 2;

		if (vec[mid] >= target) {
			ans = mid;
			hi = mid - 1;
		}
		else {

			lo = mid + 1;
		}
	}

	return ans;
}


int customUpperBound(vector<int>& vec, int n, int target) {

	int lo = 0, hi = n - 1, ans = -1;

	while ( lo <= hi ) {

		int mid = lo + (hi - lo) / 2;

		if (vec[mid] <= target) {
			ans = mid;
			lo = mid + 1;
		}
		else {
			hi = mid - 1;
		}
	}

	if (vec[ans] != target) ans++; // index to element greater than target

	return ans;
}


vector<int> searchRange(vector<int>& nums, int target) {

	int firstIndx = -1, upperBIndx = -1, n = nums.size();
	vector<int> ans = { -1, -1};


	firstIndx = customLowerBound(nums, n, target);
	upperBIndx = customUpperBound(nums, n, target);

	if (firstIndx != n and nums[firstIndx] == target) {

		nums[0] = firstIndx;

	}

	if (upperBIndx != n and nums[upperBIndx] == target) {

		nums[1] = upperBIndx;
	}

	return ans;
}

int main() {


	return 0;
}