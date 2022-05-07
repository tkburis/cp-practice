#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007
#define debug(x) cout << #x << " = " << x << "\n";
#define vdebug(a) cout << #a << " = "; for(auto x: a) cout << x << " "; cout << "\n";

typedef long long ll;

void solve()
{
    int n;
    cin >> n;
    vector<int> t1, t2;
    int a, b;
    for (int i = 0; i < n; i++) {
        cin >> a >> b;
        if (a == 1) {
            t1.push_back(b);
        } else {
            t2.push_back(b);
        }
    }
    sort(t1.begin(), t1.end()); sort(t2.begin(), t2.end());
    int ans = INT_MAX, w;
    for (int i = 0; i <= t1.size(); i++) {
        for (int j = 0; j <= t2.size(); j++) {
            w = 0;
            w += accumulate(t1.begin(), t1.end()-i, 0);
            w += accumulate(t2.begin(), t2.end()-j, 0);
            // debug(w); debug(i+2*j);
            if (w <= i+2*j) ans = min(ans, i+2*j);
        }
    }
    cout << ans << '\n';
    return;
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) solve();
    return 0;
}
