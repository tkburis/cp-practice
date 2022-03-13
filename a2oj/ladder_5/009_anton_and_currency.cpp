// https://codeforces.com/problemset/problem/508/B

#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cin >> s;
    bool found = false;
    for (int i = 0; i < s.length(); i++) {
        if ((s[i] - '0') % 2 == 0 && (s[i] - '0') < (s[s.length()-1] - '0')) {
            found = true;
            swap(s[i], s[s.length()-1]);
            break;
        }
    }
    if (!found) {
        for (int i = s.length()-1; i >= 0; i--) {
            if ((s[i] - '0') % 2 == 0) {
                found = true;
                swap(s[i], s[s.length()-1]);
                break;
            }
        }
    }
    if (found) cout << s << '\n';
    else cout << -1 << '\n';
    return 0;
}
