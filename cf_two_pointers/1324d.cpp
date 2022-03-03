#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];

    vector<int> diffs(n);
    for (int i = 0; i < n; i++) diffs[i] = a[i] - b[i];
    sort(diffs.begin(), diffs.end());

    long long cnt = 0;
    for (int i = 0; i < n; i++) {
        // cout << diffs[i] << ": ";
        if (diffs[i] > 0) {
            cnt += n - i - 1;
        } else {
            cnt += n - (lower_bound(diffs.begin(), diffs.end(), 1 - diffs[i]) - diffs.begin());
        }
        // cout << cnt << '\n';
    }
    cout << cnt << '\n';

    return 0;
}