// https://codeforces.com/problemset/problem/205/A

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n = 0, mini = INT_MAX, cnt = 0, found_at = 0;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int temp = 0;
        cin >> temp;
        if (temp < mini) {
            mini = temp;
            found_at = i;
            cnt = 1;
        } else if (temp == mini) {
            cnt += 1;
        }
    }
    if (cnt > 1) {
        cout << "Still Rozdil";
    } else {
        cout << found_at;
    }
    return 0;
}
