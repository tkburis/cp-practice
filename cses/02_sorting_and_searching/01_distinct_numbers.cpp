// https://cses.fi/problemset/task/1621

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    unordered_set<int> alr(n);
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        alr.insert(x);
    }
    cout << alr.size() << endl;
    return 0;
}
