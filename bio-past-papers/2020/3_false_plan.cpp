// https://olympiad.org.uk/papers/2020/bio/bio20-exam.pdf

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll p, q, r;
ll n;

ll fs[12][13];

void fill_table()
{
    for (int i = 1; i <= q; i++) {
        fs[0][i] = 1;
    }
    for (int i = 1; i < r; i++)  {
        for (int j = 1; j <= q; j++) {
            fs[i][j] = (p-1)*fs[i-1][1];
            if (j != q) {
                fs[i][j] += fs[i-1][j+1];
            }
        }
    }
}

string solve()
{
    string s = "";
    char prev;
    ll current_bottom = 1;
    for (int lvl = 0; lvl < p; lvl++) {
        ll this_top = current_bottom + fs[r-1][1] - 1;
        if (current_bottom <= n && n <= this_top) {
            prev = 'A' + lvl;
            s += ('A' + lvl);
            break;
        }
        current_bottom = this_top + 1;
    }
    ll curr_alr = 1;
    for (int i = 2; i <= r; i++) {
        for (int lvl = 0; lvl < p; lvl++) {
            char to_add = 'A' + lvl;
            ll this_top = current_bottom;
            if (to_add == prev) {
                if (curr_alr == q) {
                    continue;
                }
                this_top += fs[r-i][curr_alr+1] - 1;
            } else {
                this_top += fs[r-i][1] - 1;
            }
            if (current_bottom <= n && n <= this_top) {
                if (to_add == prev) {
                    curr_alr++;
                } else {
                    curr_alr = 1;
                }
                prev = to_add;
                s += to_add;
                break;
            }
            current_bottom = this_top + 1;
        }
    }
    return s;
}

int main()
{
    // Task 1
    cin >> p >> q >> r >> n;
    fill_table();
    cout << solve();
    return 0;
}
