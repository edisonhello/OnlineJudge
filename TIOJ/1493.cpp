#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e6 + 10;
vector<int> G[maxn];
int tin[maxn], tout[maxn], stamp;
bool l[maxn];

struct Node {
    int a, b, c;
    Node(): a(0), b(0), c(0) {}
    Node(int _a, int _b, int _c): a(_a), b(_b), c(_c) {}
    Node operator+(const Node& rhs) const {
        return Node(a + rhs.a, b + rhs.b, c + rhs.c);
    }
    Node& operator+=(const Node& rhs) {
        a += rhs.a; b += rhs.b; c += rhs.c;
        return *this;
    }
    Node operator-(const Node& rhs) const {
        return Node(a - rhs.a, b - rhs.b, c - rhs.c);
    }
};

struct BIT {
    vector<Node> _bit;
    void init(int n) {
        for (int i = 0; i < n; ++i) _bit.push_back(Node());
    }
#define lowbit(x) (x & -x)
    void add(int x, Node v) {
        for (int i = x; i < _bit.size(); i += lowbit(i)) _bit[i] += v;
    }
    Node qry(int x) {
        Node ret = Node();
        for (int i = x; i; i -= lowbit(i)) ret += _bit[i];
        return ret;
    }
#undef lowbit
} bit;

void dfs(int, int);
Node make(int, int);

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    for (int i = 0; i < n - 1; ++i) {
        int a, b; cin >> a >> b;
        G[a].push_back(b); G[b].push_back(a);
    }
    dfs(1, 0);
    bit.init(stamp + 10);
    int m; cin >> m;
    while (m--) {
        string s; cin >> s;
        if (s == "Grow") {
            int w, k, c; cin >> w >> k >> c;
            if (w == 1 && k != 2) cout << "Error" << endl;
            else if (l[w] && k == 2) cout << "Error" << endl;
            else bit.add(tin[w], make(k, c));
        }
        if (s == "Drop") {
            int w, k, c; cin >> w >> k >> c;
            Node q = bit.qry(tin[w]) - bit.qry(tin[w] - 1);
            q += make(k, -c);
            if (w == 1 && k != 2) cout << "Error" << endl;
            else if (l[w] && k == 2) cout << "Error" << endl;
            else if (q.a < 0 || q.b < 0 || q.c < 0) cout << "Error" << endl;
            else bit.add(tin[w], make(k, -c));
        }
        if (s == "Query") {
            int w; cin >> w;
            Node q = bit.qry(tout[w]) - bit.qry(tin[w] - 1);
            cout << q.a << ' ' << q.b << ' ' << q.c << endl;
        }
    }
    return 0;
}

void dfs(int x, int fa) {
    int ch = 0;
    tin[x] = ++stamp;
    for (int u : G[x]) if (u != fa) {
        ++ch; dfs(u, x);
    }
    if (ch == 0) l[x] = true;
    tout[x] = stamp;
}

Node make(int k, int c) {
    if (k == 0) return Node(c, 0, 0);
    if (k == 1) return Node(0, c, 0);
    if (k == 2) return Node(0, 0, c);
} 
