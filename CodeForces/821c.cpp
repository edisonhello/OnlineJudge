#include <bits/stdc++.h>
using namespace std;

const int maxn = 3e5 + 10;
bool v[maxn], sor;

int main() {
    stack<int> s; set<int> st; int n; cin >> n;
    int ans = 0, cur = 1;
    for (int i = 0; i < 2 * n; ++i) {
        // cout << i << endl;
        string cmd; cin >> cmd;
        if (cmd == "add") {
            int x; cin >> x;
            s.push(x); st.insert(x);
            sor = false;
        } else {
            while (s.size() && s.top() >= 1 && s.top() <= n && v[s.top()]) s.pop();
            while (s.size() && s.top() == -1) sor = true, s.pop();
            // if (s.size() == 0) continue;
            if (s.top() == cur) {
                // cout << "jizz" << endl;
                st.erase(s.top());
                v[s.top()] = true;
                s.pop(); ++cur;
            } else {
                // cout << "asd" << endl;
                if (sor) {
                    v[cur] = true;
                    st.erase(cur); ++cur;
                } else {
                    ++ans; st.erase(cur); v[cur] = true;
                    s.push(-1); ++cur;
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}
