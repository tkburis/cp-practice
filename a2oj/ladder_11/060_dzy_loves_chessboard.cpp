// https://codeforces.com/problemset/problem/445/A

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<char>> board(n);
    for (int i = 0; i < n; i++) {
        string t;
        cin >> t;
        vector<char> temp(t.begin(), t.end());
        board[i] = temp;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (board[i][j] == '.') {
                if (i % 2 == j % 2 == 0) {
                    cout << 'B';
                } else {
                    cout << 'W';
                }
            } else {
                cout << '-';
            }
        }
        cout << endl;
    }
    return 0;
}
