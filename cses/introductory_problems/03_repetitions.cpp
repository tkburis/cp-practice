// https://cses.fi/problemset/task/1069

#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cin >> s;
    int all_best = 0, curr = 1;
    for (int i = 1; i < s.length(); i++) {
        if (s[i] == s[i-1]) {
            curr++;
        } else {
            all_best = max(all_best, curr);
            curr = 1;
        }
    }
    all_best = max(all_best, curr);
    cout << all_best;
    return 0;
}
