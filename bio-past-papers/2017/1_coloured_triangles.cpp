// https://olympiad.org.uk/papers/2017/bio/bio17-exam.pdf

#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cin >> s;
    vector<char> row(s.begin(), s.end());
    while (row.size() > 1) {
        vector<char> new_row(row.size()-1);
        for (int i = 0; i < row.size() - 1; i++) {
            if (row[i] == row[i+1]) {
                new_row[i] = row[i];
            } else {
                new_row[i] = 'R' + 'G' + 'B' - row[i] - row[i+1];
            }
        }
        row = new_row;
    }
    cout << row[0] << '\n';
    return 0;
}

