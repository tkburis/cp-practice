// https://cses.fi/problemset/task/1624

#include <bits/stdc++.h>
using namespace std;

int cnt = 0, n = 8;
vector<bool> columns(n, false), diag1(n*2, false), diag2(n*2, false);
vector<vector<char>> grid(n, vector<char>(n));

void queens(int curr_row) {
    if (curr_row == n) {
        cnt++;
        return;
    }
    for (int col = 0; col < n; col++) {
        if (columns[col] || diag1[curr_row+col] || diag2[n-curr_row-1+col] || grid[curr_row][col] == '*') {
            continue;
        }
        columns[col] = diag1[curr_row+col] = diag2[n-curr_row-1+col] = true;
        queens(curr_row+1);
        columns[col] = diag1[curr_row+col] = diag2[n-curr_row-1+col] = false;
    }
}

int main()
{
    for (int y = 0; y < n; y++) {
        for (int x = 0; x < n; x++) {
            cin >> grid[y][x];
        }
    }
    queens(0);
    cout << cnt << endl;
    return 0;
}
