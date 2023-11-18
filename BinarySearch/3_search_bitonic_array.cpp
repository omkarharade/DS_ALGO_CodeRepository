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
--------------------------------------------------------------------------------------------------------------------------------------------------------------------------

Description :


Given a bitonic array A consisting of N integers and an integer Q. In each query, you will be given an integer K, find the positions of K in A. Integer K exists in A.

Bitonic array - A bitonic sequence is a sequence with A[1]<A[2]<A[3]....A[k]>A[k+1]>A[k+2]....>A[N] for some 1<=K≤N.


Input Format:


The first line contains T, the number of test cases (1<=T<=10000).

The first line contains two space separated-integer N, Q where 1<=N<=10^5, 1<=Q<=10^6.

The second line contains N space-separated integers A1,A2....AN where -1e9<=Ai<=1e9.

Next Q lines contains an integer K, -1e9<=K<=1e9.

Sum of N, Q across all test case ≤10^6


Output Format:

For each test case print the positions of K in A in sorted order in a new line.

Positions are 1-indexed.




Sample Input 1

1
6 4
1 2 5 3 2 1
1
2
5
3

Sample Output 1

1 6
2 5
3
4

------------------------------------------------------------------------------------------------
*/

// my approach using STL
// bool peakCheck(vector<int> &vec, int mid) {

// 	if (mid == vec.size() - 1) return 1;

// 	return vec[mid] > vec[mid + 1];
// }



// void solve() {
// 	// solve here....

// 	int n, q;
// 	cin >> n >> q;

// 	vector<int> vec(n);

// 	for (int i = 0; i < n; ++i)
// 	{
// 		cin >> vec[i];
// 	}

// 	int lo = 0, hi = n - 1;
// 	int peakIndx = n - 1;


// 	// finding peak element in bitonic array

// 	while (lo <= hi) {

// 		int mid = lo + (hi - lo) / 2;

// 		if (peakCheck(vec, mid)) {
// 			peakIndx = mid;
// 			hi = mid - 1;
// 		}
// 		else lo = mid + 1;
// 	}


// 	while (q--) {

// 		int num;
// 		cin >> num;

// 		// check left of peak and peak element

// 		int leftLowIndx = lower_bound(vec.begin(), vec.begin() + (peakIndx + 1), num) - vec.begin();
// 		int leftHighIndx = upper_bound(vec.begin(), vec.begin() + (peakIndx + 1), num) - vec.begin();

// 		// check right of peak element

// 		int rightLowIndx = lower_bound(vec.rbegin(), vec.rend() - (peakIndx + 1) , num) - vec.rbegin();
// 		int rightHighIndx = upper_bound(vec.rbegin(), vec.rend() - (peakIndx + 1), num) - vec.rbegin();

// 		rightHighIndx =  n - 1 - rightHighIndx;
// 		rightLowIndx =  n - 1 - rightLowIndx;

// 		for (int i = leftLowIndx + 1; i <= leftHighIndx; i++) cout << i << " ";
// 		for (int i = rightHighIndx + 1 ; i <= rightLowIndx; i++) cout << i + 1 << " ";
// 		cout << nline;

// 	}


// }


int n, q;
vector<int> arr;

bool check(int i) {
	if (arr[i] > arr[i - 1])return 1;
	else return 0;
}

void solve() {
	cin >> n >> q;
	arr.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	// Get Peak Element

	int lo = 1;
	int hi = n - 1;
	int peak = 0;
	while (lo <= hi) {
		int mid = (lo + hi) / 2;
		if (check(mid)) {
			peak = mid;
			lo = mid + 1;
		} else {
			hi = mid - 1;
		}
	}

	while (q--) {
		int k;
		cin >> k;

		vector<int> final;

		// check left array from peak

		lo = 0;
		hi = peak - 1;
		while (lo <= hi) {
			int mid = (lo + hi) / 2;
			if (arr[mid] == k) {
				final.push_back(mid + 1);
				break;
			} else if (arr[mid] > k) {
				hi = mid - 1;
			} else {
				lo = mid + 1;
			}
		}


		// check right array from peak


		lo = peak;
		hi = n - 1;
		while (lo <= hi) {
			int mid = (lo + hi) / 2;
			if (arr[mid] == k) {
				final.push_back(mid + 1);
				break;
			} else if (arr[mid] > k) {
				lo = mid + 1;
			} else {
				hi = mid - 1;
			}
		}

		for (auto v : final) {
			cout << v << " ";
		}
		cout << endl;
	}
}

int main()
{
	clock_t begin = clock();
	file_i_o();
	// Write your code here....

	int t = 1;
	cin >> t;

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

/*

Binary Search Form 1 - sublinear - ( log(n)  - { :. work / time complexity})

*/