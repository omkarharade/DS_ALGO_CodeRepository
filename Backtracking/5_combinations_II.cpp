#include <bits/stdc++.h>
using namespace std;
#define nline "\n";


void combinations(vector<vector<int>>& ans, vector<int>& candidates, int target, int currTarget, vector<int>& currCandidates, int currIndx) {

	if (currTarget == target) {
		ans.push_back(currCandidates);
		return;
	}

	if (currIndx == candidates.size()) return;
	if (currTarget > target) return;

	// pick

	currCandidates.push_back(candidates[currIndx]);
	combinations(ans, candidates, target, currTarget + candidates[currIndx], currCandidates, currIndx + 1);
	currCandidates.pop_back();

	// not pick
	int skipCount = 0;
	while (currIndx + 1 < candidates.size() and candidates[currIndx] == candidates[currIndx + 1]) { currIndx++; skipCount++;}
	combinations(ans, candidates, target, currTarget, currCandidates, currIndx + 1);

}


vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
	vector<vector<int>> ans;
	vector<int> currCandidates;

	sort(candidates.begin(), candidates.end());
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

	vector<vector<int>> ans = combinationSum2(vec, 5);

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


	return 0;
}