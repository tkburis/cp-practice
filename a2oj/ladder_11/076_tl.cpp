// https://codeforces.com/problemset/problem/350/A

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    int min_a = INT_MAX, max_a = 0, min_b = INT_MAX;
    for (int i = 0; i < n; i++) {
        int t;
        cin >> t;
        min_a = min(min_a, t);
        max_a = max(max_a, t);
    }
    for (int i = 0; i < m; i++) {
        int t;
        cin >> t;
        min_b = min(min_b, t);
    }
    for (int i = 2*min_a; i < min_b; i++) {
        if (i >= max_a) {
            cout << i;
            return 0;
        }
    }
    cout << -1;
    return 0;
}
