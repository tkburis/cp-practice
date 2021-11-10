// https://codeforces.com/problemset/problem/298/B

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t, sx, sy, ex, ey;
    cin >> t >> sx >> sy >> ex >> ey;
    int x_diff = ex-sx, y_diff = ey-sy;
    string s;
    cin >> s;
    int n_count = 0, e_count = 0, s_count = 0, w_count = 0;
    bool x_can = x_diff == 0, y_can = y_diff == 0, broken = false;
    for (int i = 0; i < t; i++) {
        if (s[i] == 'N') {
            n_count++;
        } else if (s[i] == 'E') {
            e_count++;
        } else if (s[i] == 'S') {
            s_count++;
        } else {
            w_count++;
        }
        if (x_diff > 0) {
            if (e_count >= x_diff) {
                x_can = true;
            }
        } else if (x_diff < 0) {
            if (w_count >= -x_diff) {
                x_can = true;
            }
        }
        if (y_diff > 0) {
            if (n_count >= y_diff) {
                y_can = true;
            }
        } else if (y_diff < 0) {
            if (s_count >= -y_diff) {
                y_can = true;
            }
        }
        if (x_can && y_can) {
            cout << i+1;
            broken = true;
            break;
        }
    }
    if (!broken) {
        cout << -1;
    }
    return 0;
}
