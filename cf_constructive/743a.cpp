#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, a, b;
    cin >> n >> a >> b;
    a--; b--;
    string s;
    cin >> s;
    
    if (s[a] == s[b]) cout << 0 << '\n';
    else {
        cout << 1 << '\n';
    }
    return 0;
}