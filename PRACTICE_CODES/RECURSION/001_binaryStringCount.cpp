#include <bits/stdc++.h>
using namespace std;
#define nline "\n";


/*

Q. Given a value n, print count of binary strings with no consecutive 1's

ex. for n = 3
	ans: 5


	note: the series forms a fibonacci series starting with 2, 3
	for n = 1, ans: 2
	for n = 2, ans: 3
	for n = 3, ans: 5
	for n = 4, ans: 8
	for n = 5, ans: 13

*/

int binaryStringCount(int prevChar, int n) {

	if (n == 0) return 1;
	int count = 0;

	if (prevChar == 0 or prevChar == -1) {
		count += (binaryStringCount(0, n - 1) + binaryStringCount(1, n - 1));
	}
	else if (prevChar == 1 or prevChar == -1) {
		count += (binaryStringCount(0, n - 1));
	}

	return count;
}

int stringCountFib(int n) {

	if (n == 1) return 2;
	if (n == 2) return 3;

	return stringCountFib(n - 1) + stringCountFib(n - 2);
}

int main() {

	int n;
	cin >> n;

	cout << binaryStringCount(-1, n) << nline;
	cout << stringCountFib(n) << nline;

	return 0;
}