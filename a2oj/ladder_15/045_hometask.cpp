#include <bits/stdc++.h>
using namespace std;

#define MOD 1e9+7
#define debug(x) cout << #x << " = " << x << "\n";
#define vdebug(a) cout << #a << " = "; for(auto x: a) cout << x << " "; cout << "\n";

typedef long long ll;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    int num_zero = 0, mod1 = 0, mod2 = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (a[i] == 0) num_zero++;
        if (a[i] % 3 == 1) mod1++;
        if (a[i] % 3 == 2) mod2++;
    }
    if (num_zero == 0) {
        cout << "-1\n";
        return;
    }
    sort(a.begin(), a.end(), greater<>());
    int curr_sum = accumulate(a.begin(), a.end()-num_zero, 0);
    int rem1 = 0, rem2 = 0;
    if (curr_sum % 3 == 2) {
        if (mod2 >= 1) {
            rem2 = 1;
        } else if (mod1 >= 2) {
            rem1 = 2;
        } else {
            cout << "-1\n";
            return;
        }
    } else if (curr_sum % 3 == 1) {
        if (mod1 >= 1) {
            rem1 = 1;
        } else if (mod2 >= 2) {
            rem2 = 2;
        } else {
            cout << "-1\n";
            return;
        }
    }
    int i = n-1-num_zero;
    while (rem1 > 0 || rem2 > 0) {
        if (rem1 > 0 && a[i] % 3 == 1) {
            a.erase(a.begin()+i);
            rem1--;
        } else if (rem2 > 0 && a[i] % 3 == 2) {
            a.erase(a.begin()+i);
            rem2--;
        }
        i--;
    }
    while (a[0] == 0 && a.size() > 1) a.erase(a.begin());
    for (int x : a) cout << x;
    cout << '\n';
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
