#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 10;
bool p[maxn], v[maxn];
struct Foo {
    string s;
    int a;
    bool operator<(const Foo& bar) const {
        return a > bar.a;
    }
} f[maxn];

struct cmp {
    bool operator()(const pair<string, int>& a, const pair<string, int>& b) {
        return a.first == b.first ? f[a.second].a > f[b.second].a : a.first < b.first;
    }
};

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, k; cin >> k >> n;
    multiset<pair<string, int>, cmp> ms;
    for (int i = 0; i < k; ++i) {
        cin >> f[i].s >> f[i].a;
        // string t = f[i].s; reverse(t.begin(), t.end());
        // p[i] = (f[i].s == t);
    }
    int ans = 0;
    sort(f, f + k);
    for (int i = 0; i < k; ++i) {
        ms.insert(make_pair(f[i].s, i));
        string t = f[i].s; reverse(t.begin(), t.end());
        p[i] = t == f[i].s;
    }
    f[k].a = 100001;
    for (int i = 0; i < k; ++i) if (!v[i]) {
        string t = f[i].s; reverse(t.begin(), t.end());
        auto it = ms.lower_bound(make_pair(t, k));
        if (it->first == t && !v[it->second] && it->second != i) {
            if (f[it->second].a + f[i].a > 0) {
                ans += f[it->second].a + f[i].a;
                v[i] = true;
                v[it->second] = true;
                ms.erase(ms.find(*it));
                ms.erase(ms.find(make_pair(f[i].s, i)));
            }
        }
    }
    int pal = 0;
    for (int i = 0; i < k; ++i) if (!v[i] && p[i]) {
        if (f[i].a > 0) pal = max(pal, f[i].a);
    }
    cout << ans + pal << endl;
    return 0;
}
