// https://codeforces.com/problemset/problem/447/B

#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cin >> s;
    int k;
    cin >> k;
    int w[26], maxi = 0;
    for (int i = 0; i < 26; i++) {
        int t;
        cin >> t;
        w[i] = t;
        maxi = max(maxi, t);
    }
    int ans = 0;
    for (int i = 1; i <= s.length(); i++) {
        ans += (i * w[s[i-1]-'a']);
    }
    for (int i = s.length()+1; i <= s.length()+k; i++) {
        ans += i * maxi;
    }
    cout << ans << '\n';
    return 0;
}
