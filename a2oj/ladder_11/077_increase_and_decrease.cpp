// https://codeforces.com/problemset/problem/246/B

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, sum = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int t;
        cin >> t;
        sum += t;
    }
    if (sum % n == 0) {
        cout << n;
    } else {
        cout << n-1;
    }
    return 0;
}
