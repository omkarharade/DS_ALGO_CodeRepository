#include <bits/stdc++.h>
using namespace std;
#define nline "\n";

/*

there are N problems each with T[i] - time required to solve the problem
							   S[i] - skill associated with the problem

you have X time and K slots for selecting problems such that the total skill
obtained at the end is maximum


*/


int n;
int t[1001];
int s[1001];

int x, k;
int taken[1001];

int dp[101][101][101];


bool check(int level) {

	return true;
}
// returns max skill i can make from [level . . . . . n-1]
int rec(int level, int timetaken, int itemtaken) {

	// 1. pruning



	// 2. base case
	if (level == n) {

		return 0;
	}

	// 3. cache check
	if (dp[level][timetaken][itemtaken] != -1) return dp[level][timetaken][itemtaken];



	// 4. compute / transition  :

	// choice 1: dont take
	int ans = rec(level + 1, timetaken, itemtaken);


	// choice 2: take item
	if (timetaken + t[level] <= x and itemtaken + 1 <= k) {
		ans = max(ans, s[level] + rec(level + 1, timetaken + t[level], itemtaken + 1));
	}



	// 5. save and return
	return dp[level][timetaken][itemtaken] = ans;

}
int main() {

	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> t[i] >> s[i];
	}

	cin >> x >> k;
	memset(dp, -1, sizeof(dp));

	cout << rec(0) << nline;

	return 0;
}