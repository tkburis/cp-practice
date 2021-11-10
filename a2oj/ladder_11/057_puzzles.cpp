// https://codeforces.com/problemset/problem/337/A

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> f(m);
    for (int i = 0; i < m; i++) {
        cin >> f[i];
    }
    sort(f.begin(), f.end());
    int mini = INT_MAX;
    for (int i = 0; i < m-n+1; i++) {
        mini = min(f[i+n-1] - f[i], mini);
    }
    cout << mini;
    return 0;
}
