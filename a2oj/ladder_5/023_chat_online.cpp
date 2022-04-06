#include <bits/stdc++.h>
using namespace std;

int main()
{
    int p, q, l, r;
    cin >> p >> q >> l >> r;
    vector<bool> z(2002);
    vector<pair<int, int>> x(q);
    for (int i = 0; i < p; i++) {
        int a, b;
        cin >> a >> b;
        for (int j = a; j <= b; j++) z[j] = true;
    }
    for (int i = 0; i < q; i++) {
        int c, d;
        cin >> c >> d;
        x[i] = make_pair(c, d);
    }

    int cnt = 0;
    bool found;
    for (int i = l; i <= r; i++) {
        found = false;
        for (auto p : x) {
            if (found) break;
            for (int j = p.first; j <= p.second; j++) {
                if (z[j+i]) {
                    cnt++;
                    found = true;
                    break;
                }
            }
        }
    }
    cout << cnt << '\n';
    return 0;
}
