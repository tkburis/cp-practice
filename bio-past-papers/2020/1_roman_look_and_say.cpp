// https://olympiad.org.uk/papers/2020/bio/bio20-exam.pdf

#include <bits/stdc++.h>
using namespace std;

vector< pair<string, int> > numerals = {
    {"M", 1000},
    {"CM", 900},
    {"D", 500},
    {"CD", 400},
    {"C", 100},
    {"XC", 90},
    {"L", 50},
    {"XL", 40},
    {"X", 10},
    {"IX", 9},
    {"V", 5},
    {"IV", 4},
    {"I", 1}
};

string to_roman(int n)
{
    string s = "";
    while (n > 0) {
        for (auto p : numerals) {
            if (p.second <= n) {
                s += p.first;
                n -= p.second;
                break;
            }
        }
    }
    return s;
}

string solve(string s, int n, bool out)
{
    while (n--) {
        string new_string = "";
        int curr_count = 0;
        char prev = s[0];
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == prev) {
                curr_count++;
            } else {
                new_string += to_roman(curr_count) + prev;
                curr_count = 1;
            }
            prev = s[i];
        }
        new_string += to_roman(curr_count) + prev;
        s = new_string;
    }
    if (out)
    {
        cout << count(s.begin(), s.end(), 'I') << ' ' << count(s.begin(), s.end(), 'V') << endl;
    }
    return s;
}

int main()
{
    // Task 1
    string s;
    int n;
    cin >> s >> n;
    solve(s, n, true);

    // Task 2
    set<string> distincts;
    for (int i = 1; i <= 3999; i++) {
        distincts.insert(solve(to_roman(i), 1, false));
    }
    cout << distincts.size();

    return 0;
}
