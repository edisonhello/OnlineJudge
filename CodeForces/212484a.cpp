#include <bits/stdc++.h>
using namespace std;

const int maxn = 500000 + 5;
int n, p[maxn], pos[maxn], mem[2][maxn];
set<int> s;

void dp(int);

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> p[i], pos[p[i]] = i;
    memset(mem, -1, sizeof(mem));
    s.insert(0);
    for (int i = 1; i <= n; ++i) s.insert(p[i]), dp(p[i]);
    for (int i = 1; i <= n; ++i) cout << mem[0][i] + mem[1][i] + 1 << '\n';
    return 0;
}

void dp(int i) {
    if (mem[0][i] != -1) return;
    auto it = s.upper_bound(i);
    mem[0][i] = mem[1][i] = 0;
    if (it != s.end()) dp(*it), mem[0][i] = mem[0][*it] + 1;
    it = s.lower_bound(i);
    if (*it == i) --it;
    if (*it) dp(*it), mem[1][i] = mem[1][*it] + 1;
}
