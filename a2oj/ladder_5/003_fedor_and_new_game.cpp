// https://codeforces.com/problemset/problem/467/B

#include <bits/stdc++.h>
using namespace std;

int count_bits(int n) {
    if (n == 0) return 0;
    return 1 + count_bits(n & (n-1));
}

int main()
{
    int n, m, k;
    cin >> n >> m >> k;
    int xs[m];
    for (int i = 0; i < m; i++) {
        cin >> xs[i];
    }
    int target, cnt = 0;
    cin >> target;
    for (int x : xs) {
        int diff = x ^ target;
        if (count_bits(diff) <= k) {
            cnt++;
        }
    }
    cout << cnt;
    return 0;
}
