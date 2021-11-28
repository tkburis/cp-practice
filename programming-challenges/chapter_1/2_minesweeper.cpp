// Programming Challenges (Skiena & Revilla) - 1.6.2 Minesweeper - UVa ID: 10189

#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int tt = 1;
    int n, m;
    while (cin >> n >> m, n > 0 && m > 0) {
        if (tt > 1) {
            cout << endl;
        }

        vector<vector<char> > board(n + 2, vector<char>(m + 2, '.'));
        for (int r = 1; r <= n; r++) {
            for (int c = 1; c <= m; c++) {
                cin >> board[r][c];
            }
        }

        cout << "Field #" << tt << ":" << endl;
        for (int r = 1; r <= n; r++) {
            for (int c = 1; c <= m; c++) {
                if (board[r][c] == '*') {
                    cout << '*';
                } else {
                    int mines = 0;
                    for (int i = r - 1; i <= r + 1; i++) {
                        for (int j = c - 1; j <= c + 1; j++) {
                            if (board[i][j] == '*') {
                                mines++;
                            }
                        }
                    }
                    cout << mines;
                }
            }
            cout << endl;
        }
        tt++;
    }
    return 0;
}
