// https://codeforces.com/problemset/problem/327/A

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int a[n], b[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (a[i] == 0) {
            b[i] = 1;
        } else {
            b[i] = -1;
        }
    }
    int curr_max = 0, all_max = INT_MIN;
    for (int i = 0; i < n; i++) {
        curr_max = max(curr_max + b[i], b[i]);
        all_max = max(all_max, curr_max);
    }
    cout << all_max + accumulate(a, a+n, 0);
    return 0;
}
