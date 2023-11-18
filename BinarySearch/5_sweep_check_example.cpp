#include <bits/stdc++.h>
using namespace std;
#define nline "\n";


/*

You are given an array containing n positive integers.
Your task is to divide the array into k subarrays so that the maximum sum in a subarray is as small as possible.
Input
The first input line contains two integers n and k: the size of the array and the number of subarrays in the division.
The next line contains n integers x_1,x_2,\ldots,x_n: the contents of the array.
Output
Print one integer: the maximum sum in a subarray in the optimal division.
Constraints

1 <= n <= 2 * 10^5
1 <= k <= n
1 <= x_i <= 10^9

Example


Input:
5 3
2 4 7 3 5

Output:
8

Explanation: An optimal division is [2,4],[7],[3,5] where the sums of the subarrays are 6,7,8. The largest sum is the last sum 8.


*/

bool check(long long x, long long k, vector<long long> &vec) {

	long long subarrays = 1;
	long long currSum = 0LL;

	for (int i = 0; i < vec.size(); ++i)
	{
		if (currSum + vec[i] <= x) {
			currSum += vec[i];
		}
		else if (vec[i] <= x) {
			subarrays++;
			currSum = vec[i];
		}
		else return 0;
	}

	return subarrays <= k;

}


int main() {


	long long n, k;
	cin >> n >> k;

	vector<long long> vec(n);
	long long sum = 0LL;

	for (int i = 0; i < n; ++i)
	{
		cin >> vec[i];
		sum += vec[i];
	}

	long long lo = 0, hi = sum, ans = -1;

	while (lo <= hi) {

		long long mid = lo + (hi - lo) / 2;

		// expected max of k subarray sum

		if (check(mid, k, vec)) {

			ans = mid;
			hi = mid - 1;

		}

		else lo = mid + 1;
	}

	cout << ans << nline;


	return 0;
}