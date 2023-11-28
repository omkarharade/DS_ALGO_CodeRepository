#include <bits/stdc++.h>
using namespace std;
#define nline "\n";


void permutations(vector<vector<int>>& ans, vector<int>& nums, int currIndx) {

	if (currIndx == nums.size()) {
		ans.push_back(nums);
		return;
	}

	for (int i = currIndx; i < nums.size(); ++i)
	{
		swap(nums[currIndx], nums[i]); // each character gets chance to be at currIndx atleast once

		permutations(ans, nums, currIndx + 1);

		swap(nums[currIndx], nums[i]);
	}
}

vector<vector<int>> permute(vector<int>& nums) {

	vector<vector<int>> ans;
	permutations(ans, nums, 0);

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

	vector<vector<int>> ans = permute(vec);

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