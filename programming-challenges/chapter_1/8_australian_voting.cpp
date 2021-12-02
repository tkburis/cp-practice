// Programming Challenges (Skiena & Revilla) - 1.6.8 Australian Voting - UVa ID: 10142

#include <bits/stdc++.h>
using namespace std;

void solve(vector<pair<string, bool>> names, vector<vector<int>> votes, bool last)
{
    map<string, int> current_votes;
    for (auto p : names) {
        if (p.second) current_votes[p.first] = 0;
    }
    for (auto row : votes) {
        for (int i = 0; i < row.size(); i++) {
            if (names[row[i]-1].second) {  // still in
                current_votes[names[row[i]-1].first]++;
                break;
            }
        }
    }
    bool all_same = true;
    int maxi = -1, least = INT_MAX, sum = 0, prev = -1;
    string best;
    for (auto p : current_votes) {
        if (prev == -1) {
            prev = p.second;
        } else {
            if (p.second != prev) {
                all_same = false;
            }
            prev = p.second;
        }
        if (p.second > maxi) {
            maxi = p.second;
            best = p.first;
        }
        least = min(least, p.second);
        sum += p.second;
    }
    if (maxi > sum/2) {
        cout << best << '\n';
        if (!last) cout << '\n';
        return;
    }
    if (all_same) {
        for (auto name : current_votes) {
            cout << name.first << '\n';
        }
        if (!last) cout << '\n';
        return;
    }
    for (auto p : current_votes) {
        if (p.second == least) {
            for (auto& q : names) {
                if (p.first == q.first) {
                    q.second = false;
                }
            }
        }
    }
    /* for (int i = 0; i < names.size(); i++) { */
    /*     cout << names[i].first << ' ' << names[i].second << '\n'; */
    /* } */
    solve(names, votes, last);
    return;
}

int main()
{
    freopen("input.txt", "r", stdin);
    int t;
    scanf("%d ", &t);
    while (t--) {
        int n;
        scanf("%d ", &n);
        vector<pair<string, bool>> names;
        while (n--) {
            string name;
            getline(cin, name);
            names.push_back({name, true});
        }
        vector<vector<int>> votes;
        string ln;
        while (getline(cin, ln), ln.length() > 0) {
            vector<int> row;
            stringstream ss(ln);
            int n;
            while (ss >> n) {
                row.push_back(n);
            }
            votes.push_back(row);
        }
        if (t > 0) solve(names, votes, false);
        else solve(names, votes, true);
    }
    return 0;
}

