// https://codeforces.com/problemset/problem/186/A

#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s, t;
    cin >> s >> t;
    if (s.length() != t.length()) {
        cout << "NO";
        return 0;
    }
    int len = s.length(), matches[len];
    for (int i = 0; i < len; i++) {
        matches[i] = s[i] == t[i];
    }
    int nonmatches = 0;
    for (int i = 0; i < len; i++) {
        if (!matches[i]) nonmatches++;
    }
    if (nonmatches != 2) {
        cout << "NO";
        return 0;
    }
    sort(s.begin(), s.end());
    sort(t.begin(), t.end());
    if (s==t) {
        cout << "YES";
    } else {
        cout << "NO";
    }
    return 0;
}
