#include <bits/stdc++.h>
using namespace std;
#define nline "\n";


void printSubset(string& s, int currIndx, string output) {

	if (currIndx == s.length()) {
		cout << output << nline;
		return;
	}

	printSubset(s, currIndx + 1, output + s[currIndx]);
	printSubset(s, currIndx + 1, output);

}

int main() {

	string s = "abc";

	printSubset(s, 0, "");

	return 0;
}