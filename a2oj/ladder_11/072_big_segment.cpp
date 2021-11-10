// https://codeforces.com/problemset/problem/242/B

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int best_i = 1;
    bool still_good = true;
    int l, r;
    cin >> l >> r;
    int left_most = l, right_most = r;
    for (int i = 1; i < n; i++) {
        cin >> l >> r;
        if (l < left_most != r > right_most) {
            still_good = false;
        }
        if (l <= left_most && r >= right_most) {
            best_i = i+1;
            still_good = true;
        }
        left_most = min(l, left_most), right_most = max(r, right_most);
        // cout << left_most << "..." << right_most << endl;
    }
    if (still_good) {
        cout << best_i;
    } else {
        cout << -1;
    }
    return 0;
}
