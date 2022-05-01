#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long n, k;
    cin >> n >> k;
    vector<long long> a(n);
    for (long long i = 0; i < n; i++) cin >> a[i];
    sort(a.begin(), a.end());
    long long best = 1, best_elem = a[0];
    long long j = 0;
    long long sum = a[1] - a[0];
    // for (long long x : a) cout << x << ' ';
    // cout << '\n';
    for (long long i = 1; i < n; i++) {
        if (i > 1) {
            sum += (a[i] - a[i-1]) * (i-j);
        }
        // cout << "**SUM: " << sum << " i: " << i << " j: " << j << '\n';
        while (j < i && sum > k) {
            sum -= a[i] - a[j];
            j++;
            // cout << "sum: " << sum << " i: " << i << " j: " << j << '\n';
        }
        if (i-j+1 > best) {
            best = i-j+1;
            best_elem = a[i];
        }
    }
    cout << best << ' ' << best_elem << '\n';
    return 0;
}
