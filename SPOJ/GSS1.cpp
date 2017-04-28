#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 10;

struct Query {
    int L, R, block, id;
    bool operator<(const Query& rhs) const {
        return block == rhs.block ? R < rhs.R : block < rhs.block;
    }
} qry[maxn];

int a[maxn], p[maxn], ans[maxn];
multiset<int> s[2];

void addR(int);
void subR(int);
void addL(int);
void subL(int);

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, m; cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i], p[i] = p[i - 1] + a[i];
    int _lim = (int)sqrt(n) + 1;
    cin >> m;
    for (int i = 0; i < m; ++i) {
        cin >> qry[i].L >> qry[i].R;
        qry[i].block = qry[i].L / _lim;
        qry[i].id = i;
    }
    sort(qry, qry + m);
    s[0].insert(0); s[1].insert(0);
    for (int i = 0, L = 1, R = 0; i < m; ++i) {
        while (R < qry[i].R) addR(++R);
        while (R > qry[i].R) subR(R--);
        while (L > qry[i].L) addL(--L);
        while (L < qry[i].L) subL(L++);
        ans[qry[i].id] = *s[0].rbegin() - *s[1].begin();
    }
    for (int i = 0; i < m; ++i) cout << ans[i] << '\n';
    return 0;
}

void addR(int x) { s[0].insert(p[x]); }
void subR(int x) { s[0].erase(p[x]);  }
void addL(int x) { s[1].insert(p[x - 1]); }
void subL(int x) { s[1].erase(p[x - 1]); }
