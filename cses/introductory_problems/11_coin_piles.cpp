// https://cses.fi/problemset/task/1754

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    int t;
    cin >> t;
    while (t--) {
        ll a, b;
        cin >> a >> b;
        ll lower = min(a, b), higher = max(a, b);
        if (higher <= lower * 2 && (lower - (higher - lower)) % 3 == 0) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    return 0;
}
