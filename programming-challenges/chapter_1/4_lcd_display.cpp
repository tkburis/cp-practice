// Programming Challenges (Skiena & Revilla) - 1.6.4 LCD Display - UVa ID: 706

#include <bits/stdc++.h>
using namespace std;

map<char, vector<bool>> horizontal = {
    {'0', {true, false, true}},
    {'1', {false, false, false}},
    {'2', {true, true, true}},
    {'3', {true, true, true}},
    {'4', {false, true, false}},
    {'5', {true, true, true}},
    {'6', {true, true, true}},
    {'7', {true, false, false}},
    {'8', {true, true, true}},
    {'9', {true, true, true}}
};

map<char, vector<bool>> vertical = {
    {'0', {true, true, true, true}},
    {'1', {false, true, false, true}},
    {'2', {false, true, true, false}},
    {'3', {false, true, false, true}},
    {'4', {true, true, false, true}},
    {'5', {true, false, false, true}},
    {'6', {true, false, true, true}},
    {'7', {false, true, false, true}},
    {'8', {true, true, true, true}},
    {'9', {true, true, false, true}}
};

int main()
{
    // ofstream cout("output.txt");
    int sz;
    string num;
    while (cin >> sz >> num) {
        if (sz == 0 && num == "0") {
            break;
        }
        // horizontal top
        for (int i = 0; i < num.length(); i++) {
            if (horizontal[num[i]][0]) {
                cout << ' ';
                for (int j = 0; j < sz; j++) {
                    cout << '-';
                }
                cout << ' ';
            } else {
                for (int j = 0; j < sz+2; j++) {
                    cout << ' ';
                }
            }
            if (i != num.length() - 1) {
                cout << ' ';
            }
        }
        cout << '\n';
        // vertical top left and top right
        for (int i = 0; i < sz; i++) {
            for (int j = 0; j < num.length(); j++) {
                if (vertical[num[j]][0]) {
                    cout << '|';
                } else {
                    cout << ' ';
                }
                for (int k = 0; k < sz; k++) {
                    cout << ' ';
                }
                if (vertical[num[j]][1]) {
                    cout << '|';
                } else {
                    cout << ' ';
                }
                if (j != num.length() - 1) {
                    cout << ' ';
                }
            }
            cout << '\n';
        }
        // horizontal middle
        for (int i = 0; i < num.length(); i++) {
            if (horizontal[num[i]][1]) {
                cout << ' ';
                for (int j = 0; j < sz; j++) {
                    cout << '-';
                }
                cout << ' ';
            } else {
                for (int j = 0; j < sz+2; j++) {
                    cout << ' ';
                }
            }
            if (i != num.length() - 1) {
                cout << ' ';
            }
        }
        cout << '\n';
        // vertical bottom left and right
        for (int i = 0; i < sz; i++) {
            for (int j = 0; j < num.length(); j++) {
                if (vertical[num[j]][2]) {
                    cout << '|';
                } else {
                    cout << ' ';
                }
                for (int k = 0; k < sz; k++) {
                    cout << ' ';
                }
                if (vertical[num[j]][3]) {
                    cout << '|';
                } else {
                    cout << ' ';
                }
                if (j != num.length() - 1) {
                    cout << ' ';
                }
            }
            cout << '\n';
        }
        // horizontal bottom
        for (int i = 0; i < num.length(); i++) {
            if (horizontal[num[i]][2]) {
                cout << ' ';
                for (int j = 0; j < sz; j++) {
                    cout << '-';
                }
                cout << ' ';
            } else {
                for (int j = 0; j < sz+2; j++) {
                    cout << ' ';
                }
            }
            if (i != num.length() - 1) {
                cout << ' ';
            }
        }
        cout << "\n\n";
    }
    return 0;
}

