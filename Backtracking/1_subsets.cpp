#include <bits/stdc++.h>
using namespace std;
#define nline "\n";


void subsetWays(vector<vector<int>>& ans, vector<int>& nums, vector<int>&currSubset, int i) {

	if ( i == nums.size()) {
		ans.push_back(currSubset);
		return;
	}

	subsetWays(ans, nums, currSubset, i + 1);

	currSubset.push_back(nums[i]);
	subsetWays(ans, nums, currSubset, i + 1);
	currSubset.pop_back();

}

vector<vector<int>> subsets(vector<int>& nums) {

	vector<vector<int>> ans;
	vector<int> currSubset;
	subsetWays(ans, nums, currSubset, 0);

	return ans;
}

int main() {

	int n;
	cin >> n;


	vector<int> nums(n);

	for (int i = 0; i < n; ++i)
	{
		cin >> nums[i];
	}

	vector<vector<int>> ans = subsets(nums);

	for (int i = 0; i < ans.size(); ++i)
	{
		cout << "[ ";
		for (int j = 0; j < ans[i].size(); ++j)
		{
			cout << ans[i][j] << " ";
		}

		cout << "]" << nline;
	}

	return 0;
}