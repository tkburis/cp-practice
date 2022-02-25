#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        bool is_pos = true;
        if (a[0] < 0) {
            is_pos = false;
        }
        long long ans = 0;
        int best = 0;
        for (int i = 0; i < n; i++) {
            if (a[i] > 0 != is_pos) {
                ans += best;
                best = 0;
                is_pos = !is_pos;
            }
            if (a[i] < 0 && best == 0) best = a[i];
            best = max(best, a[i]);
        }
        ans += best;
        cout << ans << '\n';
    }
    return 0;
}