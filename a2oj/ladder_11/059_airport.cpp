// https://codeforces.com/problemset/problem/218/B

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> a(m);
    priority_queue<int> maxi;
    priority_queue<int, vector<int>, greater<int>> mini;
    for (int i = 0; i < m; i++) {
        int t;
        cin >> t;
        a[i] = t;
        maxi.push(t);
        mini.push(t);
    }
    int mx = 0, mn = 0;
    for (int i = 0; i < n; i++) {
        int temp = maxi.top();
        maxi.pop();
        mx += temp;
        if (temp > 1) {
            maxi.push(temp-1);
        }
        temp = mini.top();
        mini.pop();
        mn += temp;
        if (temp > 1) {
            mini.push(temp-1);
        }
    }
    cout << mx << ' ' << mn;
    return 0;
}
