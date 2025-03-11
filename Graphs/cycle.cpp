#include <bits/stdc++.h>
using namespace std;
#define nline "\n"

const int N = 1e5 + 10;
vector<int> g[N];
bool vis[N];

bool dfs(int vertex, int par) {

	/*
	take action on vertex after
	entering the vertex
	*/

	vis[vertex] = 1;

	bool doesLoopExist  = false;

	for (auto child : g[vertex]) {

		if (vis[child] and child == par) continue;
		if (vis[child]) return true;

		/*
		take action on child before
		entering the child node
		*/

		doesLoopExist |= dfs(child, vertex);

		/*
		take action on child after
		exiting the child node
		*/
	}

	/*
	take action on vertex before
	exiting the vertex
	*/

	return doesLoopExist;

}



int main() {
#ifndef ONLINE_JUDGE
	freopen("error.txt", "w", stderr);
#endif

	// code here

	int n, e;
	cin >> n >> e;

	for (int i = 0; i < e; ++i)
	{
		int v1, v2;
		cin >> v1 >> v2;

		g[v1].push_back(v2);
		g[v2].push_back(v1);

	}

	bool loopExists = false;

	for (int i = 1; i <= n; ++i)
	{
		if (vis[i]) continue;

		if (dfs(i, 0)) {
			loopExists = true;
			break;
		}
	}

	cout << loopExists << nline;

	return 0;
}