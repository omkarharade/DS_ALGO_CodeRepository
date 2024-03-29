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

Consider a money system consisting of n coins. Each coin has a positive integer value. Your task is to produce a sum of money x using the available coins in such a way that the number of coins is minimal.
For example, if the coins are \{1,5,7\} and the desired sum is 11, an optimal solution is 5+5+1 which requires 3 coins.
Input
The first input line has two integers n and x: the number of coins and the desired sum of money.
The second line has n distinct integers c_1,c_2,\dots,c_n: the value of each coin.
Output
Print one integer: the minimum number of coins. If it is not possible to produce the desired sum, print -1.
Constraints

1 <= n <= 100
1 <= x <= 10^6
1 <= c_i <= 10^6

Example
Input:
3 11
1 5 7

Output:
3

*/

int minCoins(vector<int>& C, int currSum, int n, int x) {

	// pruning
	if (currSum > x) return 1e9;


	// base case
	if (currSum == x) return 0;


	// compute
	int minOfCoins = 1e9;

	for (int i = 0; i < n; ++i)
	{
		minOfCoins = min(minOfCoins, 1 + minCoins(C, currSum + C[i], n, x));
	}

	// return
	return (minOfCoins == 1e9 ? 1e9 : minOfCoins);
}



vector<int> dp;

int minCoinsDP(vector<int>& C, int currSum, int n, int x) {

	// pruning
	if (currSum > x) return 1e9;

	// base case
	if (currSum == x) return 0;

	// cache check
	if (dp[currSum] != -1) return dp[currSum];


	// compute
	int minOfCoins = 1e9;

	for (int i = 0; i < n; ++i)
	{
		minOfCoins = min(minOfCoins, 1 + (minCoinsDP(C, currSum + C[i], n, x)));
	}

	// save and return
	return dp[currSum] = ((minOfCoins == int(1e9)) ? int(1e9) : minOfCoins);
}

int minCoinsBU(vector<int>& C, int n, int x) {

	vector<int> DP(x + 1, -1);
	DP[x] = 0;

	for (int i = x - 1; i >= 0; i--)
	{
		int minOfCoins = 1e9;

		for (int j = 0; j < n; ++j)
		{

			if (i + C[j] <= x) {
				minOfCoins = min(minOfCoins, 1 + DP[i + C[j]]);
			}
		}

		DP[i] = (minOfCoins == int(1e9) ? 1e9 : minOfCoins);
	}

	return ((DP[0] == 1e9 ) ? -1 : DP[0]);
}



void solve() {
	// solve here....

	int n, x;
	cin >> n >> x;

	vector<int> C(n);
	dp.resize(x + 1, -1);

	for (int i = 0; i < n; ++i)
	{
		cin >> C[i];
	}

	// cout << minCoins(C, 0, n, x) << nline;

	// for (int i = 0; i <= x; ++i)
	// {
	// 	dp[i] = -1;
	// }

	// cout << (minCoinsDP(C, 0, n, x) >= int(1e9) ? -1 : dp[0]) << nline;


	cout << minCoinsBU(C, n, x) << nline;
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