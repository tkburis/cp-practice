// https://codeforces.com/problemset/problem/352/A

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n = 0, five_cnt = 0, zero_cnt = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int t;
        cin >> t;
        if (t == 5) {
            five_cnt++;
        } else {
            zero_cnt++;
        }
    }
    int used_fives = five_cnt - (five_cnt % 9);
    if (zero_cnt == 0) {
        cout << -1;
    } else if (used_fives == 0) {
        cout << 0;
    } else {
        for (int i = 0; i < used_fives; i++) {
            cout << 5;
        }
        for (int i = 0; i < zero_cnt; i++) {
            cout << 0;
        }
    }
    return 0;
}
