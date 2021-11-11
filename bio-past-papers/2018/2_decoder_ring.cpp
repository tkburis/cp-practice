// https://www.olympiad.org.uk/papers/2018/bio/bio18-exam.pdf

#include <bits/stdc++.h>
using namespace std;

int n;
string w;
string second_dial = "";
string encrypted = "";

void rotate()
{
    second_dial += second_dial[0];
    second_dial.erase(0, 1);
}

void make_dial()
{
    string circle = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    int i = 0;
    while (circle.length() > 0) {
        i += n-1;
        i %= circle.length();
        second_dial += circle[i];
        circle.erase(i, 1);
    }
}

void encrypt()
{
    for (char c : w) {
        int i = c - 'A';
        encrypted += second_dial[i];
        rotate();
    }
}

int main()
{
    cin >> n >> w;
    make_dial();
    cout << second_dial.substr(0, 6) << endl;
    encrypt();
    cout << encrypted;
    return 0;
}
