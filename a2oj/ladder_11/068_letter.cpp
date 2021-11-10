// https://codeforces.com/problemset/problem/43/B

#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s1, s2;
    getline(cin, s1);
    getline(cin, s2);
    map<char, int> s1_counts, s2_counts;
    for (char c : s1) {
        s1_counts[c]++;
    }
    for (char c : s2) {
        if (c != ' ') s2_counts[c]++;
    }
    for (auto p : s2_counts) {
        if (s1_counts[p.first] < p.second) {
            cout << "NO";
            return 0;
        }
    }
    cout << "YES";
    return 0;
}
