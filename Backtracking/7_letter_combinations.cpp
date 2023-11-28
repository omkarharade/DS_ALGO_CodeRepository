#include <bits/stdc++.h>
using namespace std;
#define nline "\n";


void possibleLetters(vector<string>& pad, string& digits, vector<string>& ans, int currDigiIndx, string osf) {

	if (digits.length() == currDigiIndx) {

		ans.push_back(osf);
		return;
	}

	for (int i = 0; i < 3; ++i)
	{
		possibleLetters(pad, digits, ans, currDigiIndx + 1, osf + pad[(digits[currDigiIndx] - '1') + 1][i]);
	}
}


vector<string> letterCombinations(string digits) {

	vector<string> pad(10);
	char currChar = 'a';
	for (int i = 2; i <= 6; i++) {
		string currString;

		for (int j = 0; j < 3; j++) {
			currString.push_back(char(currChar));
			currChar++;
		}
		pad[i] = currString;
	}

	pad[7] = "pqrs";
	pad[8] = "tuv";
	pad[9] = "wxyz";

	vector<string> ans;
	possibleLetters(pad, digits, ans, 0, "");
	return ans;

}

int main() {

	string s;
	cin >> s;

	vector<string> ans = letterCombinations(s);

	for (int i = 0; i < ans.size(); ++i)
	{
		cout << ans[i] << nline;
	}
	return 0;
}