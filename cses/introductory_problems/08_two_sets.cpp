// https://cses.fi/problemset/task/1092

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    if (n % 4 == 0) {
        cout << "YES\n" << n/2 << '\n';
        for (int i = 1; i <= n; i+=4) {
            cout << i << ' ' << i+3 << ' ';
        }
        cout << '\n' << n/2 << '\n';
        for (int i = 1; i <= n; i+=4) {
            cout << i+1 << ' ' << i+2 << ' ';
        }
    } else if (n % 4 == 3) {
        cout << "YES\n" << n/2 + 1 << "\n1 2 ";
        for (int i = 4; i <= n; i+=4) {
            cout << i << ' ' << i+3 << ' ';
        }
        cout << '\n' << n/2 << "\n3 ";
        for (int i = 4; i <= n; i+=4) {
            cout << i+1 << ' ' << i+2 << ' ';
        }
    } else {
        cout << "NO";
    }
    return 0;
}
