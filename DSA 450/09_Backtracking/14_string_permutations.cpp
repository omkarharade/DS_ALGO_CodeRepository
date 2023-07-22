#include <bits/stdc++.h>
using namespace std;
#define nline "\n";


void printPermutations(string &s, int currIndx, int n) {

	if (currIndx == n) {
		cout << s << nline;
		return;
	}

	bool chPresent[26] = {0};

	for (int i = currIndx; i < n; i++) {

		int toBeSwapped = s[i] - 'a';
		if (chPresent[toBeSwapped]) continue;
		else {

			chPresent[toBeSwapped] = 1;
			swap(s[currIndx], s[i]);
			printPermutations(s, currIndx + 1, n);
			swap(s[currIndx], s[i]);
		}

	}
}

int main() {

	string s;
	cin >> s;
	printPermutations(s, 0, s.length());
	return 0;
}