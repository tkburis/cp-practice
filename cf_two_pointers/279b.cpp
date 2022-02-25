#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, t;
    cin >> n >> t;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    int j = 0, curr_sum = 0, best = 0;
    for (int i = 0; i < n; i++) {
        while (j < n && curr_sum + a[j] <= t) {
            curr_sum += a[j];
            j++;
        }
        best = max(best, j-i);
        curr_sum -= a[i];
    }
    cout << best << '\n';
    return 0;
}