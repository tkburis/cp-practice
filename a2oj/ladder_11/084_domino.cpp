// https://codeforces.com/problemset/problem/353/A

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int sum_left = 0, sum_right = 0;
    bool have_diff = false;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        sum_left += a;
        sum_right += b;
        if (a % 2 != b % 2) {
            have_diff = true;
        }
    }
    if (sum_left % 2 == 0 && sum_right % 2 == 0) {
        cout << 0;
    } else if (sum_left % 2 == sum_right % 2 && have_diff) {
        cout << 1;
    } else {
        cout << -1;
    }
    return 0;
}
