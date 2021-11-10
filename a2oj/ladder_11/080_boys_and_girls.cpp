// https://codeforces.com/problemset/problem/253/A

#include <bits/stdc++.h>
using namespace std;

int main()
{
    ifstream cin("input.txt");
    ofstream cout("output.txt");
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < min(n, m); i++) {
        if (n > m) {
            cout << "BG";
        }
        else {
            cout << "GB";
        }
    }
    if (n > m) {
        for (int i = 0; i < n-m; i++) {
            cout << "B";
        }
    } else {
        for (int i = 0; i < m-n; i++) {
            cout << "G";
        }
    }
    return 0;
}
