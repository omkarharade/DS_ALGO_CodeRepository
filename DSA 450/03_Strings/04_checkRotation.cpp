#include <bits/stdc++.h>
using namespace std;
#define nline "\n";

bool isRotation(string&s, string&r, int i, int sLen, int rLen) {

	int rIndx = 0, sIndx = i;

	while (rIndx < rLen) {

		if (s[sIndx % sLen] == r[rIndx]) {
			sIndx++, rIndx++;
		}
		else return false;
	}

	return true;
}


bool checkRotation_brute(string& s, string& r) {


	/*

	traverse every character in the string and check if it is rotation
	Time Complexity : O(n*n)
	Space Complexity : O(1)

	*/

	int sLen = s.length(), rLen = r.length();
	for (int i = 0; i < sLen; i++) {

		if (s[i] == r[0]) {
			if (isRotation(s, r, i, sLen, rLen)) return true;
		}
	}

	return false;
}

int main() {


	string s, r;
	cin >> s >> r;

	cout << (checkRotation_brute(s, r) ? "True" : "False");

	return 0;
}