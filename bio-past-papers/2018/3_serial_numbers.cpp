// https://www.olympiad.org.uk/papers/2018/bio/bio18-exam.pdf

#include <bits/stdc++.h>
using namespace std;

int d;
vector<int> src;

vector<pair<int, int>> swaps(vector<int> num) {
    vector<pair<int, int>> res;
    for (int i = 0; i < d-1; i++) {
        int low = min(num[i], num[i+1]);
        int high = max(num[i], num[i+1]);
        if (0 < i && i < d-2) {
            if ((low < num[i-1] && num[i-1] < high) || (low < num[i+2] && num[i+2] < high)) {
                res.push_back(make_pair(i, i+1));
            }
        } else if (i == 0) {
            if ((low < num[i+2]) && (num[i+2] < high)) {
                res.push_back(make_pair(i, i+1));
            }
        } else if (i == d-2) {
            if ((low < num[i-1]) && (num[i-1] < high)) {
                res.push_back(make_pair(i, i+1));
            }
        }
    }
    return res;
}

// Doesn't make the last testcase by a second
void solve()
{
    map<vector<int>, int> distances;
    set<vector<int>> visited;
    queue<vector<int>> q;
    q.push(src);
    while (!q.empty()) {
        vector<int> curr_node = q.front();
        int curr_distance = distances[curr_node];
        q.pop();
        visited.insert(curr_node);
        for (auto poss_swap : swaps(curr_node)) {
            vector<int> working_copy(curr_node.begin(), curr_node.end());
            swap(working_copy[poss_swap.first], working_copy[poss_swap.second]);
            if (find(visited.begin(), visited.end(), working_copy) == visited.end()) {
                q.push(working_copy);
                distances[working_copy] = max(distances[working_copy], curr_distance + 1);
            }
        }
    }
    int maxi = 0;
    for (auto p : distances) {
        maxi = max(maxi, p.second);
    }
    cout << maxi << endl;
}

int main()
{
    int n;
    cin >> d >> n;
    while (n > 0) {
        src.push_back(n % 10);
        n /= 10;
    }
    reverse(src.begin(), src.end());
    solve();
    return 0;
}
