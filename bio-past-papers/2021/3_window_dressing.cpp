// https://olympiad.org.uk/papers/2021/bio/bio21-exam.pdf

#include <bits/stdc++.h>
using namespace std;

// Data structure for arrangement of the boxes, dist = min operations from beginning
struct Arrangement
{
    string left;
    string right;
    int dist;
};

pair<string, string> add(string left, string right)
{
    left += right[0];
    right.erase(0, 1);
    return make_pair(left, right);
}

pair<string, string> swap(string left, string right)
{
    swap(left[0], left[1]);
    return make_pair(left, right);
}

pair<string, string> rotate(string left, string right)
{
    string new_left = "";
    for (int i = 1; i < left.length(); i++) {
        new_left += left[i];
    }
    new_left += left[0];
    return make_pair(new_left, right);
}

int solve(string target)
{
    map<string, int> distances;
    string conveyer = "";
    for (int i = 0; i < target.length(); i++) {
        conveyer += 'A' + i;
    }

    queue<Arrangement> q;
    q.push({"", conveyer, 0});

    while (!q.empty()) {
        Arrangement curr = q.front();
        q.pop();
        distances[curr.left] = curr.dist;
        string new_left, new_right;

        if (curr.right.length() > 0) {
            tie(new_left, new_right) = add(curr.left, curr.right);
            if (distances.find(new_left) == distances.end()) {
                distances[new_left] = INT_MAX;
            }
            if (curr.dist + 1 < distances[new_left]) {
                distances[new_left] = curr.dist + 1;
                q.push({new_left, new_right, curr.dist+1});
            }
        }
        if (curr.left.length() > 1) {
            tie(new_left, new_right) = swap(curr.left, curr.right);
            if (distances.find(new_left) == distances.end()) {
                distances[new_left] = INT_MAX;
            }
            if (curr.dist + 1 < distances[new_left]) {
                distances[new_left] = curr.dist + 1;
                q.push({new_left, new_right, curr.dist+1});
            }
            
            tie(new_left, new_right) = rotate(curr.left, curr.right);
            if (distances.find(new_left) == distances.end()) {
                distances[new_left] = INT_MAX;
            }
            if (curr.dist + 1 < distances[new_left]) {
                distances[new_left] = curr.dist + 1;
                q.push({new_left, new_right, curr.dist+1});
            }
        }
    }
    return distances[target];
}

int main()
{
    // Task 1
    string s;
    cin >> s;
    cout << solve(s) << endl;

    // Task 2
    string abcde = "ABCDE";
    do {
        if (solve(abcde) == 6) cout << abcde << ' ';
    } while (next_permutation(abcde.begin(), abcde.end()));
    return 0;
}
