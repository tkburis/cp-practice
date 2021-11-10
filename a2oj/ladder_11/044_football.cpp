// https://codeforces.com/problemset/problem/43/A

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    string team1, team2;
    int team1_score = 1, team2_score = 0;
    cin >> team1;
    for (int i = 1; i < n; i++) {
        string t;
        cin >> t;
        if (t == team1) {
            team1_score++;
        } else {
            team2 = t;
            team2_score++;
        }
    }
    if (team1_score > team2_score) {
        cout << team1;
    } else {
        cout << team2;
    }
    return 0;
}
