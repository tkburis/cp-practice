// https://codeforces.com/problemset/problem/296/A

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> cnts(1001, 0);
    for (int i = 0; i < n; i++) {
        int t;
        cin >> t;
        cnts[t]++;
    }
    bool can = true;
    for (auto c : cnts) {
        if (c != 0 && c > (n+1)/2) {
            can = false;
        }
    }
    if (can) {
        cout << "YES";
    } else {
        cout << "NO";
    }
}
