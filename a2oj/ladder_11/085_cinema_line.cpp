// https://codeforces.com/problemset/problem/349/A

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, twentyfive = 0, fifty = 0;
    bool broken = false;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        if (a == 25) {
            twentyfive++;
        } else if (a == 50) {
            twentyfive--;
            fifty++;
        } else if (a == 100) {
            if (fifty > 0) {
                twentyfive--;
                fifty--;
            } else {
                twentyfive -= 3;
            }
        }
        if (twentyfive < 0) {
            broken = true;
            break;
        }
    }
    if (broken) {
        cout << "NO";
    } else {
        cout << "YES";
    }
    return 0;
}
