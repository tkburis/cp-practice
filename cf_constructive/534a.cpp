#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    if (n == 1 || n == 2) {
        cout << 1 << '\n' << 1;
    } else if (n == 3) {
        cout << 2 << '\n' << "1 3";
    } else {
        cout << n << '\n';
        for (int i = 2; i <= n; i += 2) {
            cout << i << ' ';
        }
        for (int i = 1; i <= n; i += 2) {
            cout << i << ' ';
        }
    }
    return 0;
}