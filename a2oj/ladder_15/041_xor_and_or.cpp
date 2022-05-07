#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s, t;
    cin >> s >> t;
    int n = s.length(), m = t.length();
    if (m != n) {
        cout << "NO\n";
        return 0;
    }
    bool oks = false, okt = false;
    for (char c : s) if (c == '1') oks = true;
    for (char c : t) if (c == '1') okt = true;
    if (oks == okt) cout << "YES\n";
    else cout << "NO\n";
    return 0;
}
