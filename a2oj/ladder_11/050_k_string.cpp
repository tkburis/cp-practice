// https://codeforces.com/problemset/problem/219/A

#include <bits/stdc++.h>
using namespace std;

struct DefaultZero {
    int value = 0;
};

int main()
{
    int k;
    string s;
    map<char, int> counts;
    cin >> k >> s;
    for (char c : s) {
        counts[c]++;
    }
    for (auto t : counts) {
        if (t.second % k != 0) {
            cout << -1;
            return 0;
        }
    }
    for (int i = 0; i < k; i++) {
        for (auto t : counts) {
            for (int j = 0; j < t.second/k; j++) {
                cout << t.first;
            }
        }
    }
    return 0;
}
