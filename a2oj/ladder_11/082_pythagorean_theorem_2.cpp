// https://codeforces.com/problemset/problem/304/A

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int cnt = 0;
    double c;
    for (int a = 1; a <= n; a++) {
        for (int b = a+1; b <= n; b++) {
            c = a*a + b*b;
            c = sqrt(c);
            if (c == floor(c) && c <= n) {
                cnt++;
            }
        }
    }
    cout << cnt;
    return 0;
}
