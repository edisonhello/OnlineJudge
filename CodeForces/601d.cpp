#include <bits/stdc++.h>
using namespace std;

const int maxn = 3e5 + 10, mod = 715827883, p = 457;
vector<int> G[maxn];
long long c[maxn], cnt, ans;
char ch[maxn];

inline int add(int a, int b) { return a + b >= mod ? a + b - mod : a + b; }
inline int mul(int a, int b) { return a * 1ll * b % mod; }

set<int> *dfs(int now, int fa) {
    set<int> *ret = new set<int>();
    // cout << "now = " << now << endl;
    for (int u : G[now]) if (u != fa) {
        // cout << "u = " << u << endl;
        set<int> *res = dfs(u, now);
        // cout << "u = " << u << " size = " << res->size() << endl;
        // if (res->size() > ret->size() && ret->size() > 0) swap(res, ret);
        for (auto it = res->begin(); it != res->end(); ++it) ret->insert(add(mul(*it, p), ch[now]));
    }
    ret->insert(ch[now]);
    // cout << "now = " << now << " size = " << ret->size() << endl;
    if ((long long)ret->size() + c[now] > ans) ans = (long long)ret->size() + c[now], cnt = 1;
    else if ((long long)ret->size() + c[now] == ans) ++cnt;
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    for (int i = 1; i <= n; ++i) cin >> c[i];
    string s; cin >> s;
    for (int i = 1; i <= n; ++i) ch[i] = s[i - 1];
    for (int i = 0; i < n - 1; ++i) {
        int a, b; cin >> a >> b;
        G[a].push_back(b); G[b].push_back(a);
    }
    dfs(1, 0);
    cout << ans << '\n' << cnt << endl;
    return 0;
}

