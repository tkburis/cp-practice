#include <bits/stdc++.h>
using namespace std;

int main()
{
    int m, n;
    cin >> m >> n;
    vector<vector<int>> grid(m, vector<int>(n));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) cin >> grid[i][j];
    }
    vector<bool> row(m, true), col(n, true);
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == 0) {
                row[i] = false;
                col[j] = false;
            }
        }
    }
    vector<vector<int>> new_grid(m, vector<int>(n, 1));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (row[i] == false || col[j] == false) {
                new_grid[i][j] = 0;
            }
        }
    }
    vector<vector<int>> check_grid(m, vector<int>(n));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            bool ok = false;
            for (int y = 0; y < m; y++) {
                if (new_grid[y][j] == 1) ok = true;
            }
            for (int x = 0; x < n; x++) {
                if (new_grid[i][x] == 1) ok = true;
            }
            if (ok) check_grid[i][j] = 1;
            else check_grid[i][j] = 0;
        }
    }
    if (check_grid != grid) {
        cout << "NO" << '\n';
    } else {
        cout << "YES" << '\n';
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                cout << new_grid[i][j] << ' ';
            }
            cout << '\n';
        }
    }
    return 0;
}