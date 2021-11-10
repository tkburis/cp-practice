// https://codeforces.com/problemset/problem/215/A

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    cin >> m;
    vector<int> b(m);
    for (int i = 0; i < m; i++) {
        cin >> b[i];
    }
    int maxi = 0, maxi_cnt = 0;
    for (auto i : a) {
        for (auto j : b) {
            if (j % i == 0) {
                // cout << j << ' ' << i << endl;
                if (j / i > maxi) {
                    maxi = j / i;
                    maxi_cnt = 1;
                } else if (j / i == maxi) {
                    maxi_cnt++;
                }
            }
        }
    }
    cout << maxi_cnt;
    return 0;
}
