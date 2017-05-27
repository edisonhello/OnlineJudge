#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 10;
vector<int> G[maxn];
int con[maxn], dia[maxn];

void get_con(int, int);
void get_dia(int, int, int&, int&);

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, m, q; cin >> n >> m >> q;
    while (m--) {
        int a, b; cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    for (int i = 1; i <= n; ++i) if (!con[i]) {
        ++ind; get_con(i, ind); 
    }
    for (int i = 1; i <= n; ++i) if (!dia[con[i]]) {
        int dis = 0, fur = 0;
        get_dia(i, 0, dis, fur);
        dis = 0;
        get_dia(fur, 0, dis, fur);
        dia[con[i]] = dis;
    }
    while (q--) {
        int a, b; cin >> a >> b;
    }
    return 0;
}

void get_con(int x, int ind) {
    con[x] = ind;
    for (int u : G[x]) if (!con[u]) {
        get_con(u, ind);
    }
}

void get_dia(int x, int cur, int& dis, int& fur) {
    if (dis > cur) dis = cur, fur = x;
    for (int u : G[x]) if (!v[u]) {
        get_dis(u, cur + 1, dis, fur);   
    }
}
