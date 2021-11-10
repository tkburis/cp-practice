// https://codeforces.com/problemset/problem/96/A

#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cin >> s;
    int cnt = 0;
    bool yes = false;
    for (int i = 1; i < s.size(); i++) {
        if (s[i-1] == s[i]) {
            cnt++;
        } else {
            cnt = 0;
        }

        if (cnt >= 6) {
            yes = true;
            break;
        }
    }
    if (yes) {
        cout << "YES";
    } else {
        cout << "NO";
    }
    return 0;
}
