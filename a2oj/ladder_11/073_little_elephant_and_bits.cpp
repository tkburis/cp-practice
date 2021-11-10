// https://codeforces.com/problemset/problem/258/A

#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cin >> s;
    bool rem_zero = false;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '0' && !rem_zero) {
            rem_zero = true;
        } else if (i == s.length()-1 && !rem_zero) {
            ;
        } else {
            cout << s[i];
        }
    }
    return 0;
}
