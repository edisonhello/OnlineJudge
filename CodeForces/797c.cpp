#include <bits/stdc++.h>
using namespace std;

const int sigma = 26, maxn = 100000 + 5;
int v[maxn];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    string s; cin >> s;
    v[s.length() - 1] = (int)s[s.length() - 1];
    for (int i = s.length() - 2; i >= 0; --i) v[i] = min(v[i + 1], (int)s[i]);
    stack<int> st;
    string ans = "";
    for (int i = 0; i < s.length(); ++i) {
        st.push(s[i]);
        while (st.size() && st.top() <= v[i]) ans += (char)st.top(), st.pop();
    }
    while (st.size()) ans += (char)st.top(), st.pop();
    cout << ans << '\n';
    return 0;
}
