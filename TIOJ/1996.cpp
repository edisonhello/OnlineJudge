#include <bits/stdc++.h>
#include "lib1996.h"
using namespace std;

template <typename T> using MinHeap = priority_queue<T, vector<T>, greater<T>>;
template <typename T> using MaxHeap = priority_queue<T, vector<T>, less<T>>;

const int maxn = 6e6 + 10;
vector<int> *G;
int *ans;
bool *v;;

struct dsu {
    int p[maxn >> 1], sz[maxn >> 1];
    void init() {
        for (int i = 0; i < maxn >> 1; ++i) {
            p[i] = i; sz[i] = 1;
        }
    }
    int find(int x) {
        if (x == p[x]) return x;
        return p[x] = find(p[x]);
    }
    void merge(int x, int y) {
        x = find(x); y = find(y);
        if (x == y) return;
        if (sz[x] > sz[y]) swap(x, y);
        p[x] = y; sz[y] += sz[x];
    }
} dsu;

void init(int n, int m, int a[], int b[], int k[]) {
    dsu.init();
    int now = n, e = 0;
    for (int i = 0; i < m; ++i) {
        if (k[i] == 0) dsu.merge(a[i], b[i]);
        if (k[i] == 2) ++e;
    }
    G = new vector<int> [n + e + 1];
    for (int i = 0; i < m; ++i) {
        if (dsu.find(a[i]) == dsu.find(b[i])) continue;
        if (k[i] == 1) {
            G[dsu.find(a[i])].push_back(dsu.find(b[i]));
            G[dsu.find(b[i])].push_back(dsu.find(a[i]));
        }
        if (k[i] == 2) {
            G[dsu.find(a[i])].push_back(now);
            G[now].push_back(dsu.find(a[i]));
            G[dsu.find(b[i])].push_back(now);
            G[now].push_back(dsu.find(b[i]));
            ++now;
        }
    }
    queue<pair<int, int>> que; que.push(make_pair(0, 0));
    ans = new int [n + e + 1];
    fill(ans, ans + n + e + 1, -1);
    v = new bool [n + e + 1];
    fill(v, v + n + e + 1, false);
    while (que.size()) {
        auto now = que.front(); que.pop();
        now.first = (now.first < n ? dsu.find(now.first) : now.first);
        if (v[now.first]) continue;
        v[now.first] = true;
        ans[now.first] = now.second;
        for (int u : G[now.first]) {
            if (!v[u]) que.push(make_pair(u, now.second + 1));
        }
    }
}

int get_cost(int x) {
    if (ans[dsu.find(x)] == -1) return -1; 
    return ans[dsu.find(x)] * 16;
}
