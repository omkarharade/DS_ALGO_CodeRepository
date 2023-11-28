#include <bits/stdc++.h>
using namespace std;
#define nline "\n";

void combinations(vector<vector<int>>& ans, vector<int>& candidates, int target, int currTarget, vector<int>& currCandidates, int currIndx) {

	if (currIndx == candidates.size()) return;
	if (currTarget > target) return;

	if (currTarget == target) {
		ans.push_back(currCandidates);
		return;
	}

	for (int i = currIndx; i < candidates.size(); ++i)
	{
		if (currTarget + candidates[i] <= target) {

			currCandidates.push_back(candidates[i]);
			combinations(ans, candidates, target, currTarget + candidates[i], currCandidates, i);
			currCandidates.pop_back();
		}
	}
}

vector<vector<int>> combinationSum(vector<int>& candidates, int target) {

	vector<vector<int>> ans;
	vector<int> currCandidates;

	combinations(ans, candidates, target, 0, currCandidates, 0);
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

	vector<vector<int>> ans = combinationSum(vec, 7);

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