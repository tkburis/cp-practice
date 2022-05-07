#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007
#define debug(x) cout << #x << " = " << x << "\n";
#define vdebug(a) cout << #a << " = "; for(auto x : a) cout << x << " "; cout << "\n";

typedef long long ll;

vector<int> calc_z(string s)
{
    int l = 0, r = 0, n = s.length(), k;
    vector<int> z(n); z[0] = 0;
    for (int i = 1; i < n; i++) {
        if (i > r) {  // new element
            l = r = i;
            while (r < n && s[r] == s[r-l]) r++;
            z[i] = r - l;
            r--;
        } else {  // in z-box
            k = i - l;
            if (z[k] + i < r + 1) z[i] = z[k];  // doesn't exceed current box
            else {  // exceeds current box; check if more matches
                l = i;
                while (r < n && s[r] == s[r-l]) r++;
                z[i] = r - l;
                r--;
            }
        }
    }
    return z;
}

void solve()
{
    string s;
    cin >> s;
    int n = s.length();
    vector<int> z = calc_z(s), max_z(n);
    max_z[0] = z[0];
    for (int i = 1; i < n; i++) {
        max_z[i] = max(max_z[i-1], z[i]);
    }
    int ans = -1;
    for (int i = 1; i < n; i++) {
        if (z[i] == n - i && max_z[i-1] >= z[i]) {
            ans = z[i];
            break;
        }
    }
    if (ans == -1) {
        cout << "Just a legend\n";
    } else {
        cout << s.substr(0, ans) << '\n';
    }
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
