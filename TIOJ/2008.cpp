#include <bits/stdc++.h>
using namespace std;

const int maxn = 15e5 + 10;
int a[maxn], d[maxn], w[maxn];

inline bool win(int i, int j) {
    return a[i] >= a[j] && d[i] > d[j] || a[i] > a[j] && d[i] >= d[j];
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i] >> d[i];
    stack<int> st;
    for (int i = 1; i <= n; ++i) {
        if (st.size() && win(st.top(), i)) continue;
        while (st.size()) {
            if (!win(st.top(), i)) w[st.top()] += i - st.top() - 1, st.pop();
            else break;
        }
        st.push(i);
    }
    if (st.size()) w[st.top()] += n - st.top();
    while (st.size()) st.pop();
    for (int i = n; i > 0; --i) {
        if (st.size() && win(st.top(), i)) continue;
        while (st.size()) {
            if (!win(st.top(), i)) w[st.top()] += st.top() - i - 1, st.pop();
            else break;
        }
        st.push(i);
    }
    if (st.size()) w[st.top()] += st.top() - 1;
    int ans = 0;
    for (int i = 1; i <= n; ++i) ans = max(ans, w[i]);
    cout << ans << endl;
    return 0;
}
