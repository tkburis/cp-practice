#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007
#define debug(x) cout << #x << " = " << x << '\n';
#define vdebug(v) cout << #v << " = "; for(auto x : v) cout << x << ' '; cout << '\n';
#define pdebug(p) cout << #p << " = " << p.first << ' ' << p.second << '\n';

typedef long long ll;

void solve()
{
    string s;
    cin >> s;
    int n = s.length();
    vector<pair<char, int>> rle;
    char prev = s[0], curr;
    int cnt = 1;
    for (int i = 1; i < n; i++) {
        curr = s[i];
        if (curr == prev) {
            cnt++;
        } else {
            rle.push_back(make_pair(prev, cnt));
            cnt = 1;
        }
        prev = curr;
    }
    rle.push_back(make_pair(prev, cnt));
    if (rle[0].second > 2) rle[0].second = 2;
    for (int i = 1; i < rle.size(); i++) {
        if (rle[i].second >= 2) {
            if (rle[i-1].second == 2) {
                rle[i].second = 1;
            } else {
                rle[i].second = 2;
            }
        }
    }
    for (auto p : rle) {
        while (p.second--) cout << p.first;
    }
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
