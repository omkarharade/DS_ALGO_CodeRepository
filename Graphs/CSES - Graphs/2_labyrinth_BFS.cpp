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
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]" << nline;}
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

bool isSafe(int i, int j, int n, int m) {

	return i >= 0 and j >= 0 and i < n and j < m;
}

void solve() {
	// solve here....

	int n, m;
	cin >> n >> m;

	vector<vector<char>> grid(n, vector<char>(m));
	queue<pair<int, int>> que;


	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			cin >> grid[i][j];
		}
	}

	pair<int, int> start, end;
	vector<pair<int, int>> direction = {

		{ -1, 0}, {1, 0}, {0, -1}, {0, 1} // {U, D, L, R}
	};

	vector<vector<char>> path(n, vector<char>(m, '?'));


	for (int i = 0; i < n; i++) {

		for (int j = 0; j < m; j++) {

			if (grid[i][j] == 'A') {
				start = make_pair(i, j);
			}

			if (grid[i][j] == 'B') {
				end = make_pair(i, j);
			}
		}
	}

	debug(start)
	debug(end)

	bool ok = 0;
	que.push(start);
	path[start.first][start.second] = 'S';


	while (!que.empty()) {

		int x0 = que.front().first;
		int y0 = que.front().second;
		que.pop();

		if (x0 == end.first and y0 == end.second) {

			ok = 1;
			break;
		}


		for (int i = 0; i < 4; ++i)
		{
			int x1 = x0 + direction[i].first;
			int y1 = y0 + direction[i].second;

			if (!isSafe(x1, y1, n, m)) continue;
			if (grid[x1][y1] == '#') continue;

			if (path[x1][y1] == '?') {

				que.push(make_pair(x1, y1));

				// store the direction used by [x0, y0] to reach [x1, y1]

				if (i == 0) path[x1][y1] = 'U';
				else if (i == 1) path[x1][y1] = 'D';
				else if (i == 2) path[x1][y1] = 'L';
				else if (i == 3) path[x1][y1] = 'R';

			}
		}
	}

	debug(ok)

	if (ok) {

		cout << "YES" << nline;
		string ans;

		int currX = end.first, currY = end.second;

		while (path[currX][currY] != 'S') {

			ans.push_back(path[currX][currY]);

			if (path[currX][currY] == 'U') currX++;
			else if (path[currX][currY] == 'D') currX--;
			else if (path[currX][currY] == 'L') currY++;
			else if (path[currX][currY] == 'R') currY--;
		}

		reverse(ans.begin(), ans.end());
		cout << ans.length() << nline;
		cout << ans << nline;
	}
	else cout << "NO" << nline;




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