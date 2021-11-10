// https://codeforces.com/problemset/problem/315/A

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int a[n], b[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i] >> b[i];
    }
    int sum = 0;
    for (int i = 0; i < n; i++) {
        bool can = false;
        for (int j = 0; j < n; j++) {
            if (i != j) {
                if (a[i] == b[j]) {
                    can = true;
                    break;
                }
            }
        }
        if (!can) sum++;
    }
    cout << sum;
    return 0;
}
