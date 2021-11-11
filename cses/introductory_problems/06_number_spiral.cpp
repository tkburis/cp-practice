// https://cses.fi/problemset/task/1071/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    int t;
    cin >> t;
    while (t--) {
        ll y, x;
        cin >> y >> x;
        if (y > x) {
            if (y % 2 == 0) {
                cout << (y * y) - x + 1;
            } else {
                cout << ((y-1) * (y-1)) + x;
            }
        } else {
            if (x % 2 == 0) {
                cout << ((x-1) * (x-1)) + y;
            } else {
                cout << (x * x) - y + 1;
            }
        }
        cout << '\n';
    }
    return 0;
}
