#include <bits/stdc++.h>
using namespace std;
#define nline "\n";


// this solution requires sorting


void subsetWays(vector<vector<int>>& ans, vector<int>& nums, vector<int>&currSubset, int i, bool prev) {

	if ( i == nums.size()) {
		ans.push_back(currSubset);
		return;
	}

	subsetWays(ans, nums, currSubset, i + 1, false);
	if ((i > 0) and (nums[i] == nums[i - 1]) and (!prev)) return;



	currSubset.push_back(nums[i]);
	subsetWays(ans, nums, currSubset, i + 1, true);
	currSubset.pop_back();

}


vector<vector<int>> subsetsWithDup(vector<int>& nums) {
	vector<vector<int>> ans;
	vector<int> currSubset;

	sort(nums.begin(), nums.end());
	subsetWays(ans, nums, currSubset, 0, false);

	return ans;
}



int main() {


	return 0;
}