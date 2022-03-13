#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, s, t;
    cin >> n >> s >> t;
    vector<int> p(n+1);
    for (int i = 1; i <= n; i++) cin >> p[i];

    set<int> vis;
    int curr = s;
    if (s == t) {
        cout << 0 << '\n';
    } else {
        for (int i = 1; i <= n; i++) {
            if (vis.find(curr) != vis.end()) {
                cout << -1 << '\n';
                break;
            }
            vis.insert(curr);
            curr = p[curr];
            if (curr == t) {
                cout << i << '\n';
                break;
            }
        }
    }
    return 0;
}