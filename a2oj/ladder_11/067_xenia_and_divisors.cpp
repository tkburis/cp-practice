// https://codeforces.com/problemset/problem/342/A

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, counts[8] = {0};
    cin >> n;
    for (int i = 0; i < n; i++) {
        int t;
        cin >> t;
        counts[t]++;
    }
    if (counts[5] == 0 && counts[7] == 0 && counts[1] == n/3 && counts[2] >= counts[4] && counts[6] >= counts[3] && counts[2] + counts[3] == counts[4] + counts[6]) {
        for (int i = 0; i < counts[4]; i++) {
            cout << "1 2 4" << endl;
        }
        counts[2] -= counts[4];
        for (int i = 0; i < counts[2]; i++) {
            cout << "1 2 6" << endl;
        }
        for (int i = 0; i < counts[3]; i++) {
            cout << "1 3 6" << endl;
        }
    }
    else {
        cout << -1;
    }
    return 0;
}
