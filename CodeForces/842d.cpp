#include <bits/stdc++.h>
using namespace std;

const int maxn = 3e5 + 10, lg = 25;
bool chg[lg + 5];

struct Trie {
    Trie *ch[2];
    int cnt;
    Trie(): cnt(0) {
        ch[0] = ch[1] = nullptr;
    }
    void insert(int x, int dep) {
        if (dep < 0) return;
        int bit = ((1 << dep) & x) >> dep;
        if (!ch[bit]) ch[bit] = new Trie();
        ++ch[bit]->cnt;
        ch[bit]->insert(x, dep - 1);
    }
    int query(int dep) {
        if (dep < 0) return 0;
        int bit = (int)chg[dep];
        if (ch[bit] && ch[bit]->cnt == (1 << dep)) {
            int ret = (1 << dep);
            if (ch[bit ^ 1]) ret += ch[bit ^ 1]->query(dep - 1);
            return ret;
        } else {
            if (!ch[bit]) return 0;
            return ch[bit]->query(dep - 1);
        }
    } 
} *tr;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, m; cin >> n >> m;
    tr = new Trie();
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    sort(a.begin(), a.end()); a.resize(unique(a.begin(), a.end()) - a.begin());
    for (int i : a) tr->insert(i, lg);
    while (m--) {
        int x; cin >> x;
        for (int i = 0; i < lg; ++i) {
            if ((1 << i) & x) chg[i] = !chg[i];
        }
        cout << tr->query(lg) << endl;
    }
    return 0;
}
