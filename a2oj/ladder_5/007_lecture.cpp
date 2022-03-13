// https://codeforces.com/problemset/problem/499/B

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    map<string, string> best;
    for (int i = 0; i < m; i++) {
        string s, t;
        cin >> s >> t;
        if (t.length() < s.length()) {
            best[t] = t;
            best[s] = t;
        } else {
            best[s] = s;
            best[t] = s;
        }
    }
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        cout << best[s] << ' ';
    }
    return 0;
}
