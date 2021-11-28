// Programming Challenges (Skiena & Revilla) - 1.6.5 Graphical Editor - UVa ID: 10267

#include <bits/stdc++.h>
using namespace std;

int height = 0, width = 0;

void fill(vector<vector<char>>& table, int x, int y, char c)
{
    if (table[y][x] == c) {
        return;
    }
    char old_c = table[y][x];
    table[y][x] = c;
    if (x - 1 >= 1) {
        if (table[y][x-1] == old_c) {
            fill(table, x-1, y, c);
        }
    }
    if (x + 1 <= width) {
        if (table[y][x+1] == old_c) {
            fill(table, x+1, y, c);
        }
    }
    if (y - 1 >= 1) {
        if (table[y-1][x] == old_c) {
            fill(table, x, y-1, c);
        }
    }
    if (y + 1 <= height) {
        if (table[y+1][x] == old_c) {
            fill(table, x, y+1, c);
        }
    }
    return;
}

int main()
{
    vector<vector<char>> table(300, vector<char>(300, 'O'));
    char cmd;
    while (cin >> cmd) {
        if (cmd == 'X') {
            break;
        }
        if (cmd == 'I') {
            cin >> width >> height;
            for (int i = 1; i <= height; i++) {
                for (int j = 1; j <= width; j++) {
                    table[i][j] = 'O';
                }
            }
        } else if (cmd == 'C') {
            for (int i = 1; i <= height; i++) {
                for (int j = 1; j <= width; j++) {
                    table[i][j] = 'O';
                }
            }
        } else if (cmd == 'L') {
            int x, y;
            char c;
            cin >> x >> y >> c;
            table[y][x] = c;
        } else if (cmd == 'V') {
            int x, y1, y2;
            char c;
            cin >> x >> y1 >> y2 >> c;
            for (int i = min(y1, y2); i <= max(y1, y2); i++) {
                table[i][x] = c;
            }
        } else if (cmd == 'H') {
            int x1, x2, y;
            char c;
            cin >> x1 >> x2 >> y >> c;
            for (int i = min(x1, x2); i <= max(x1, x2); i++) {
                table[y][i] = c;
            }
        } else if (cmd == 'K') {
            int x1, y1, x2, y2;
            char c;
            cin >> x1 >> y1 >> x2 >> y2 >> c;
            for (int i = min(y1, y2); i <= max(y1, y2); i++) {
                for (int j = min(x1, x2); j <= max(x1, x2); j++) {
                    table[i][j] = c;
                }
            }
        } else if (cmd == 'F') {
            int x, y;
            char c;
            cin >> x >> y >> c;
            fill(table, x, y, c);
        } else if (cmd == 'S') {
            string name;
            cin >> name;
            cout << name << '\n';
            for (int i = 1; i <= height; i++) {
                for (int j = 1; j <= width; j++) {
                    cout << table[i][j];
                }
                cout << '\n';
            }
        }
    }
    return 0;
}

