#include <bits/stdc++.h>
using namespace std;

const int maxn = 100 + 10, inf = 1e7 + 10;
string w, q;
int b, d, t[maxn];

bool check(int p) {
    int cur = 0;
    int use = 0;
    for (int i = 0; i < p; ++i) {
        if (t[cur] == -1) return false;
        if (cur + t[cur] >= w.size()) ++use;
        cur = (cur + t[cur]) % w.size();
    }
    return use <= b;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> b >> d >> w >> q;
    for (int c = 0; c < w.size(); ++c) {
        string ns = "";
        for (int j = c; j < w.size(); ++j) ns += w[j];
        for (int j = 0; ns.size() < w.size(); ++j) ns += w[j];
        int ind = 0;
        bool ok = true;
        for (int j = 0; j < q.size(); ++j) {
            while (ind < ns.size() && ns[ind] != q[j]) ++ind;
            if (ind == ns.size()) {
                ok = false;
                break;
            }
            ++ind;
        }
        if (ok) t[c] = ind;
        else t[c] = -1;
    }
    int d = 1, ans = 0; while (d < inf) d <<= 1;
    while (d >>= 1) if (ans + d < inf) if (check(ans + d)) ans += d;
    cout << ans << endl;
    return 0;
}
