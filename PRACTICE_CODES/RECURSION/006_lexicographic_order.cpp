#include <bits/stdc++.h>
using namespace std;
#define nline "\n";

void lexico(int i, int n) {

	if ( i > n) return;

	for (int j = (i == 0 ? 1 : 0) ; j <= 9; j++) {
		cout << i << nline;
		lexico(10 * i + j, n);
	}
}

int main() {

	int n;
	cin >> n;

	lexico(0, n);

	return 0;
}