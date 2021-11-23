// https://cses.fi/problemset/task/1755

#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> cnts(26, 0);
    string s;
    cin >> s;
    for (char c : s) {
        cnts[c - 'A']++;
    }
    int num_odds = 0, odd_index;
    for (int i = 0; i < 26; i++) {
        if (cnts[i] % 2 == 1) {
            num_odds++;
            odd_index = i;
        }
        if (num_odds > 1) {
            cout << "NO SOLUTION" << endl;
            return 0;
        }
    }
    string left_side = "";
    for (int i = 0; i < 26; i++) {
        if (cnts[i] % 2 == 0 && cnts[i] != 0) {
            for (int j = 0; j < cnts[i] / 2; j++) {
                left_side += ('A' + i);
            }
        }
    }
    string right_side = left_side;
    reverse(right_side.begin(), right_side.end());
    if (num_odds == 1) {
        for (int i = 0; i < cnts[odd_index]; i++) {
            left_side += ('A' + odd_index);
        }
    }
    cout << left_side + right_side << endl;
    return 0;
}
