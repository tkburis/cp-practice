// Programming Challenges (Skiena & Revilla) - 1.6.7 Check the Check - UVa ID: 10196

#include <bits/stdc++.h>
using namespace std;

int game = 1;

bool check_target(vector<vector<char>> board, int y, int x, char target)
{
    if (y >= 0 && y < 8 && x >= 0 && x < 8) {
        if (board[y][x] == target) {
            return true;
        }
    }
    return false;
}

bool pawn(vector<vector<char>> board, int y, int x)
{
    if (isupper(board[y][x])) {
        char target = 'k';
        if (check_target(board, y-1, x+1, target) || check_target(board, y-1, x-1, target)) {
            cout << "Game #" << game << ": black king is in check.\n";
            return true;
        }
    } else {
        char target = 'K';
        if (check_target(board, y+1, x+1, target) || check_target(board, y+1, x-1, target)) {
            cout << "Game #" << game << ": white king is in check.\n";
            return true;
        }
    }
    return false;
}

bool rook(vector<vector<char>> board, int y, int x)
{
    char target; string msg;
    if (isupper(board[y][x])) {
        target = 'k';
        msg = "Game #" + to_string(game) + ": black king is in check.\n";
    } else {
        target = 'K';
        msg = "Game #" + to_string(game) + ": white king is in check.\n";
    }
    // up
    for (int dy = y-1; dy >= 0; dy--) {
        if (board[dy][x] == target) {
            cout << msg;
            return true;
        }
        if (board[dy][x] != '.') {
            break;
        }
    }
    // down
    for (int dy = y+1; dy < 8; dy++) {
        if (board[dy][x] == target) {
            cout << msg;
            return true;
        }
        if (board[dy][x] != '.') {
            break;
        }
    }
    // left
    for (int dx = x-1; dx >= 0; dx--) {
        if (board[y][dx] == target) {
            cout << msg;
            return true;
        }
        if (board[y][dx] != '.') {
            break;
        }
    }
    // right
    for (int dx = x+1; dx < 8; dx++) {
        if (board[y][dx] == target) {
            cout << msg;
            return true;
        }
        if (board[y][dx] != '.') {
            break;
        }
    }
    return false;
}

bool bishop(vector<vector<char>> board, int y, int x)
{
    char target; string msg;
    if (isupper(board[y][x])) {
        target = 'k';
        msg = "Game #" + to_string(game) + ": black king is in check.\n";
    } else {
        target = 'K';
        msg = "Game #" + to_string(game) + ": white king is in check.\n";
    }
    // top left
    for (int dy = y-1; dy >= 0; dy--) {
        int dx = x - (y - dy);
        if (dx < 0) {
            break;
        }
        if (board[dy][dx] == target) {
            cout << msg;
            return true;
        }
        if (board[dy][dx] != '.') {
            break;
        }
    }
    // top right
    for (int dy = y-1; dy >= 0; dy--) {
        int dx = x + (y - dy);
        if (dx >= 8) {
            break;
        }
        if (board[dy][dx] == target) {
            cout << msg;
            return true;
        }
        if (board[dy][dx] != '.') {
            break;
        }
    }
    // bottom left
    for (int dy = y+1; dy < 8; dy++) {
        int dx = x - (dy - y);
        if (dx < 0) {
            break;
        }
        if (board[dy][dx] == target) {
            cout << msg;
            return true;
        }
        if (board[dy][dx] != '.') {
            break;
        }
    }
    // bottom right
    for (int dy = y+1; dy < 8; dy++) {
        int dx = x + (dy - y);
        if (dx >= 8) {
            break;
        }
        if (board[dy][dx] == target) {
            cout << msg;
            return true;
        }
        if (board[dy][dx] != '.') {
            break;
        }
    }
    return false;
}

bool queen(vector<vector<char>> board, int y, int x)
{
    if (rook(board, y, x)) return true;
    if (bishop(board, y, x)) return true;
    return false;
}

bool knight(vector<vector<char>> board, int y, int x)
{
    char target; string msg;
    if (isupper(board[y][x])) {
        target = 'k';
        msg = "Game #" + to_string(game) + ": black king is in check.\n";
    } else {
        target = 'K';
        msg = "Game #" + to_string(game) + ": white king is in check.\n";
    }
    vector<int> diffs = {-2, -1, 1, 2};
    vector<pair<int, int>> to_check;
    for (int diff1 : diffs) {
        int diff2 = 3 - abs(diff1);
        to_check.push_back({diff1, diff2});
        to_check.push_back({diff1, -diff2});
    }
    for (auto check : to_check) {
        int dy = y+check.first, dx = x+check.second;
        if (check_target(board, dy, dx, target)) {
            cout << msg;
            return true;
        }
    }
    return false;
}

void print(vector<vector<char>> board)
{
    for (auto row : board) {
        for (auto c : row) {
            cout << c;
        }
        cout << '\n';
    }
}

void solve(vector<vector<char>> board)
{
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            switch (tolower(board[i][j])) {
                case 'p':
                    if (pawn(board, i, j)) return;
                    break;
                case 'r':
                    if (rook(board, i, j)) return;
                    break;
                case 'b':
                    if (bishop(board, i, j)) return;
                    break;
                case 'q':
                    if (queen(board, i, j)) return;
                    break;
                case 'n':
                    if (knight(board, i, j)) return;
                    break;
                default:
                    continue;
            }
        }
    }
    cout << "Game #" << game << ": no king is in check.\n";
    return;
}

int main()
{
    while (true) {
        vector<vector<char>> input_board(8, vector<char>(8));
        bool empty = true;
        for (int i = 0; i < 8; i++) {
            for (int j = 0; j < 8; j++) {
                char c;
                cin >> c;
                input_board[i][j] = c;
                if (c != '.') {
                    empty = false;
                }
            }
        }
        cin.ignore();
        if (!empty) {
            solve(input_board);
        } else {
            break;
        }
        game++;
    }
    return 0;
}

