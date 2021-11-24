// https://olympiad.org.uk/papers/2017/bio/bio17-exam.pdf

#include <bits/stdc++.h>
using namespace std;

int p1, m1, p2, m2, t;
bool p1_turn = true;

/*
*.*.*.*.*.*
...........
*.*.*.*.*.*
...........
etc.
 */

void init_grid(vector<vector<char>>& grid) {
    for (int i = 0; i <= 10; i++) {
        for (int j = 0; j <= 10; j++) {
            if (i % 2 == 0 && j % 2 == 0) {
                grid[i][j] = '*';
            } else {
                grid[i][j] = '.';
            }
        }
    }
}

void print_grid(vector<vector<char>> grid) {
    for (auto row : grid) {
        for (auto c : row) {
            if (c != '.') cout << c << ' ';
            else cout << "  ";
        }
        cout << '\n';
    }
}

int count_squares(vector<vector<char>> grid) {
    int ret = 0;
    for (int i = 1; i <= 9; i += 2) {
        for (int j = 1; j <= 9; j += 2) {
            if (grid[j-1][i] == '-' && grid[j+1][i] == '-' && grid[j][i-1] == '-' && grid[j][i+1] == '-') {
                ret++;
            }
        }
    }
    return ret;
}

void player1(vector<vector<char>>& grid, int& pos) {
    pos = (pos + m1) % 36;
    if (pos == 0) {
        pos = 36;
    }
    int x = ((pos-1) % 6) * 2;
    int y = ((pos-1) / 6) * 2;
    cout << pos << " -> " << x << ' ' << y << '\n';
    int before_squares = count_squares(grid);
    bool done = false;
    if (y-1 >= 0) {  // up
        if (grid[y-1][x] == '.') {
            grid[y-1][x] = '-';
            done = true;
        }
    }
    if (x+1 <= 10 && !done) {  // right
        if (grid[y][x+1] == '.') {
            grid[y][x+1] = '-';
            done = true;
        }
    }
    if (y+1 <= 10 && !done) {  // down
        if (grid[y+1][x] == '.') {
            grid[y+1][x] = '-';
            done = true;
        }
    }
    if (x-1 >= 0 && !done) {  // left
        if (grid[y][x-1] == '.') {
            grid[y][x-1] = '-';
            done = true;
        }
    }
    if (!done) {
        player1(grid);
    }
    if (before_squares < count_squares(grid)) {
        p1_turn = true;
    } else {
        p1_turn = false;
    }
}

void player2(vector<vector<char>>& grid, int& pos) {
    pos = (pos + m2) % 36;
    if (pos == 0) {
        pos = 36;
    }
    int x = ((pos-1) % 6) * 2;
    int y = ((pos-1) / 6) * 2;
    cout << pos << " -> " << x << ' ' << y << '\n';
    int before_squares = count_squares(grid);
    bool done = false;
    if (y-1 >= 0) {  // up
        if (grid[y-1][x] == '.') {
            grid[y-1][x] = '-';
            done = true;
        }
    }
    if (x-1 >= 0 && !done) {  // left
        if (grid[y][x-1] == '.') {
            grid[y][x-1] = '-';
            done = true;
        }
    }
    if (y+1 <= 10 && !done) {  // down
        if (grid[y+1][x] == '.') {
            grid[y+1][x] = '-';
            done = true;
        }
    } 
    if (x+1 <= 10 && !done) {  // right
        if (grid[y][x+1] == '.') {
            grid[y][x+1] = '-';
            done = true;
        }
    }
    if (before_squares < count_squares(grid)) {
        p1_turn = false;
    } else {
        p1_turn = true;
    }
}



void solve()
{
    vector<vector<char>> grid(11, vector<char>(11));
    init_grid(grid);
    print_grid(grid);
    cout << '\n';
    int p1_pos = p1;
    int p2_pos = p2;
    while (t--) {
        if (p1_turn) {
            player1(grid, p1_pos);
        } else {
            player2(grid, p2_pos);
        }
        print_grid(grid);
        cout << '\n';
    }
}

int main()
{
    cin >> p1 >> m1 >> p2 >> m2 >> t;
    solve();
    return 0;
}

