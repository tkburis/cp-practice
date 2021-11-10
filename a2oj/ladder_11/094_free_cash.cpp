// https://codeforces.com/problemset/problem/237/A

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, curr_same = 1, maxi = 1;
    cin >> n;
    int a, b;
    cin >> a >> b;
    pair<int, int> last{a, b};
    for (int i = 1; i < n; i++) {
        int a, b;
        cin >> a >> b;
        pair<int, int> curr{a, b};
        if (curr == last) {
            curr_same++;
            maxi = max(maxi, curr_same);
        } else {
            curr_same = 1;
        }
        last = curr;
    }
    cout << maxi;
    return 0;
}
