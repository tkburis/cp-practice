// https://codeforces.com/problemset/problem/118/A

#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s, t;
    cin >> s;
    for (auto c : s) {
        t += (char)tolower(c);
    }
    for (int i = 0; i < t.size(); i++) {
        if (t[i] == 'a' || t[i] == 'o' || t[i] == 'y' || t[i] == 'e' || t[i] == 'u' || t[i] == 'i'){
            continue;
        }
        cout << '.' << t[i];
    }
    return 0;
}
