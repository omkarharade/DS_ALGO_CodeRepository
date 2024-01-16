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

bool isSafe(int i, int j, int n) {

	return i >= 0 and j >= 0 and i < n and j < n;

}


int paths(vector<vector<char>>& grid, int i, int j, int n) {

	// pruning
	if (!isSafe(i, j, n)) return 0;


	// base case
	if (grid[i][j] == '*') return 0;
	if (grid[i][j] != '*' and i == n - 1 and j == n - 1) return 1;


	// compute and return
	return (paths(grid, i + 1, j, n) % MOD + paths(grid, i, j + 1, n) % MOD) % MOD;
}


vector<vector<int>> dp;

int pathsDP(vector<vector<char>>& grid, int i, int j, int n) {

	// pruning
	if (!isSafe(i, j, n)) return 0;

	// cache check
	if (dp[i][j] != -1 ) return dp[i][j];


	// base case
	if (grid[i][j] == '*') return 0;
	if (grid[i][j] != '*' and i == n - 1 and j == n - 1) return 1;


	// compute and return
	return dp[i][j] =  (pathsDP(grid, i + 1, j, n) % MOD + pathsDP(grid, i, j + 1, n) % MOD) % MOD;
}


int pathsBU(vector<vector<char>>& grid, int n) {

	vector<vector<int>> DP(n + 1, vector<int>(n, 0));
	DP[n - 1][n - 1] = (grid[n - 1][n - 1] == '*' ? 0 : 1);


	for (int i = n - 1; i >= 0; i--) {

		for (int j = n - 1; j >= 0; j--) {

			if (i == n - 1 and j == n - 1) continue;

			if (grid[i][j] == '*') DP[i][j] = 0;
			else DP[i][j] = (((i + 1 < n ? DP[i + 1][j] : 0) % MOD) + ((j + 1 < n ? DP[i][j + 1] : 0) % MOD)) % MOD;
		}
	}


	return DP[0][0];
}


void solve() {
	// solve here....

	int n;
	cin >> n;

	vector<vector<char>> grid(n, vector<char>(n));

	dp.resize(n + 1);

	for (int i = 0; i <= n; ++i)
	{
		dp[i].resize(n + 1, -1);
	}


	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			cin >> grid[i][j];
		}
	}

	// cout << paths(grid, 0, 0, n) << nline;
	// cout << pathsDP(grid, 0, 0, n) << nline;
	cout << pathsBU(grid, n) << nline;


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