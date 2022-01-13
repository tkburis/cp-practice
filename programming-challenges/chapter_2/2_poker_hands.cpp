// Programming Challenges (Skiena & Revilla) - 2.8.2 Poker Hands - UVa ID: 10315

#include <bits/stdc++.h>
using namespace std;

string vals = "23456789TJQKA";
string suits = "CDHS";

int encode(string card)
{
    char val = card[0], suit = card[1];
    int val_idx = find(vals.begin(), vals.end(), val) - vals.begin();
    int suit_idx = find(suits.begin(), suits.end(), suit) - suits.begin();
    int code = val_idx + suit_idx * 13;
    return code;
}

int get_val(int c)
{
    return c % 13;
}

int get_suit(int c)
{
    return c / 13;
}

bool same_val(int c1, int c2)
{
    return c1 % 13 == c2 % 13;
}

bool same_suit(int c1, int c2)
{
    return c1 / 13 == c2 / 13;
}

pair<int, int> score(vector<int> cards)
{
    // straight flush
    bool ok = true;
    for (int i = 1; i < 5; i++) {
        if (!same_suit(cards[i-1], cards[i])) ok = false;
    }
    if (ok) {
        vector<int> vals;
        for (int i = 0; i < 5; i++) {
            vals.push_back(get_val(cards[i]));
        }
        sort(vals.begin(), vals.end());
        ok = true;
        for (int i = 1; i < 5; i++) {
            if (vals[i] - vals[i-1] != 1) ok = false;
        }
        if (ok) return {9, vals[4]};
    }

    // four of a kind
    ok = true;
    for (int i = 1; i < 5; i++) {
        if (get_val(cards[i-1]) != get_val(cards[i]))
    }


    return {-1, -1};
}

int main()
{
    freopen("input.txt", "r", stdin);
    string in;
    while (getline(cin, in)) {
        stringstream ss(in);
        vector<int> black(5), white(5);
        for (int i = 0; i < 5; i++) {
            string t;
            ss >> t;
            black[i] = encode(t);
        }
        for (int i = 0; i < 5; i++) {
            string t;
            ss >> t;
            white[i] = encode(t);
        }
        cout << "BLACK: ";
        for (int b : black) cout << b << ' ';
        cout << "\nWHITE: ";
        for (int w : white) cout << w << ' ';
        cout << '\n';
        pair<int, int> b_score = score(black);
        pair<int, int> w_score = score(white);
        cout << b_score.first << ' ' << b_score.second << '\n';
        cout << w_score.first << ' ' << w_score.second << '\n';
    }
    return 0;
}

