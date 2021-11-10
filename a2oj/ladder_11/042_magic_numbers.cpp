// https://codeforces.com/problemset/problem/320/A

#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cin >> s;
    for (int i = 0; i < s.size(); i++) {
        if (!(s[i] == '1' || s[i] == '4')) {
            cout << "NO";
            return 0;
        }
    }
    if (s[0] == '4') {
        cout << "NO";
        return 0;
    }
    if (s.find("444") != s.npos) {
        cout << "NO";
        return 0;
    }
    cout << "YES";
    return 0;
}
