// https://codeforces.com/problemset/problem/339/B

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    long long tot = 0, curr = 1;
    for (int i = 0; i < m; i++) {
        int a;
        cin >> a;
        if (a < curr) {
            tot += (n - curr) + a;
        } else {
            tot += (a - curr);
        }
        curr = a;
    }
    cout << tot;
    return 0;
}
