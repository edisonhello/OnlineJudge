#include <bits/stdc++.h>
#define bit(x, dep) ((x >> dep) & 1)
using namespace std;

const int maxn = 100000 + 5;

struct Trie {
    Trie *ch[2];
    Trie() {
        ch[0] = ch[1] = nullptr;
    }
    Trie(Trie* t) {
        if (!t) {
            ch[0] = ch[1] = nullptr;
            return;
        }
        ch[0] = t->ch[0];
        ch[1] = t->ch[1];
    }
    int query(int x, int dep) {
        if (dep < 0) return 0;
        if (ch[!bit(x, dep)]) return (1 << dep) + ch[!bit(x, dep)]->query(x, dep - 1);
        if (ch[bit(x, dep)]) return ch[bit(x, dep)]->query(x, dep - 1);
        return 0;
    }
} *trie[maxn], mem[4000000], *top;

Trie* modify(Trie*, int, int);
void dfs(int, int, int, int);

int a[maxn], ans[maxn];
vector<int> G[maxn];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t; cin >> t; while (t--) {
        int n; cin >> n; for (int i = 1; i <= n; ++i) cin >> a[i];
        fill(G, G + maxn, vector<int>());
        for (int i = 0; i < n - 1; ++i) {
            int a, b; cin >> a >> b;
            G[a].push_back(b);
            G[b].push_back(a);
        }
        top = mem;
        trie[0] = new(top++) Trie(); trie[0] = modify(trie[0], 0, 30);
        dfs(1, 0, 0, 0);
        for (int i = 1; i <= n; ++i) cout << ans[i] << '\n';
    }
    return 0;
}

Trie* modify(Trie* t, int x, int dep) {
    if (dep < -1) return nullptr;
    Trie *ret = new(top++) Trie(t);
    ret->ch[bit(x, dep)] = modify(ret->ch[bit(x, dep)], x, dep - 1);
    return ret;
}

void dfs(int x, int fa, int Xor, int mx) {
    ans[x] = max(mx, trie[fa]->query(Xor ^ a[x], 30));
    trie[x] = modify(trie[fa], Xor ^ a[x], 30);
    for (int u : G[x]) if (u != fa) {
        dfs(u, x, Xor ^ a[x], ans[x]);
    }
}

