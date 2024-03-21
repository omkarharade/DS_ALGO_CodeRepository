#include <bits/stdc++.h>
using namespace std;
#define nline "\n"


void selectionSort(vector<int>& vec, int n) {

    for (int i = 0; i < n - 1; i++)
    {
        int minIndx = i;

        // calculate the min element from the unsorted region (index j to n)

        for (int j = i; j < n; j++)
        {
            if (vec[minIndx] > vec[j]) {
                minIndx = j;
            }
        }

        swap(vec[i], vec[minIndx]);
    }

}

void printArray(vector<int>& vec, int n) {

    for (int i = 0; i < n; i++)
    {
        cout << vec[i] << " ";
    }

    cout << nline;

}


void solve() {
    // solve here...
    int n;
    cin >> n;

    vector<int> vec(n);

    for (int i = 0; i < n; i++)
    {
        cin >> vec[i];
    }

    selectionSort(vec, n);
    printArray(vec, n);

}

int main()
{
    // Write your code here....

    int t = 1;
    // cin >> t;

    while (t-- > 0)
    {
        solve();
    }
}