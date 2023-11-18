#include <bits/stdc++.h>
using namespace std;
#define nline "\n";


/*

CSES Problem Set : Factory Machines

A factory has n machines which can be used to make products. Your goal is to make a total of t products.
For each machine, you know the number of seconds it needs to make a single product. The machines can work simultaneously, and you can freely decide their schedule.
What is the shortest time needed to make t products?
Input
The first input line has two integers n and t: the number of machines and products.
The next line has n integers k_1,k_2,\dots,k_n: the time needed to make a product using each machine.
Output
Print one integer: the minimum time needed to make t products.


Constraints

1 <= n <= 2 * 10^5
1 <= t <= 10^9
1 <= ki <= 10^9


Example


Input:
3 7
3 2 5

Output:
8

Explanation: Machine 1 makes two products, machine 2 makes four products and machine 3 makes one product.



*/


bool check(vector<int> &vec, long long time, int reqProducts) {

	long long totalProducts = 0LL;

	for (int i = 0; i < vec.size(); ++i)
	{

		// individual contribution in given time ( atomic contribution )

		totalProducts += (1LL * time / vec[i]);
	}
	return totalProducts >= reqProducts;
}


int main() {

	int n, t;
	cin >> n >> t;

	vector<int> vec(n);
	long long lo = 1, hi = *min_element(vec.begin(), vec.end()) * 1LL * t  , ans = 0LL; // int overflow possible

	for (int i = 0; i < n; ++i)
	{
		cin >> vec[i];
	}


	while (lo <= hi) {

		long long mid = lo + (hi - lo) / 2;

		if (check(vec, mid, t)) {

			ans = mid;
			hi = mid - 1;
		}
		else lo = mid + 1;

	}

	cout << ans << nline;

	return 0;
}
/*

 (non sublinear) Binary search on answer first form -- atomic item contribution
 Time Complexity 	= O( log(hi - lo + 1) * O(check)) = O(n * log (time taken by the slowest contributor to do one job * no. of jobs ))
 					= O(n * log (hi))
*/