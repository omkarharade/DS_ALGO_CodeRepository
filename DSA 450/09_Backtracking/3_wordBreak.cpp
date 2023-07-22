#include <bits/stdc++.h>
using namespace std;
#define nline "\n";

void f(vector<string>& dict, string& s, int n, int strLen, int strIndx, string osf, vector<string>& ansVec) {

	if (strIndx == strLen) {
		ansVec.push_back(osf);
		return;
	}
	string ans;

	for (int i = strIndx; i < strLen; i++) {

		ans.push_back(s[i]);

		for (int j = 0; j < n; j++) {

			if (ans == dict[j]) {

				f(dict, s, n, strLen, i + 1, osf + dict[j] + (i + 1 == strLen ? "" : " "), ansVec);
			}
		}
	}
}

vector<string> wordBreak(int n, vector<string>& dict, string s)
{
	// code here

	int strLen = s.length();
	vector<string> ansVec;

	f(dict, s, n, strLen, 0, "", ansVec);

	return ansVec;
}


int main() {

	int n;
	cin >> n;

	string s;
	cin >> s;

	vector<string> dict(n);

	for (int i = 0; i < n; ++i)
	{
		cin >> dict[i];
	}

	vector<string> ansVec = wordBreak(n, dict, s);

	for (int i = 0; i < ansVec.size(); ++i)
	{
		cout << ansVec[i] << nline;
	}

	return 0;
}