#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    int n;
    cin >> n;
    vector<ll> prefix(n);
    int t;
    for (int i = 0; i < n; i++) {
        cin >> t;
        if (i == 0) {
            prefix[i] = t;
        } else {
            prefix[i] = prefix[i-1] + t;
        }
    }

    if (prefix[n-1] % 3 != 0) {
        cout << 0 << '\n';
        return 0;
    }

    ll p1 = prefix[n-1] / 3, p2 = p1 * 2;
    vector<int> idxs1, idxs2;
    for (int i = 0; i < n-1; i++) {
        if (prefix[i] == p1) idxs1.push_back(i);
        if (prefix[i] == p2) idxs2.push_back(i);
    }
    ll ans = 0;
    for (int idx : idxs1) {
        ans += idxs2.end() - lower_bound(idxs2.begin(), idxs2.end(), idx+1);
    }
    cout << ans << '\n';

    return 0;
}