// https://codeforces.com/problemset/problem/58/A

#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s, h = "hello";
    cin >> s;
    int h_index = 0;
    for (char c : s) {
        if (c == h[h_index]) {
            h_index++;
        }
    }
    if (h_index >= 5) {
        cout << "YES";
    } else {
        cout << "NO";
    }
    return 0;
}
