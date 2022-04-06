#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, t;
    cin >> n >> t;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    int i = 0, j = 0, curr_sum = 0, best = 0;
    while (j < n) {
        if (curr_sum + a[j] > t) {
            if (i == j) {
                curr_sum += a[j];
                j++;
            }
            else {
                curr_sum -= a[i];
                i++;
            }
        } else {
            curr_sum += a[j];
            j++;
            best = max(best, j-i);
        }
        // cout << curr_sum << ", " << i << "," << j << '\n';
    }
    cout << best << '\n';
    return 0;
}
