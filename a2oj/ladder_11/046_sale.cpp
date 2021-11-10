// https://codeforces.com/problemset/problem/34/B

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    int c = 0;
    for (int i = 0; i < m; i++) {
        if (a[i] < 0) {
            c -= a[i];
        }
    }
    cout << c;
    return 0;
}
