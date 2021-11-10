// https://codeforces.com/problemset/problem/149/A

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int k;
    cin >> k;
    vector<int> a(12);
    for (int i = 0; i < 12; i++) {
        cin >> a[i];
    }
    if (accumulate(a.begin(), a.end(), 0) < k) {
        cout << -1;
        return 0;
    }
    sort(a.begin(), a.end(), greater<>());
    int sum = 0, cnt = 0;
    while (sum < k && cnt < 12) {
        sum += a[cnt];
        cnt++;
    }
    cout << cnt;
    return 0;
}
