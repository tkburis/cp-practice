// https://olympiad.org.uk/papers/2020/bio/bio20-exam.pdf

#include <bits/stdc++.h>
using namespace std;

class Room
{
    public:
        char name;
        vector<pair<char, int>> exits;
        int vis;
        Room(char name1, vector<pair<char, int>> exits1);
        char choose_exit();
};

Room::Room(char name1, vector<pair<char, int>> exits1)
{
    name = name1;
    exits = exits1;
    vis = 0;
}

char Room::choose_exit()
{
    if (vis % 2 == 1) {
        exits[0].second++;
        return exits[0].first;
    }
    int num_exits = exits.size();
    for (int i = 0; i < num_exits; i++) {
        if (exits[i].second % 2 == 1) {
            if (i == num_exits - 1) {
                exits[i].second++;
                return exits[i].first;
            }
            exits[i+1].second++;
            return exits[i+1].first;
        }
    }
}

map<char, vector<char>> parse_plan(string plan)
{
    int n = plan.length();
    map<char, vector<char>> adj;
    string alpha = "";
    for (int i = 0; i < n+2; i++) {
        alpha += 'A' + i;
    }
    while (plan.length() > 0) {
        for (int j = 0; j < n+2; j++) {
            if (find(plan.begin(), plan.end(), alpha[j]) == plan.end()) {
                adj[alpha[j]].push_back(plan[0]);
                adj[plan[0]].push_back(alpha[j]);
                plan.erase(0, 1);
                alpha.erase(j, 1);
                break;
            }
        }
    }
    adj[alpha[0]].push_back(alpha[1]);
    adj[alpha[1]].push_back(alpha[0]);
    for (auto& p : adj) {
        sort(p.second.begin(), p.second.end());
    }
    return adj;
}

void print_all(vector<Room> rooms)
{
    for (auto room : rooms) {
        cout << "Room " << room.name << ' ' << room.vis << endl;
        cout << "Exits: " << endl;
        for (auto exit : room.exits) {
            cout << exit.first << ' ' << exit.second << endl;
        }
        cout << endl;
    }
}

void solve(string plan, int p, int q)
{
    int n = plan.length();
    map<char, vector<char>> adj = parse_plan(plan);
    vector<Room> rooms;
    for (auto p : adj) {
        vector<pair<char, int>> exits;
        for (char exit : p.second) {
            cout << exit;
            pair<char, int> temp_exit(exit, 0);
            exits.push_back(temp_exit);
        }
        cout << endl;
        Room temp(p.first, exits);
        rooms.push_back(temp);
    }
    Room curr_room = rooms[0];
    for (int i = 0; i < max(p, q); i++) {
        curr_room.vis++;
        char chosen_exit = curr_room.choose_exit();
        rooms[curr_room.name - 'A'] = curr_room;
        for (Room room : rooms) {
            if (room.name == chosen_exit) {
                curr_room = room;
            }
        }
        if (i == p-1 || i == q-1) {
            cout << curr_room.name;
        }
    }
}

int main()
{
    string plan;
    int p, q;
    cin >> plan >> p >> q;
    solve(plan, p, q);
    return 0;
}
