#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007
#define MOD1 998244353
#define INF 1e18
#define nline "\n"
#define pb push_back
#define ppb pop_back
#define mp make_pair
#define ff first
#define ss second
#define PI 3.141592653589793238462
#define set_bits __builtin_popcountll
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;
typedef vector<long long> vll;
typedef vector<int> vi;
typedef pair<int, int> pii;
// typedef tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update > pbds; // find_by_order, order_of_key

#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x <<" "; _print(x); cerr << endl;
#else
#define debug(x)
#endif

void _print(ll t) {cerr << t;}
void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(lld t) {cerr << t;}
void _print(double t) {cerr << t;}
void _print(ull t) {cerr << t;}

template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T> void _print(unordered_set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T, class V> void _print(unordered_map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.ff); cerr << ","; _print(p.ss); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(unordered_set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(unordered_map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}



template<typename T1, typename T2> // cin >> pair<T1, T2>
istream& operator>>(istream &in, pair<T1, T2> &p) { return (in >> p.first >> p.second);}
template<typename T> // cin >> vector<T>
istream& operator>>(istream &in, vector<T> &v) {for (auto &it : v) cin >> it; return in;}
template<typename T1, typename T2> // cout << pair<T1, T2>
ostream& operator<<(ostream &out, const pair<T1, T2> &p) {return (out << p.first << " " << p.second); }
template<typename T> //cout << vector<T>
ostream& operator<<(ostream &out, const vector<T> &c) {for (auto &it : c) cout << it << " "; return out;}


void file_i_o()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("error.txt", "w", stderr);
#endif
}


/*

Your task is to count the number of ways to construct sum n by throwing a dice one or more times. Each throw produces an outcome between 1 and  6.
For example, if n=3, there are 4 ways:

1+1+1
1+2
2+1
3


Input :
The only input line has an integer n.


Output :
Print the number of ways modulo 10^9+7.


Constraints:

1 <= n <= 10^6

Example:

Input:
3

Output:
4

*/

int combinations(int current, int target) {

	// pruning
	if (current > target) return 0;

	// base case
	if (current == target) return 1;

	// compute
	int ways = 0;

	for (int i = 1; i <= 6 ; ++i)
	{
		ways += ((combinations(current + i, target) * 1LL) % MOD);
		ways %= MOD;
	}

	// return
	return ways;
}

int dp[1000010]; // value from the upper limit of value n

int combinationsTD(int current, int target) {

	// pruning
	if (current > target) return 0;

	// base case
	if (current  == target) return 1;

	// cache check
	if (dp[current] != -1) return dp[current];


	// compute
	int ways = 0;

	for (int i = 1; i <= 6 ; ++i)
	{
		ways += ((combinations(current + i, target) * 1LL) % MOD);
		ways %= MOD;
	}

	// save and return
	return dp[current] = ways;

}

int combinationsBU(int n) {

	vector<int> DP(n + 1, 0);
	DP[n] = 1;

	// states

	for (int i = n - 1; i >= 0; i--)
	{
		int ways = 0;

		// transitions

		for (int j = 1; j <= 6; ++j)
		{
			if (i + j <= n) {

				ways += ((DP[i + j] * 1LL) % MOD);
				ways %= MOD;
			}
		}

		DP[i] = ways;
	}

	return DP[0];
}

void solve() {
	// solve here....

	int n;
	cin >> n;

	// cout << combinations(0, n) << nline;

	// for (int i = 0; i < 1000010; ++i)
	// {
	// 	dp[i] = -1;
	// }

	// cout << combinationsTD(0, n) << nline;
	cout << combinationsBU(n) << nline;

}

int main()
{
	clock_t begin = clock();
	file_i_o();
	// Write your code here....

	int t = 1;
	// cin >> t;

	while (t-- > 0)
	{
		solve();
	}

#ifndef ONLINE_JUDGE
	clock_t end = clock();
	cout << "\n\nExecuted In: " << double(end - begin) / CLOCKS_PER_SEC * 1000 << " ms";
#endif
	return 0;
}