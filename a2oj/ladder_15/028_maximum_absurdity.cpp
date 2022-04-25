#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long n, k;
    cin >> n >> k;
    vector<long long> x(n);
    for (long long i = 0; i < n; i++) cin >> x[i];
    vector<long long> sums(n-k+1);
    for (long long i = 0; i < k; i++) {
        sums[0] += x[i];
    }
    for (long long i = 1; i < n-k+1; i++) {
        sums[i] = sums[i-1] + x[i+k-1] - x[i-1];
    }
    vector<long long> max_before(n-k+1), max_after(n-k+1);  // inclusive
    max_before[0] = sums[0];
    for (long long i = 1; i < n-k+1; i++) {
        max_before[i] = max(max_before[i-1], sums[i]);
    }
    max_after[n-k] = sums[n-k];
    for (long long i = n-k-1; i >= 0; i--) {
        max_after[i] = max(max_after[i+1], sums[i]);
    }
    long long ans = 0;
    long long best_before, best_after;
    for (long long i = 0; i < n-2*k+1; i++) {
        if (max_before[i] + max_after[i+k] > ans) {
            ans = max_before[i] + max_after[i+k];
            best_before = max_before[i];
            best_after = max_after[i+k];
        }
    }
    long long i;
    for (i = 0; i < n-k+1; i++) {
        if (sums[i] == best_before) {
            cout << i+1 << ' ';
            break;
        }
    }
    for (i += k; i < n-k+1; i++) {
        if (sums[i] == best_after) {
            cout << i+1 << ' ';
            break;
        }
    }
    return 0;
}