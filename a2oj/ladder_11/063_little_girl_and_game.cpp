// https://codeforces.com/problemset/problem/276/B

#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cin >> s;
    unordered_map<char, int> cnts;
    for (char c : s) {
        cnts[c]++;
    }
    int odds = 0;
    for (auto p : cnts) {
        if (p.second % 2 == 1) {
            odds++;
        }
    }
    if (odds < 2) cout << "First";
    else {
        if (odds % 2 == 0) {
            cout << "Second";
        } else {
            cout << "First";
        }
    }
    return 0;
}
