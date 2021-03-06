#include <bits/stdc++.h>
using namespace std;

const int maxn = 100 + 10, inf = 1e9 + 1;

template <typename T> class Hungarian {
    private:
        T w[maxn][maxn], lx[maxn], ly[maxn];
        int match[maxn], n;
        bool s[maxn], t[maxn];
        bool dfs(int now) {
            s[now] = true;
            for (int i = 0; i < n; ++i) {
                if (lx[now] + ly[i] == w[now][i] && !t[i]) {
                    t[i] = true;
                    if (match[i] == -1 || dfs(match[i])) {
                        match[i] = now;
                        return true;
                    }
                }
            }
            return false;
        }
        void relabel() {
            T a = inf;
            for (int i = 0; i < n; ++i) if (s[i]) {
                for (int j = 0; j < n; ++j) if (!t[j]) {
                    a = min(a, lx[i] + ly[j] - w[i][j]);
                }
            }
            for (int i = 0; i < n; ++i) {
                if (s[i]) lx[i] -= a;
                if (t[i]) ly[i] += a;
            }
        }
    public:
        Hungarian(int n): n(n) {
            memset(w, 0, sizeof(w));
            memset(lx, 0, sizeof(lx));
            memset(ly, 0, sizeof(ly));
            memset(match, -1, sizeof(match));
        }
        void add_edge(int a, int b, T c) {
            w[a][b] = c;
        }
        T solve() {
            for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) lx[i] = max(lx[i], w[i][j]);
            for (int i = 0; i < n; ++i) {
                while (true) {
                    memset(s, false, sizeof(s)); memset(t, false, sizeof(t));
                    if (dfs(i)) break;
                    else relabel();
                }
            }
            T ans = 0;
            for (int i = 0; i < n; ++i) ans += w[match[i]][i];
            return ans;
        }
};

int a[maxn];
bool p[32000];
vector<int> prime;

void sieve() {
    for (int i = 2; i < 32000; ++i) {
        if (!p[i]) prime.push_back(i);
        for (int j = 0; i * prime[j] < 32000; ++j) {
            p[i * prime[j]] = true;
            if (i % prime[j] == 0) break; 
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, m; cin >> n >> m;
    sieve();
    Hungarian<int> h(n + 5);
    for (int i = 1; i <= n; ++i) cin >> a[i];
    while (m--) {
        int u, v; cin >> u >> v;
        int g = __gcd(a[u], a[v]);
        int cnt = 0;
        for (int i : prime) {
            while (g % i == 0) ++cnt, g /= i;
        }
        if (u & 1) h.add_edge(u, v, cnt);
        else h.add_edge(v, u, cnt);
        // h.add_edge(u, v, cnt); h.add_edge(v, u, cnt);
    }
    cout << h.solve() << endl;
    return 0;
}
