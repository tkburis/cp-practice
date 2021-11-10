// https://codeforces.com/problemset/problem/287/A

#include <bits/stdc++.h>
using namespace std;

bool three_eq(const char a, const char b, const char c) {
    return (a == b && b == c);
}

int main()
{
    char grid[6][6];
    for (int i = 0; i < 6; i++) {
        grid[0][i] = i+'0';  // to make sure that they are distinct, hence not intefering with our checking function
        grid[5][i] = i+'0';
    }
    for (int i = 1; i <= 4; i++) {
        string s;
        cin >> s;
        grid[i][0] = i+'0';
        grid[i][5] = i+'0';
        for (int j = 1; j <= 4; j++) {
            grid[i][j] = s[j-1];
        }
    }
    bool can = false;
    for (int i = 1; i <= 4; i++) {
        if (can) {
            break;
        }
        for (int j = 1; j <= 4; j++) {
            if (three_eq(grid[i-1][j-1], grid[i-1][j], grid[i][j-1])) can = true;
            else if (three_eq(grid[i-1][j], grid[i-1][j+1], grid[i][j+1])) can = true;
            else if (three_eq(grid[i][j-1], grid[i+1][j-1], grid[i+1][j])) can = true;
            else if (three_eq(grid[i][j+1], grid[i+1][j+1], grid[i+1][j])) can = true;
        }
    }
    if (can) {
        cout << "YES";
    } else {
        cout << "NO";
    }
    return 0;
}
