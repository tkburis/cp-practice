// https://codeforces.com/problemset/problem/118/B

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    for (int i = -n; i <= n; i++) {
        int maxi = n - abs(i);
        for (int j = 0; j < abs(i); j++) {
            cout << "  ";
        }
        for (int j = 0; j < maxi; j++) {
            cout << j << ' ';
        }
        for (int j = maxi; j > 0; j--) {
            cout << j << ' ';
        }
        cout << 0 << endl;
    }
    return 0;
}
