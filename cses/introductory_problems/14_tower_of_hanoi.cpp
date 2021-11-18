// https://cses.fi/problemset/task/2165

#include <bits/stdc++.h>
using namespace std;

vector< pair<int, int> > hanoi(int n, int from, int to, int use)
{
    if (n == 1) {
        return {make_pair(from, to)};
    }
    vector< pair<int, int> > moves;
    vector< pair<int, int> > temp = hanoi(n-1, from, use, to);
    moves.insert(moves.end(), temp.begin(), temp.end());
    moves.push_back(make_pair(from, to));
    temp = hanoi(n-1, use, to, from);
    moves.insert(moves.end(), temp.begin(), temp.end());
    return moves;
}

int main()
{
    int n;
    cin >> n;
    vector< pair<int, int> > moves = hanoi(n, 1, 3, 2);
    cout << moves.size() << endl;
    for (auto p : moves) {
        cout << p.first << ' ' << p.second << endl;
    }
    return 0;
}
