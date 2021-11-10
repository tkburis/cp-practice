// https://codeforces.com/problemset/problem/363/B

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    int h[n+1];
    for (int i = 1; i <= n; i++) {
        cin >> h[i];
    }
    int curr_sum = 0;
    for (int i = 1; i <= k; i++) {
        curr_sum += h[i];
    }
    int mini_sum = curr_sum, best_i = 1;
    for (int i = 2; i <= n - k + 1; i++) {
        curr_sum += (h[i+k-1] - h[i-1]);
        if (curr_sum <= mini_sum) {
            mini_sum = curr_sum;
            best_i = i;
        }
    }
    cout << best_i;
    return 0;
}
