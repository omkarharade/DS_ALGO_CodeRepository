#include <bits/stdc++.h>
using namespace std;
#define nline "\n";

int validPartition(int arr[], int indx, int N, int target, vector<vector<int>>&dp) {

	if (indx == N) return false;
	if (target == 0) return true;
	if (target < 0) return false;
	if (dp[indx][target] != -1) return dp[indx][target];

	bool include = validPartition(arr, indx + 1, N, target - arr[indx], dp);
	bool exclude = validPartition(arr, indx + 1, N, target, dp);

	return dp[indx][target] = (include || exclude);

}

int equalPartition(int N, int arr[]) {

	int totalSum = 0;

	for (int i = 0; i < N; ++i)
	{
		totalSum += arr[i];
	}

	if ((totalSum / 2) != (totalSum - (totalSum / 2))) return false;

	vector<vector<int>> dp(N, vector<int>((totalSum / 2) + 2, -1));



	return validPartition(arr, 0, N, totalSum / 2, dp);
}

int main() {

	int N;
	cin >> N;

	int arr[N];

	for (int i = 0; i < N; ++i)
	{
		cin >> arr[i];
	}

	cout << (equalPartition(N, arr) ? "YES" : "NO");
	return 0;
}