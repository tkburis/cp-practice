// Programming Challenges (Skiena & Revilla) - 1.6.6 Interpreter - UVa ID: 10033

#include <bits/stdc++.h>
using namespace std;

int main()
{
    ifstream cin("input.txt");
    int t;
    cin >> t;
    //getchar(); getchar();
    string p;
    getline(cin, p);
    getline(cin, p);
    while (t--) {
        vector<int> registers(10, 0);
        vector<string> ram(1000, "");
        string in;
        int i = 0;
        while (getline(cin, in)) {
            if (in.length() == 0) break;
            ram[i] = in;
            i++;
        }
        int cnt = 0, cii = 0;  // current instruction index
        while (true) {
            string ci = ram[cii];  // current instruction
            cii++; cnt++;
            if (ci == "100") {
                break;
            } else if (ci[0] == '2') {
                registers[ci[1]-'0'] = ci[2]-'0';
            } else if (ci[0] == '3') {
                registers[ci[1]-'0'] = (registers[ci[1]-'0'] + (ci[2]-'0')) % 1000;
            } else if (ci[0] == '4') {
                registers[ci[1]-'0'] = (registers[ci[1]-'0'] * (ci[2]-'0')) % 1000;
            } else if (ci[0] == '5') {
                registers[ci[1]-'0'] = registers[ci[2]-'0'];
            } else if (ci[0] == '6') {
                registers[ci[1]-'0'] = (registers[ci[1]-'0'] + registers[ci[2]-'0']) % 1000;
            } else if (ci[0] == '7') {
                registers[ci[1]-'0'] = (registers[ci[1]-'0'] * registers[ci[2]-'0']) % 1000;
            } else if (ci[0] == '8') {
                registers[ci[1]-'0'] = stoi(ram[registers[ci[2]-'0']]);
            } else if (ci[0] == '9') {
                string old_s = to_string(registers[ci[1]-'0']);
                string new_s = string(3 - min(3, (int)old_s.length()), '0') + old_s;
                ram[registers[ci[2]-'0']] = new_s;
            }
            if (ci[0] == '0') {
                if (registers[ci[2]-'0'] != 0) {
                    cii = registers[ci[1]-'0'];
                }
            }
        }
        cout << cnt << '\n';
        if (t != 0) {
            cout << '\n';
        }
    }
    return 0;
}

