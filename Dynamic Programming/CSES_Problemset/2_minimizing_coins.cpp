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


int minCoins(vector<int>& C, int currSum, int n, int x) {

	// pruning
	if (currSum > x) return 1e8;


	// base case
	if (currSum == x) return 0;


	// compute
	int minOfCoins = INT_MAX;

	for (int i = 0; i < n; ++i)
	{
		minOfCoins = min(minOfCoins, 1 + minCoins(C, currSum + C[i], n, x));
	}

	// return
	return minOfCoins;
}




const int N = 1000010;
vector<int> dp(N);

int minCoinsDP(vector<int>& C, int currSum, int n, int x) {

	// pruning
	if (currSum > x) return 1e8;

	// base case
	if (currSum == x) return 0;

	// cache check
	if (dp[currSum] != -1) return dp[currSum];


	// compute
	int minOfCoins = 1e8;

	for (int i = 0; i < n; ++i)
	{
		minOfCoins = min(minOfCoins, 1 + (minCoinsDP(C, currSum + C[i], n, x)));
	}

	// save and return
	return dp[currSum] = ((minOfCoins >= int(1e8)) ? int(1e8) : minOfCoins);
}

int minCoinsBU(vector<int>& C, int n, int x) {

	vector<int> DP(x + 1, -1);
	DP[x] = 0;

	for (int i = x - 1; i >= 0; i--)
	{
		int minOfCoins = 1e8;

		for (int j = 0; j < n; ++j)
		{

			if (i + C[j] <= x) {
				minOfCoins = min(minOfCoins, 1 + DP[i + C[j]]);
			}
		}

		DP[i] = (minOfCoins >= int(1e8) ? 1e8 : minOfCoins);
	}

	return ((DP[0] >= 1e8 ) ? -1 : DP[0]);
}



void solve() {
	// solve here....

	int n, x;
	cin >> n >> x;

	vector<int> C(n);

	for (int i = 0; i < n; ++i)
	{
		cin >> C[i];
	}

	// cout << minCoins(C, 0, n, x) << nline;

	// for (int i = 0; i <= x; ++i)
	// {
	// 	dp[i] = -1;
	// }

	// cout << (minCoinsDP(C, 0, n, x) >= int(1e8) ? -1 : dp[0]) << nline;


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