#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> line(n);
    for (int i = 0; i < n; i++) cin >> line[i];
    
    vector<int> dies(n);
    dies[0] = -1;

    stack<int> st;
    st.push(0);

    for (int i = 1; i < n; i++) {
        dies[i] = 1;
        while (!st.empty()) {
            if (line[st.top()] < line[i]) {
                if (dies[i] != -1) dies[i] = max(dies[i], dies[st.top()]+1);
                if (dies[st.top()] == -1) dies[i] = -1;
                st.pop();
            } else {
                break;
            }
        }
        st.push(i);
    }

    int ans = 0;
    for (int i = 0; i < n; i++) {
        ans = max(ans, dies[i]);
    }
    cout << ans << '\n';

    return 0;
}
