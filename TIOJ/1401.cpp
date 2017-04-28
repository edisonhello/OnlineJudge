#include <bits/stdc++.h>
using namespace std;

const int maxn = 100000 + 5;

int n;
pair<int, int> X[maxn], Y[maxn];

bool solve(pair<int, int>*);

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
     while (cin >> n) {
        for (int i = 0; i < n; ++i) cin >> X[i].first >> X[i].second >> Y[i].first >> Y[i].second;
        if (solve(X) && solve(Y)) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}

bool solve(pair<int, int>* p) {
    sort(p, p + n);
    map<int, int> m;
    for (int i = 1, ind = 0; i <= n; ++i) {
        while (ind < n && p[ind].first <= i) m[p[ind].second]++, ++ind;
        auto it = m.begin();
        if (it->first < i) return false;
        --it->second;
        if (!it->second) m.erase(it);
    }
    return true;
}
