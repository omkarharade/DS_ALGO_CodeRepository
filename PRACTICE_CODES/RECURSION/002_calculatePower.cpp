#include <bits/stdc++.h>
using namespace std;
#define nline "\n";

/*

calculate a to the power b

*/

int power(int a, int b) {

	if (b == 0) return 1;
	int partialAns = power(a, b / 2);

	if (b % 2 == 0) return partialAns * partialAns;

	else return a * partialAns * partialAns;

}

int main() {


	int a, b;
	cin >> a >> b;

	cout << power(a, b) << nline;

	return 0;
}