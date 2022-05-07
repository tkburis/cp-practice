#include <bits/stdc++.h>
using namespace std;

#define MOD 1e9+7
#define debug(x) cout << #x << " = " << x << "\n";
#define vdebug(a) cout << #a << " = "; for(auto x: a) cout << x << " "; cout << "\n";

typedef long long ll;

bool op(pair<int, int> a, pair<int, int> b)
{
    if (abs(a.first) < abs(b.first)) return true;
    if (abs(a.first) == abs(b.first) && abs(a.second) < abs(b.second)) return true;
    return false;
}

void solve()
{
    int n;
    cin >> n;
    vector<pair<int, int>> coords(n);
    int a, b;
    for (int i = 0; i < n; i++) {
        cin >> a >> b;
        coords[i] = make_pair(a, b);
    }
    int s = 0;
    for (int i = 0; i < n; i++) {
        if (coords[i].first == 0 || coords[i].second == 0) {
            s += 4;
        } else {
            s += 6;
        }
    }
    cout << s << '\n';
    sort(coords.begin(), coords.end(), op);
    for (pair<int, int> xy : coords) {
        if (xy.first > 0) {
            cout << "1 " << xy.first << " R\n";
        } else if (xy.first < 0) {
            cout << "1 " << -xy.first << " L\n";
        }
        if (xy.second > 0) {
            cout << "1 " << xy.second << " U\n";
        } else if (xy.second < 0) {
            cout << "1 " << -xy.second << " D\n";
        }
        cout << "2\n";
        if (xy.first > 0) {
            cout << "1 " << xy.first << " L\n";
        } else if (xy.first < 0) {
            cout << "1 " << -xy.first << " R\n";
        }
        if (xy.second > 0) {
            cout << "1 " << xy.second << " D\n";
        } else if (xy.second < 0) {
            cout << "1 " << -xy.second << " U\n";
        }
        cout << "3\n";
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
