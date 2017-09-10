#include <bits/stdc++.h>
#define getchar gtx
#define ing long long
using namespace std;

inline int gtx() {
    const int N = 1048576;
    static char buffer[N];
    static char *p = buffer, *end = buffer;
    if (p == end) {
        if ((end = buffer + fread(buffer, 1, N, stdin)) == buffer) return EOF;
        p = buffer;
    }
    return *p++;
}

template <typename T>
inline bool rit(T& x) {
    char __c = 0; bool flag = false;
    while (__c = getchar(), (__c < '0' && __c != '-') || __c > '9') if (__c == -1) return false;
    __c == '-' ? (flag = true, x = 0) : (x = __c - '0');
    while (__c = getchar(), __c >= '0' && __c <= '9') x = x * 10 + __c - '0';
    if (flag) x = -x;
    return true;
}

template <typename T, typename ...Args>
inline bool rit(T& x, Args& ...args) { return rit(x) && rit(args...); }

const int maxn = 1e5 + 10, lg = 20;
vector<pair<int, int>> G[maxn];
vector<int> vtx;
bool v[maxn], has[maxn];
int sz[maxn], mx[maxn], dis[lg][maxn], dep[maxn], p[maxn], ans[maxn], cnt[maxn], mi[maxn];

void get_center(int now) {
    // cout << "get_center now = " << now << endl;
    v[now] = true; vtx.push_back(now);
    sz[now] = 1; mx[now] = 0;
    for (auto u : G[now]) if (!v[u.first]) {
        get_center(u.first);
        mx[now] = max(mx[now], sz[u.first]);
        sz[now] += sz[u.first];
    }
}

void get_dis(int now, int d, int len) {
    dis[d][now] = len;
    v[now] = true;
    for (auto u : G[now]) if (!v[u.first]) {
        get_dis(u.first, d, len + u.second);
    }
}

void dfs(int now, int fa, int d) {
    // cout << "dfs now = " << now << endl;
    get_center(now);
    int c = -1;
    for (int u : vtx) {
        if (max(mx[u], (int)vtx.size() - sz[u]) <= (int)vtx.size() / 2) c = u;
        v[u] = false;
    }
    get_dis(c, d, 0);
    for (int u : vtx) v[u] = false;
    v[c] = true; vtx.clear();
    dep[c] = d; p[c] = fa;
    // cout << "center = " << c << endl;
    for (auto u : G[c]) if (!v[u.first]) dfs(u.first, c, d + 1);
}

void modify(int now) {
    has[now] = true;
    int cur = now;
    for (; cur != -1; ) {
        // cout << "cur = " << cur << endl;
        ans[cur] += dis[dep[cur]][now]; mi[cur] += dis[dep[cur] - 1][now];
        ++cnt[cur];
        cur = p[cur];
    }
}

int query(int now) {
    int ret = 0;
    int cur = now;
    int abc = 0;
    for (; cur != -1; ) {
        ret += ans[cur] - mi[cur];
        ret += (cnt[cur] - abc) * dis[dep[cur]][now];
        abc = cnt[cur];
        cur = p[cur];
    }
    return ret;
}

int32_t main() {
    // ios_base::sync_with_stdio(false); cin.tie(0);
    int n, q; rit(n, q);
    for (int i = 0; i < n - 1; ++i) {
        int a, b, c; rit(a, b, c);
        G[a].emplace_back(b, c);
        G[b].emplace_back(a, c);
    }
    dfs(0, -1, 1);
    while (q--) {
        int t, x; rit(t, x);
        if (t == 1 && !has[x]) modify(x);
        else if (t == 2) printf("%lld\n", query(x));
        // for (int i = 0; i < n; ++i) cout << ans[i] << ' ' << cnt[i] << endl;
    }
    return 0;
}
