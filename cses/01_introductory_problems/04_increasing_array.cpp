// https://cses.fi/problemset/task/1094

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    int n;
    cin >> n;
    int x[n];
    for (int i = 0; i < n; i++) {
        cin >> x[i];
    }
    int curr_min = 0;
    ll sum = 0;
    for (int i = 0; i < n; i++) {
        if (x[i] > curr_min) {
            curr_min = x[i];
        } else {
            sum += curr_min - x[i];
        }
    }
    cout << sum;
    return 0;
}
